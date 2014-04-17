#include "config_file_stream.h"

using namespace std;
using namespace sgl::core;

//--------------------------------------------------------------

ConfigFileStream::ConfigFileStream() :
	fileName( "file.cfg" ), config( al_create_config() ),
	itSection( nullptr ), itEntry( nullptr ) {}

//--------------------------------------------------------------

ConfigFileStream::ConfigFileStream( ALLEGRO_CONFIG* cfg, const String& _fileName  ) :
	fileName( _fileName ), config( cfg ) {}

//--------------------------------------------------------------

ConfigFileStream::ConfigFileStream( const String& _fileName ) : fileName( _fileName )
{
	// Carregamos o arquivo
	if ( !load( _fileName ) )
		throw sgl::Exception( "Error to load file " + _fileName );
}

//--------------------------------------------------------------

bool ConfigFileStream::load( const String& _fileName )
{

	// Verificamos se o filename nao e NULL
	if( _fileName.empty() ) {
		cout << "Invalid file name " + _fileName << endl;
		return false;
	}

	// Carregamos o arquivo de configuracao
	ALLEGRO_CONFIG* cfg = al_load_config_file( _fileName.c_str() );

	// Verificamos se o arquivo foi carregado de maneira correta
	if( !cfg ) {
		cout << "Error: File " + _fileName + " does not exist!" << endl;
		return false;
	}

	// Atualizamos os atributos da classe
	fileName.clear();
	fileName = _fileName;
	config   = cfg;

	// Mensagem indicando sucesso
	std::cout << "File " << _fileName << " loaded successfully!" << std::endl;

	return true;

}

//--------------------------------------------------------------

ConfigFileStream::~ConfigFileStream()
{
	al_destroy_config( config );
}

//--------------------------------------------------------------

void ConfigFileStream::addSection( const String& section )
{
	al_add_config_section( config, section.c_str() );
}

//--------------------------------------------------------------

void ConfigFileStream::addComment( const String& section, const String& comment )
{
	al_add_config_comment( config, section.c_str(), comment.c_str() );
}

//--------------------------------------------------------------

const String ConfigFileStream::getFirstKey( const String& section ) const try
{
	return al_get_first_config_entry( config, section.c_str(), itEntry );
}
catch( exception& x )
{
	return "";
}

//--------------------------------------------------------------

const String ConfigFileStream::getFirstSection() const try
{

	return al_get_first_config_section( config, itSection );
}
catch( exception& x )
{
	return "";
}

//--------------------------------------------------------------

const String ConfigFileStream::getNextSection() const try
{
	return al_get_next_config_section( itSection );
}
catch( exception& x )
{
	return "";
}

//--------------------------------------------------------------

const String ConfigFileStream::getNextKey() const try
{
	return al_get_next_config_entry( itEntry );
}
catch( exception& x )
{
	return "";
}

//--------------------------------------------------------------

void ConfigFileStream::addValue(
    const String& section, const String& key, const String& value )
{
	al_set_config_value( config, section.c_str(), key.c_str(), value.c_str() );
}

//--------------------------------------------------------------

const String ConfigFileStream::getValue( const String& section, const String& key ) const try
{
	return al_get_config_value( config, section.c_str(), key.c_str() );
}
catch( exception& x )
{
	return "";
}

//--------------------------------------------------------------

ConfigFileStream* ConfigFileStream::merge(
    const String& file, ConfigFileStream* cfg_1, ConfigFileStream* cfg_2 )
{

	// Realizamos o merge entre os dois arquivos
	ALLEGRO_CONFIG* ncfg = al_merge_config( *cfg_1, *cfg_2 );

	// Retornamos o novo objetod ou null, em caso de erro
	return ncfg ? ( new ConfigFileStream( ncfg, file ) ) : nullptr;

}

//--------------------------------------------------------------

void ConfigFileStream::mergeInto( ConfigFileStream* add )
{
	al_merge_config_into( config, *add );
}

//--------------------------------------------------------------

bool ConfigFileStream::save( const String& _fileName )
{
	return al_save_config_file( _fileName.c_str(), config );
}

//--------------------------------------------------------------

ConfigFileStream::operator ALLEGRO_CONFIG*() const
{
	return config;
}

//--------------------------------------------------------------
