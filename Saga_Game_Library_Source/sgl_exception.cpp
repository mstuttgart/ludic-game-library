#include "sgl_exception.h"

using namespace sgl;

//----------------------------------------------

Exception::Exception(const char* _msg) : msg(_msg) {}

//----------------------------------------------

void Exception::setMensage(const char* msg) {
	this->msg = msg;
}

//----------------------------------------------

const char* Exception::what() const throw() {
	return msg.c_str();
}

//----------------------------------------------