#include "tmx_layer.hpp"
#include "util.hpp"

#include <cstdint>

using namespace Ludic;
using namespace std;

//////////////////////////////////////////////////////////////

TMXLayer::TMXLayer() :
	name( "" ), width( 0 ), height( 0 ), visible( true ), opacity( 1.0f ) {}

//////////////////////////////////////////////////////////////

TMXLayer::~TMXLayer() {}

//////////////////////////////////////////////////////////////

void TMXLayer::parse( TiXmlNode* node )
{

	// Convertemos o node para element
	TiXmlElement* elem = node->ToElement();

	// Inciando os atributos do tileset
	const char* aux = elem->Attribute( "name" );

	if( aux != nullptr )
		name = aux;

	aux = elem->Attribute( "width");

	if( aux != nullptr )
		width = (int) atoi(aux);

	aux = elem->Attribute( "height" );

	if( aux != nullptr )
		height = (int) atoi(aux);

	// Retorna NULL se nao houver atributo visible
	aux = elem->Attribute( "visible" );

	if( aux != nullptr )
		visible = false;

	// Retorna NULL se nao houver atributo opacity
	aux = elem->Attribute( "opacity" );

	if( aux != nullptr )
		opacity = ( float ) atof( aux );

	//----------------------------------------

	// Lemos as properties do layer
	parseProperty( node );

	//----------------------------------------

	// Agora lemos os valores de data

	// Elemento para ler atributos de data
	elem = node->FirstChildElement( "data" );

	//-------------------------------------------

	// Verificamos se os dados esta codificados com base64
	aux = elem->Attribute( "encoding" );

	// Variavel auxiliar
	String str;

	//---------------------------------------

	// Indicamos o tipo de compressao
	int encoding;

	if( aux != nullptr ) {

		// Recebemos o nome da codificacao
		str = aux;

		// Se for base64, iniciamos a decodificacao
		if( !str.compare( "base64" ) ) {
			encoding = ENCODE_BASE64;
		} else if( !str.compare( "csv" ) ) {
			encoding = ENCODE_CVS;
		}

	}//if
	else {
		encoding = ENCODE_NONE;
	}

	//---------------------------------------

	// Verificamos se os dados forma comprimidos
	aux = elem->Attribute( "compression" );

	// Indicamos o tipo de compressao
	int compress;

	if( aux != nullptr ) {

		str = aux;

		// Verificamo os tipo de compressao
		if( !str.compare( "zlib" ) ) {
			compress = COMPRESSION_ZLIB;
		} 
		else if( !str.compare( "gzip" ) ) {
			compress = COMPRESSION_GZIP;
		}

	}//if
	else {
		compress = COMPRESSION_NONE;
	}

	//---------------------------------------

	switch( encoding ) {

	case ENCODE_BASE64:
		parseBase64( elem->GetText(), compress );
		break;

	case ENCODE_CVS:
		parseCSV( elem->GetText() );
		break;

	case ENCODE_NONE:
		parseXML( node );
		break;

	default:
		cout << "Invalid encoding format!" << endl;

	}//switch

}

//////////////////////////////////////////////////////////////

void TMXLayer::parseProperty( TiXmlNode* root  )
{

	// Ponteiro para primeiro elemento de properties
	TiXmlNode* node;
	TiXmlElement* elem = nullptr;

	// Recebemos o no de properties
	node = root->FirstChild( "properties" );

	// Se o no existir, lemos o primeiro elemento
	if( node != nullptr )
		elem = node->FirstChildElement( "property" );

	while( elem != nullptr ) {

		// Lemos o conteudo do elemento
		const char* aux =  elem->Attribute( "name" );

		// Inserimos no mapa a property e seu valor
		if( aux != nullptr )
			properties[ aux ] = elem->Attribute( "value" );

		// Pegamos o proximos elemento
		elem = elem->NextSiblingElement( "property" );

	}//while

}

//////////////////////////////////////////////////////////////

void TMXLayer::parseBase64( const String& dataStr, int compression  )
{

	String strBase64; 		// Realizamos a decodificacap em base64
	String strDecompress;	// Variavel que recebe a saida descomprimida

	// Decodificamos a string
	Util::decodeBase64( dataStr, strBase64 );

	// Realizamos a descompressao
	switch( compression ) {

	case COMPRESSION_ZLIB:
		Util::decompressZLIB( strBase64, strDecompress );
		break;

	case COMPRESSION_GZIP:
		Util::decompressGZIP( strBase64, strDecompress );
		break;

	case COMPRESSION_NONE:
		strDecompress = strBase64;
		break;

	default:
		break;

	}//switch

	// Representa a estrutura ( gid, posicao do tile no mapa)
	DataInfo info;

	info.gid   = 0;
	info.index = 0;

	// Inserimos os dados no vetor data
	for( unsigned int i = 0; i < strDecompress.size(); i += 4 ) {

		// Variaveis auxiliares. Precisa ser unsigned char, porque as operacoes
		// sao de 8 em 8 bits.
		// Pegamos um conjunt0 de 4 bytes
		std::uint8_t a = strDecompress[i];
		std::uint8_t b = strDecompress[i + 1];
		std::uint8_t c = strDecompress[i + 2];
		std::uint8_t d = strDecompress[i + 3];

		// Realizamos a restauracao do valor antigo
		info.gid = a | b << 8 | c << 16 | d << 24;

		// gid = 0 indica tile vazio.
		// Inserimos no vetor apenas tiles com imagens
		if( info.gid != 0 )
			data.push_back( info ); // Inserimos no vetor

		info.index++;

	}//for

}

//////////////////////////////////////////////////////////////

void TMXLayer::parseXML( TiXmlNode* node )
{

	// Recebemos o primeiro elemento tile
	TiXmlElement* elem = node->FirstChild( "data" )->FirstChildElement( "tile" );

	// Representa a estrutura ( gid, posicao do tile no mapa)
	DataInfo info;

	info.gid   = 0;
	info.index = 0;

	while( elem != nullptr ) {

		// Pegamos o numero do tile
		info.gid = (int) atoi(elem->Attribute( "gid" ));

		if( info.gid != 0 )
			data.push_back( info ); // Adicionamos o valor no vetor data

		// Incrementamos o indice do tile
		info.index++;

		//Proximo elemento
		elem = elem->NextSiblingElement( "tile" );

	}//while
}

//////////////////////////////////////////////////////////////

void TMXLayer::parseCSV( const String& dataStr )
{

	String aux; // Variavel auxiliar que recebera os numeros
	String carac; // Recebe o caracter para analise

	// Representa a estrutura ( gid, posicao do tile no mapa)
	DataInfo info;

	info.gid   = 0;
	info.index = 0;

	// Usado para nao precisarmos chamr size() toda vez
	unsigned int last = dataStr.size() - 1;

	for( unsigned int i = 0; i <= last; i++ ) {

		// Recebemos o caracter
		carac = dataStr[i];

		// Verificamos se o caracter e uma virgula
		if( !carac.compare( "," ) ) {

			// Convertemos aux para inteiro
			info.gid = (int) atoi(aux.c_str());

			if( info.gid != 0 )
				data.push_back( info ); // Inserimos no vetor

			info.index++;

			// Limpamos aux
			aux.clear();

		} else {
			aux += dataStr.at( i ); // Concatenamos o char atual em aux
		}

	}//for

	// Convertemos ultimo valor de aux para inteiro
	info.gid = (int) atoi( aux.c_str() );

	if( info.gid != 0 )
		data.push_back( info ); // Inserimos no vetor

}

//////////////////////////////////////////////////////////////

const std::vector<TMXLayer::DataInfo>& TMXLayer::getData() const {
	return data;
}

//////////////////////////////////////////////////////////////

const std::map<String, String>& TMXLayer::getProperties() const {
	return properties;
}

//////////////////////////////////////////////////////////////

int TMXLayer::getHeigth() const {
	return height;
}

//////////////////////////////////////////////////////////////

const String& TMXLayer::getName() const {
	return name;
}

//////////////////////////////////////////////////////////////

bool TMXLayer::isVisible() const {
	return visible;
}

//////////////////////////////////////////////////////////////

int TMXLayer::getWidth() const {
	return width;
}

//////////////////////////////////////////////////////////////
