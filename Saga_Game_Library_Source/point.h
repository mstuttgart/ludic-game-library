#pragma once

namespace sgl {

/**
 * @file point.h
 * @author o nome de quem implementou/idealizou a classe
 * @date 01/24/14
 * @class Point
 * @brief descricao da classe
 */
class Point {

protected:

	int x, y; /**< Descricao das variaveis */

public:

	/**
	 * @brief Descricao breve do metodo
	 * Aqui tem que te um espaco de 1 linha ou mais, se for usar descricao detalhada
	 * 
	 * Descricao detalhada do metodo
	 * 
	 * @return o que o metodo retorna?
	 */
	int getX() const;


	/**
	 * @brief
	 * @return
	 */
	int getY() const;

public:

	/**
	 * @brief 
	 */
	Point(); // Eu mudei aqui
	
	
	/**
	 * @brief 
	 * @param x aqui vai a descricao do parametro x
	 * @param y aqui vai a descricao do parametro y
	 */
	Point(int x, int y);
	
	/**
	 * @brief 
	 * @return 
	 */
	virtual ~Point(){};
	

	/**
	 * @brief 
	 * @param value
	 */
	void setX(int value);
	
	/**
	 * @brief 
	 * @param value
	 */
	void setY(int value);


	/**
	 * @brief 
	 * @param p
	 * @return 
	 */
	int distance(const Point& p) const;
	
	
	/**
	 * @brief 
	 * @param p
	 * @return 
	 */
	int distance(int x, int y) const;
	
	/**
	 * @brief 
	 * @param dx
	 * @param dy
	 */
	void move(int dx, int dy);
	
};
}
