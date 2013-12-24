#include "IOException.h"

namespace sgl {
	namespace core {

const char* IOException::what() const throw(){

	return "One SGL Game Library IO exception ocurred.";
}


} /* namespace core */
} /* namespace sgl */
