#pragma once

#include <exception>
#include <string>

namespace sgl {

/**
 * @file Exception.h
 * @author Michell Stuttgart
 * @date Created on 11 de Setembro de 2013, 00:17 *
 * @class Exception
 * @brief Classe responsavel por capturar excecoes geadas pela SGL.
 *
 * A classe trata as excecoes que podem ocorrer na inicializacao dos
 * componetes da Allegro.
 */
class Exception : public std::exception {

private:

	std::string msg;

public:

	/**
	 * @brief 
	 * @return 
	 */
	Exception() {};
	
	virtual ~Exception() throw(){}

	/**
	 * @brief 
	 * @param msg
	 */
	Exception( const char* _msg );

	/**
	 * @brief 
	 * @param msg
	 */
	void setMensage( const char* msg);

	/**
	* @brief Method responsible for returning a description of the exception.
	* @return String containing the description of the exception.
	*/
	virtual const char* what() const throw();

};

}/* namespace */
