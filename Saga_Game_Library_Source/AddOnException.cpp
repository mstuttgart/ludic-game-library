#include "AddOnException.h"

namespace sgl {

	const char* AddOnException::what() const throw(){
		return "One Saga Game Library Addon exception occurred.";
	}

} /* namespace sgl */
