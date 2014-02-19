#include "tile_set.h"
#include <vector>
#include "tile.h"
#include "surface.h"

namespace sgl {
namespace image {


/**
 * @file layer.h
 * @author Michell Stuttgart
 * @date 02/16/14
 * @class Layer
 * @brief
 */
class Layer : public TmxBase{

private:

	const char* name;
	double opacity;
	bool visible;
	std::vector<Tile*> tiles;

	/**
	* @brief
	* @return
	*/
	virtual void parse( TiXmlNode* node );

public:

	/**
	 * @brief
	 */
	Layer();

	/**
	 * @brief
	 */
	virtual ~Layer() {};


	/**
	 * @brief
	 * @param node
	 * @param tileset
	 * @param width
	 * @param blockw
	 * @param blockh
	 */
	void parse( TiXmlNode* node, std::vector<TileSet*>& tileset, int width, int blockw, int blockh );

	/**
	 * @brief
	 * @param opacity
	 */
	void setOpacity(double opacity);

	/**
	 * @brief
	 * @param visible
	 */
	void setVisible(bool visible);

	/**
	 * @brief
	 * @return
	 */
	const char* getName();

	/**
	 * @brief
	 * @return
	 */
	double getOpacity() const;

	/**
	 * @brief
	 * @return
	 */
	bool isVisible() const;

	/**
	 * @brief
	 * @return
	 */
	int size() const;

	/**
	 * @brief 
	 */
	virtual void draw();

};

}
} /* namespace */
