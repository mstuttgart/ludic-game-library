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
 * @brief Class to create native Allegro configuration file.
 * 
 * This class allow create a simple text file in the format
 * [section]
 * key = value
 * 
 * Exemple:
 * [Monster]
 * life = 100
 * power = 20
 * agility = 30
 * magic = 0
 * 
 * The user can write and read values how to need.
 * It is also possible to merge two different configuration files.
 * 
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
	 * @brief Default contructor
	 */
	ConfigFileStream();

	/**
	 * @brief 
	 * @param _fileName
	 */
	ConfigFileStream( const String& _fileName );

	/**
	 * @brief Destructor
	 */
	virtual ~ConfigFileStream();

	/**
	 * @brief Load a configuration file.
	 * @param _fileName
	 * @return True if load was succeffully, otherwise False.
	 */
	bool load( const String& _fileName );

	/**
	 * @brief Save a configuration file.
	 * @param _fileName The name to save a configuration file. If
	 * used the same name passed in @ref load() or @ref ConfigFileStream( const String& _fileName )7
	 * methods, the file is overwrite. Otherwise, the new file will be created.
	 * @return True if file is saved, False otherwise.
	 */
	bool save( const String& _fileName );

	/**
	 * @brief Add a new section in configuration file.
	 * 
	 * The new section is representinf for [].
	 * 
	 * Example: addSection("moster") wirte in configuration file
	 * the section [monster].
	 * @param section The name of new section.
	 */
	void addSection( const String& section );

	/**
	 * @brief Add a new comment in configuration file.
	 * 
	 * The comments not be read for read methods.
	 * @param section name of Section where the new comment will be add.
	 * @param comment the new comment.
	 */
	void addComment( const String& section, const String& comment );

	/**
	 * @brief Get the key value in a given section.
	 * @param Section The name of section where key is declared.
	 * @param key The name of key.
	 * @return A string containing a value of given key.
	 */
	const String getValue( const String& section, const String& key ) const;

	/**
	 * @brief Add a value in key of given section.
	 * @param section The name of section that cotaining the key.
	 * @param key The name of key.
	 * @param value The new value will be stored in the key.
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
	 * @brief Merge two configuration files.
	 * 
	 * The string containing the name of the new 
	 * file that will be generated as a result of 
	 * the merger of the two files passed as parameter file.
	 * @param file string containing the name of the new 
	 * file
	 * @param cfg_1 configuration file one
	 * @param cfg_2 configuration file two
	 * @return The pointer to object ConfigFileStream initialized with
	 * the new configuration file generated.
	 */
	static ConfigFileStream* merge(
	    const String& file, ConfigFileStream* cfg_1, ConfigFileStream* cfg_2 );

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
