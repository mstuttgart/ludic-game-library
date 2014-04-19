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

	// Verificamos se os dados forma comprimidos
	aux = elem->Attribute( "compression" );

	// Indicamos o tipo de compressao
	int compress = COMPRESSION_NONE;

	if( aux ) {

		// Variavel auxiliar
		String str = aux;

		// Verificamo se codificacao e ZLIB
		if( !str.compare( "zlib" ) ) {

			compress = COMPRESSION_ZLIB;
		}
		else if( !str.compare( "gzip" ) ) {

			compress = COMPRESSION_GZIP;
		}

	}//if

	// Verificamos se os dados esta codificados com base64
	aux = elem->Attribute( "encoding" );

	if( aux ) {

		// Recebemos o nome da codificacao
		String str = aux;

		// Se for base64, iniciamos a decodificacao
		if( !str.compare( "base64" ) ) {
			parseBase64( elem->GetText(), compress );
		}
		else {
			cout << "Sorry, SGL only supports Base64 decoding!" << endl;
		}
	}
	else {

		// Realizamos o parse comum para os dados
		parseXML( node );
	}

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

	// Variaveis auxiliares
	int a, b, c, d, gid;

	// Variavel que recebe a saida descomprimida
	String strDecompress;

	// Se estiver comrpimido com ZLIB
	if( compression == COMPRESSION_ZLIB ) {

		// Realizamos a descompressao. out recebe uma string descomprimida
		Util::decompressZLIB( strBase64, strDecompress );

	}
	else if( compression == COMPRESSION_GZIP ) {

		// Realizamos a descompressao
		Util::decompressGZIP( strBase64, strDecompress );

	}
	else{
		strDecompress = strBase64;
	}

	// Inserimos os dados no vetor data
	for( unsigned int i = 0; i < strDecompress.size(); i += 4 ) {

		// Pegamos um conjunti de 4 bytes
		a = strDecompress[i];
		b = strDecompress[i + 1];
		c = strDecompress[i + 2];
		d = strDecompress[i + 3];

		// Realizamos a restauracao do valor antigo
		gid = a | b << 8 | c << 16 | d << 24;

		// Inserimos no vetor
		data.push_back( gid );

	}//for
}

//--------------------------------------------------------

void TMXLayer::parseXML( TiXmlNode* node ) {

	// Recebemos o primeiro elemento tile
	TiXmlElement* elem = node->FirstChild( "data" )->FirstChildElement( "tile" );

	int gid = 0;

	while( elem ) {

		// Pegamos o numero do tile
		elem->Attribute( "gid", &gid );

		// Adicionamos o valor no vetor data
		data.push_back( gid );

		//Proximo elemento
		elem = elem->NextSiblingElement( "tile" );

	}//while
}

//--------------------------------------------------------
