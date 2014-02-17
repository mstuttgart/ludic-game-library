#include "tmx_base.h"
#include <vector>

namespace sgl {
namespace image {

/**
 * @file layer.h
 * @author Michell Stuttgart
 * @date 02/16/14 
 * @class Layer
 * @brief 
 */
class Layer : public TmxBase {

private:

	const char* name;
	double opacity;
	bool visible;
	std::vector<int> data;

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
	 * @return
	 */
	virtual void parse( TiXmlNode* node );

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

};

}
} /* namespace */
