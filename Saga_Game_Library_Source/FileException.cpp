#include "FileException.h"

namespace sgl {
	namespace core {

const char* FileException::what() const throw(){

	return "One SGL Game Library Resource exception ocurred.";
}


} /* namespace core */
} /* namespace sgl */
