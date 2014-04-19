#include "tmx_layer.h"
#include "util.h"

using namespace sgl::image;
using namespace sgl;
using namespace std;

//-----------------------------------------------

TMXLayer::TMXLayer() :
	name( "" ), width( 0 ), heigth( 0 ), visible( true ), opacity( 1.0f ) {}

//-----------------------------------------------

TMXLayer::~TMXLayer() {}

//-----------------------------------------------

void TMXLayer::parse( TiXmlNode* node ) {

	// Convertemos o node para element
	TiXmlElement* elem = node->ToElement();

	// Inciando os atributos do tileset
	const char* aux = elem->Attribute( "name" );

	if( aux )
		name = aux;

	// Coletamos as dimensoes do layer
	elem->Attribute( "width", &width   );
	elem->Attribute( "heigth", &heigth );

	// Retorna NULL se nao houver atributo visible
	aux = elem->Attribute( "visible" );

	if( aux )
		visible = static_cast<bool> ( aux );

	// Retorna NULL se nao houver atributo opacity
	aux = elem->Attribute( "opacity" );

	if( aux )
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

	// Indicamos o tipo de compressao
	int encoding = ENCODE_NONE;

	if( aux ) {

		// Recebemos o nome da codificacao
		str = aux;

		// Se for base64, iniciamos a decodificacao
		if( !str.compare( "base64" ) ) {
			encoding = ENCODE_BASE64;
		}
		else if( !str.compare( "csv" ) ) {
			encoding = ENCODE_CVS;
		}

	}//if

	// Verificamos se os dados forma comprimidos
	aux = elem->Attribute( "compression" );

	// Indicamos o tipo de compressao
	int compress = COMPRESSION_NONE;

	if( aux ) {

		str = aux;

		// Verificamo os tipo de compressao
		if( !str.compare( "zlib" ) ) {
			compress = COMPRESSION_ZLIB;
		}
		else if( !str.compare( "gzip" ) ) {
			compress = COMPRESSION_GZIP;
		}

	}//if

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

//-----------------------------------------------

void TMXLayer::parseProperty( TiXmlNode* root  ) {

	// Ponteiro para primeiro elemento de properties
	TiXmlNode* node    = nullptr;
	TiXmlElement* elem = nullptr;

	// Recebemos o no de properties
	node = root->FirstChild( "properties" );

	// Se o no existir, lemos o primeiro elemento
	if( node )
		elem = node->FirstChildElement( "property" );

	// variavel auxiliar
	const char* aux = nullptr;

	while( elem ) {

		// Lemos o conteudo do elemento
		aux =  elem->Attribute( "name" );

		// Inserimos no mapa a property e seu valor
		if( aux )
			properties[ aux ] = elem->Attribute( "value" );

		// Pegamos o proximos elemento
		elem = elem->NextSiblingElement( "property" );

	}//while

}

//--------------------------------------------------------

void TMXLayer::parseBase64( const String& dataStr, int compression  ) {

	// Realizamos a decodificacap em base64
	String strBase64;

	// Decodificamos a string
	Util::decodeBase64( dataStr, strBase64 );

	// Variavel que recebe a saida descomprimida
	String strDecompress;

	switch( compression ) {

		case COMPRESSION_ZLIB:
			Util::decompressZLIB( strBase64, strDecompress );
			break;

		case COMPRESSION_GZIP:
			Util::decompressGZIP( strBase64, strDecompress );
			break;

		case COMPRESSION_NONE:
			strDecompress = strBase64;

	}//switch

	// Variaveis auxiliares
	int a, b, c, d;

	DataInfo info;

	info.gid   = 0;
	info.index = 0;

	// Inserimos os dados no vetor data
	for( unsigned int i = 0; i < strDecompress.size(); i += 4 ) {

		// Pegamos um conjunti de 4 bytes
		a = strDecompress[i];
		b = strDecompress[i + 1];
		c = strDecompress[i + 2];
		d = strDecompress[i + 3];

		// Realizamos a restauracao do valor antigo
		info.gid = a | b << 8 | c << 16 | d << 24;

		if( info.gid != 0 )
			data.push_back( info ); // Inserimos no vetor

		info.index++;

	}//for

}

//--------------------------------------------------------

void TMXLayer::parseXML( TiXmlNode* node ) {

	// Recebemos o primeiro elemento tile
	TiXmlElement* elem = node->FirstChild( "data" )->FirstChildElement( "tile" );

	DataInfo info;

	info.gid   = 0;
	info.index = 0;

	while( elem ) {

		// Pegamos o numero do tile
		elem->Attribute( "gid", &info.gid );

		if( info.gid != 0 )
			data.push_back( info ); // Adicionamos o valor no vetor data

		// Incrementamos o indice do tile
		info.index++;

		//Proximo elemento
		elem = elem->NextSiblingElement( "tile" );

	}//while
}

//--------------------------------------------------------

void TMXLayer::parseCSV( const String& dataStr ) {

	String aux; // Variavel auxiliar que recebera os numeros
	String carac; // Recebe o caracter para analise

	DataInfo info;

	info.gid   = 0;
	info.index = 0;

	for( unsigned int i = 0; i < dataStr.size(); i++ ) {

		// Recebemos o caracter
		carac = dataStr[i];

		// Verificamos se o caracter e uma virgula
		if( !carac.compare( "," ) ) {

			// Convertemos aux para inteiro
			info.gid = std::stoi( aux );

			if( info.gid != 0 )
				data.push_back( info ); // Inserimos no vetor

			info.index++;

			// Limpamos aux
			aux.clear();
		}
		else {
			aux += dataStr.at( i ); // Concatenamos o char atual em aux
		}

	}//for

}

//--------------------------------------------------------
