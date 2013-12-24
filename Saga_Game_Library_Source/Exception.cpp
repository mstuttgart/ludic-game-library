#include "Exception.h"

namespace sgl{
	namespace core {

const char* Exception::what() const throw(){

	return "One SGL Game Library exception ocurred.";
}

} /* namespace core */
} /* namespace sgl */
