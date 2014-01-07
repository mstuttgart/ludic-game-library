#include "ResourceException.h"

namespace sgl {

const char* ResourceException::what() const throw(){

	return "One SGL Game Library Resource exception ocurred.";
}

} /* namespace sgl */
