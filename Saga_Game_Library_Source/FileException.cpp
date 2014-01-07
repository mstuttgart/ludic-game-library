#include "FileException.h"

namespace sgl {

const char* FileException::what() const throw(){

	return "One SGL Game Library Resource exception ocurred.";
}

} /* namespace sgl */
