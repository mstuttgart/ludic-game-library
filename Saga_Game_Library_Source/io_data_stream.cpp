#include "io_data_stream.h"

using namespace sgl::core;

//--------------------------------------------------------------

IODataStream::IODataStream() :
	fileName( "file.cfg" ), config( al_create_config() ),
	itSection( nullptr ), itEntry( nullptr ) {}

//--------------------------------------------------------------

IODataStream::IODataStream( ALLEGRO_CONFIG* cfg, const String& _fileName  ) :
	fileName( _fileName ), config( cfg ) {}

//--------------------------------------------------------------

IODataStream::IODataStream( const String& _fileName ) : fileName( _fileName ) {

	// Carregamos o arquivo
	load( _fileName );
	
}

//--------------------------------------------------------------

bool IODataStream::load( const String& _fileName ) {

	// Verificamos se o filename nao e NULL
	if( _fileName.empty() )
		throw sgl::Exception( "Invalid file name " + _fileName );

	// Carregamos o arquivo de configuracao
	ALLEGRO_CONFIG* cfg = al_load_config_file( _fileName.c_str() );

	// Verificamos se o arquivo foi carregado de maneira correta
	if( !cfg )
		throw sgl::Exception(
		    "Error: File "+ _fileName +" does not exist!" );

	// Atualizamos os atributos da classe
	fileName.clear();
	fileName = _fileName;
	config   = cfg;

	// Mensagem indicando sucesso
	std::cout << "File " << _fileName << " loaded successfully!" << std::endl;

	return true;

}

//--------------------------------------------------------------

IODataStream::~IODataStream() {
	al_destroy_config( config );
}

//--------------------------------------------------------------

void IODataStream::addSection( const String& section ) {
	al_add_config_section( config, section.c_str() );
}

//--------------------------------------------------------------

void IODataStream::addComment( const String& section, const String& comment ) {
	al_add_config_comment( config, section.c_str(), comment.c_str() );
}

//--------------------------------------------------------------

const String& IODataStream::getFirstKey( const String& section ) const {
	return al_get_first_config_entry( config, section.c_str(), itEntry );
}

//--------------------------------------------------------------

const String& IODataStream::getFirstSection() const {
	return al_get_first_config_section( config, itSection );
}

//--------------------------------------------------------------

const String& IODataStream::getNextSection() const {
	return al_get_next_config_section( itSection );
}

//--------------------------------------------------------------

const String& IODataStream::getNextKey() const {
	return al_get_next_config_entry( itEntry );
}

//--------------------------------------------------------------

void IODataStream::addValue(
    const String& section, const String& key, const String& value ) {
	al_set_config_value( config, section.c_str(), key.c_str(), value.c_str() );
}

//--------------------------------------------------------------

const String& IODataStream::getValue( const String& section, const String& key ) const {
	return al_get_config_value( config, section.c_str(), key.c_str() );
}

//--------------------------------------------------------------

IODataStream* IODataStream::merge(
    const String& file, IODataStream* cfg_1, IODataStream* cfg_2 ) {

	// Realizamos o merge entre os dois arquivos
	ALLEGRO_CONFIG* ncfg = al_merge_config( *cfg_1, *cfg_2 );

	// Retornamos o novo objetod ou null, em caso de erro
	return ncfg ? ( new IODataStream( ncfg, file ) ) : nullptr;

}

//--------------------------------------------------------------

void IODataStream::mergeInto( IODataStream* add ) {
	al_merge_config_into( config, *add );
}

//--------------------------------------------------------------

bool IODataStream::save( const String& _fileName ) {
	return al_save_config_file( _fileName.c_str(), config );
}

//--------------------------------------------------------------

IODataStream::operator ALLEGRO_CONFIG*() const {
	return config;
}

//--------------------------------------------------------------
