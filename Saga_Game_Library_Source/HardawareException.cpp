#include "HardwareException.h"

namespace sgl {

const char* HardwareException::what() const throw(){

	return "One SGL Game Library Hardware exception ocurred.";
}

} /* namespace sgl */
