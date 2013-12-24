/**
 * @file HardwareException.h
 * @author Michell Stuttgart
 * @date 17/12/2013
 */

#ifndef HARDWAREEXCEPTION_H_
#define HARDWAREEXCEPTION_H_

#include "Exception.h"

namespace sgl {
	namespace core {

/**
 * @class HardwareException
 * @brief Base class responsible for catching exceptions generated by fail SGL' Hardware events.
 *
 * The class handles exceptions caused by fail in initialization of Allegro' hardware support.
 *
 */
class HardwareException: public Exception {

public:

	/**
	 * @brief Method responsible for returning a description of the exception.
	 * @return String containing the description of the exception.
	 */
	virtual const char* what() const throw();

};

} /* namespace core */
} /* namespace sgl */

#endif /* HARDWAREEXCEPTION_H_ */
