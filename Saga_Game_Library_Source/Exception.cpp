#include "Exception.h"

namespace sgl {
	
const char* Exception::what() const throw() {

	return "One SGL Game Library exception ocurred.";
}

} /* namespace sgl */
