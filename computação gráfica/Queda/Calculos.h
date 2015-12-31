/*
 * Calculos.h
 *
 *  Created on: 05/07/2009
 *      Author: diego
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

#include <math.h>

class Calculos {
public:
	Calculos();
	virtual ~Calculos();

	static double espaco(double espaco_inicial,double velocidade_inicial,double instante,double aceleracao);
	static double velocidade(double velocidade_inicial, double instante, double aceleracao);
	static double torriceli(double espaco_inicial, double velocidade_inicial, double velocidade, double aceleracao);
};

#endif /* CALCULOS_H_ */
