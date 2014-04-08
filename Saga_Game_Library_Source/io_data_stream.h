#pragma once

#include "sgl.h"

namespace sgl {
namespace core {

/**
 * @file io_data_stream.h
 * @author Michell Stuttgart
 * @date 04/06/14
 * @class IODataStream
 * @brief
 */
class IODataStream {

private:

	String fileName;
	ALLEGRO_CONFIG* config;
	ALLEGRO_CONFIG_SECTION** itSection;
	ALLEGRO_CONFIG_ENTRY** itEntry;

private:

	/**
	 * @brief
	 * @param cfg
	 * @param _fileName
	 */
	IODataStream( ALLEGRO_CONFIG* cfg, const String& _fileName );

public:

	/**
	 * @brief
	 */
	IODataStream();

	/**
	 * @brief
	 * @param _fileName
	 */
	IODataStream( const String& _fileName );

	/**
	 * @brief
	 */
	virtual ~IODataStream();

	/**
	 * @brief
	 * @param _fileName
	 * @return
	 */
	bool load( const String& _fileName );

	/**
	 * @brief
	 * @param _fileName
	 * @return
	 */
	bool save( const String& _fileName );

	/**
	 * @brief
	 * @param section
	 */
	void addSection( const String& section );

	/**
	 * @brief
	 * @param section
	 * @param comment
	 */
	void addComment( const String& section, const String& comment );

	/**
	 * @brief
	 * @param section
	 * @param key
	 * @return
	 */
	const char* getValue( const String& section, const String& key ) const;

	/**
	 * @brief
	 * @param section
	 * @param key
	 * @param value
	 */
	void addValue(
	    const String& section, const String& key, const String& value );

	/**
	 * @brief
	 * @return
	 */
	char const* getFirstSection() const;

	/**
	 * @brief
	 * @return
	 */
	char const* getNextSection() const;

	/**
	 * @brief
	 * @param section
	 * @return
	 */
	char const* getFirstKey( const String& section ) const;

	/**
	 * @brief
	 * @return
	 */
	char const* getNextKey() const;

	/**
	 * @brief
	 * @param cfg_1
	 * @param cfg_2
	 * @return
	 */
	static IODataStream* merge(
	    const String&, IODataStream* cfg_1, IODataStream* cfg_2 );

	/**
	 * @brief
	 * @param add
	 */
	void mergeInto( IODataStream* add );

	/**
	 * @brief
	 */
	operator ALLEGRO_CONFIG*() const;

};

}
} /* namespace */
