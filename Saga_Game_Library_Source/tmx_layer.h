#pragma once

#include "sgl.h"
#include "tinyxml/tinyxml.h"

#include <vector>
#include <map>

#define COMPRESSION_ZLIB	0
#define COMPRESSION_GZIP	1
#define COMPRESSION_NONE	2

namespace sgl {
namespace image {

/**
 * @class TMXLayer
 * @author Michell Stuttgart
 * @date 04/14/14
 * @file tmx_layer.h
 * @brief 
 */
class TMXLayer {

private:

	String name;
	int width;
	int heigth;
	bool visible;
	float opacity;
	std::vector<int> data;
	
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
	inline const std::vector<int>& getData() const;
	
	/**
	 * @brief
	 * @return
	 */
	inline const std::map<String, String>& getProperties() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	inline int getWidth() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	inline int getHeigth() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	inline const String& getName() const;
	
	/**
	 * @brief 
	 * @return 
	 */
	inline bool isVisible() const;

};

//------------------------------------------------------

const std::vector<int>& TMXLayer::getData() const {
	return data;
}

//------------------------------------------------

const std::map<String, String>& TMXLayer::getProperties() const {
	return properties;
}

//------------------------------------------------------

int TMXLayer::getHeigth() const {
	return heigth;
}

//------------------------------------------------------

const String& TMXLayer::getName() const {
	return name;
}

//------------------------------------------------------

bool TMXLayer::isVisible() const {
	return visible;
}

//------------------------------------------------------

int TMXLayer::getWidth() const {
	return width;
}

//------------------------------------------------------

}
} /* namespace */
