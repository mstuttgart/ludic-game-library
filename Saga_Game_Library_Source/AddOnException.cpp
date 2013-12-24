#include "AddOnException.h"

namespace sgl {
	namespace core {

	const char* AddOnException::what() const throw(){
		return "One Saga Game Library Addon exception occurred.";
	}

} /* namespace core */
} /* namespace sgl */
