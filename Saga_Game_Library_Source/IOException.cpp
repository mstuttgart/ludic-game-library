#include "IOException.h"

namespace sgl {

const char* IOException::what() const throw(){

	return "One SGL Game Library IO exception ocurred.";
}

} /* namespace sgl */
