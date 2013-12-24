#include "HardwareException.h"

namespace sgl {
	namespace core {

const char* HardwareException::what() const throw(){

	return "One SGL Game Library Hardware exception ocurred.";
}


} /* namespace core */
} /* namespace sgl */
