/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is a FREE SOFTWARE released under the BSD License.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "ludic.hpp"

namespace Ludic {

/**
 * @file config_file_stream.hpp
 * @author Michell Stuttgart
 * @date 04/06/14
 * @class ConfigFileStream
 * @brief
 */
class ConfigFileStream {

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
	ConfigFileStream( ALLEGRO_CONFIG* cfg, const String& _fileName );

public:

	/**
	 * @brief
	 */
	ConfigFileStream();

	/**
	 * @brief
	 * @param _fileName
	 */
	ConfigFileStream( const String& _fileName );

	/**
	 * @brief
	 */
	virtual ~ConfigFileStream();

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
	const String getValue( const String& section, const String& key ) const;

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
	const String getFirstSection() const;

	/**
	 * @brief
	 * @return
	 */
	const String getNextSection() const;

	/**
	 * @brief
	 * @param section
	 * @return
	 */
	const String getFirstKey( const String& section ) const;

	/**
	 * @brief
	 * @return
	 */
	const String getNextKey() const;

	/**
	 * @brief
	 * @param cfg_1
	 * @param cfg_2
	 * @return
	 */
	static ConfigFileStream* merge(
	    const String&, ConfigFileStream* cfg_1, ConfigFileStream* cfg_2 );

	/**
	 * @brief
	 * @param add
	 */
	void mergeInto( ConfigFileStream* add );

	/**
	 * @brief
	 * @return
	 */
	operator ALLEGRO_CONFIG*() const;

};

} /* namespace */
