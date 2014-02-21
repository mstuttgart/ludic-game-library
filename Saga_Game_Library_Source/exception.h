#pragma once

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
class Exception {

public:

	/**
	* @brief Excecoes disparadas por SGL_Exception.
	* @enum EXCEPTION
	*/
	enum EXCEPTION {
	    INIT_ALLEGRO,     /**< Falha ao inicializar a ALLEGRO 5. */
	    INIT_IMAGE,       /**< Falha ao inicializar a ALLEGRO_IMAGE. */
	    INIT_TTF,         /**< Falha ao inicializar a ALLEGRO_TTF. */
	    INIT_AUDIO,       /**< Falha ao inicializar a ALLEGRO_AUDIO. */
	    INIT_PRIMITIVES,  /**< Falha ao inicializar a ALLEGRO_PRIMITIVES. */
	    INSTALL_KEYBOARD, /**< Falha ao inicializar o ALLEGRO_KEYBOARD. */
	    INSTALL_MOUSE,    /**< Falha ao inicializar o ALLEGRO_MOUSE. */
	    CREATE_DISPLAY,	  /**< Falha ao inicializar ALLEGRO_DISPLAY. */
	    LOAD_BITMAP,	  /**< Falha ao criar ALLEGRO_BITMAP. */
		LOAD_TILEMAP,
		LOAD_FONT,
	    INVALID_PATH,	  /**< Caminho especificado invalido. */
	    count /**< Indica a quantidade de elementos de EXCEPTION. */
	};

	/**
	 * @brief Retorna um vetor de caracteres contendo a mensagem de erro.
	 * @return um vetor de caracteres contendo a mensagem de erro.
	 */
	static const char* getError( EXCEPTION& exIndex );

};

}/* namespace */
