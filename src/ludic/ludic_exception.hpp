/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is a FREE SOFTWARE released under the BSD License.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include <exception>
#include <string>

typedef std::string String;

namespace Ludic {

/**
 * @file ludic_exception.hpp
 * @author Michell Stuttgart
 * @date 11/11/13
 * @class Exception
 * @brief Classe responsavel por capturar excecoes geadas pela Ludic Game Library.
 *
 * A classe trata as excecoes que podem ocorrer na inicializacao dos
 * componentes da Allegro.
 */
class Exception : public std::exception {

private:

	String msg;

public:

	/**
	 * @brief
	 */
	Exception() {};

	virtual ~Exception() throw(){}

	/**
	 * @brief
	 * @param msg
	 */
	Exception( String _msg );

	/**
	 * @brief
	 * @param msg
	 */
	void setMessage( String msg );

	/**
	* @brief Method responsible for returning a description of the exception.
	* @return String containing the description of the exception.
	*/
	virtual const char* what() const throw();

};

}/* namespace */
