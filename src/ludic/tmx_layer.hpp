/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is FREE SOFTWARE released under the BSD License.                //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "sgl.hpp"
#include "../tinyxml/tinyxml.h"

#include <vector>
#include <map>

#define COMPRESSION_ZLIB	0
#define COMPRESSION_GZIP	1
#define COMPRESSION_NONE	2
#define ENCODE_BASE64 		3
#define ENCODE_CVS			4
#define ENCODE_NONE			5

namespace Ludic {

/**
* @file tmx_layer.h
* @author Michell Stuttgart
* @date 04/14/14
* @class TMXLayer
* @brief
*/
class TMXLayer {

public:

	struct DataInfo {
		unsigned int gid;
		unsigned int index;
	};

private:

	String name;
	int width;
	int height;
	bool visible;
	float opacity;
	std::vector<DataInfo> data;
	std::map< String, String > properties;

private:

	/**
	* @brief
	*/
	void parseProperty( TiXmlNode* root );

	/**
	* @brief
	* @param node
	*/
	void parseXML( TiXmlNode* node );

	/**
	* @brief
	* @param dataStr
	* @param compression
	*/
	void parseBase64( const String& dataStr, int compression );

	/**
	* @brief
	* @param dataStr
	*/
	void parseCSV( const String& dataStr );

public:

	/**
	* @brief
	*/
	TMXLayer();

	/**
	* @brief
	*/
	virtual ~TMXLayer();

	/**
	* @brief
	* @param node
	*/
	void parse( TiXmlNode* node );

	/**
	* @brief
	* @return
	*/
	const std::vector<DataInfo>& getData() const;

	/**
	* @brief
	* @return
	*/
	const std::map<String, String>& getProperties() const;

	/**
	* @brief
	* @return
	*/
	int getWidth() const;

	/**
	* @brief
	* @return
	*/
	int getHeigth() const;

	/**
	* @brief
	* @return
	*/
	const String& getName() const;

	/**
	* @brief
	* @return
	*/
	bool isVisible() const;

};

} /* namespace */
