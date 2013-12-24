#include "ResourceException.h"

namespace sgl {
	namespace core {

const char* ResourceException::what() const throw(){

	return "One SGL Game Library Resource exception ocurred.";
}


} /* namespace core */
} /* namespace sgl */
