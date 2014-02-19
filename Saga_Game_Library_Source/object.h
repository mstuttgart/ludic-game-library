#pragma once

#include "tile_set.h"
#include <vector>

namespace sgl {
namespace image {

class Object : public TmxBase {

private:

	const char* name;
	const char* type;
	int x;
	int y;
	int width;
	int height;
	double rotation;
	int gid;
	bool visible;

	/**
	* @brief
	* @param node
	*/
	virtual void parse( TiXmlNode* node );

public:

	/**
	 * @brief
	 */
	Object();

	/**
	 * @brief
	 * @return
	 */
	virtual ~Object() {};


	/**
	 * @brief 
	 * @param node
	 * @param tileset
	 */
	void parse( TiXmlNode* node, std::vector<TileSet*>& tileset );

	/**
	 * @brief
	 * @return
	 */
	const char* getName();

	/**
	 * @brief
	 * @return
	 */
	const char* getType();

	/**
	 * @brief
	 * @return
	 */
	int getX() const;

	/**
	 * @brief
	 * @return
	 */
	int getY() const;

	/**
	 * @brief
	 * @return
	 */
	int getWidth() const;

	/**
	 * @brief
	 * @return
	 */
	int getHeight() const;

	/**
	 * @brief
	 * @return
	 */
	double getRotation() const;

	/**
	 * @brief
	 * @return
	 */
	int getGid() const;

	/**
	 * @brief
	 * @return
	 */
	bool isVisible() const;

};

}
} /* namespace */
