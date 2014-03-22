#include "sgl_exception.h"

using namespace sgl;

//----------------------------------------------

Exception::Exception(String _msg) : msg(_msg) {}

//----------------------------------------------

void Exception::setMensage(String msg) {
	this->msg = msg;
}

//----------------------------------------------

const char* Exception::what() const throw() {
	return msg.c_str();
}

//----------------------------------------------