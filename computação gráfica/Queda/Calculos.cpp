/*
 * Calculos.cpp
 *
 *  Created on: 05/07/2009
 *      Author: diego
 */

#include "Calculos.h"

Calculos::Calculos() {
	// TODO Auto-generated constructor stub

}

Calculos::~Calculos() {
	// TODO Auto-generated destructor stub
}

double Calculos::espaco(double espaco_inicial,double velocidade_inicial,double instante,double aceleracao)
{
	instante = instante/1000;
	return (espaco_inicial + velocidade_inicial*instante + (aceleracao*instante*instante)/2);
}

double Calculos::velocidade(double velocidade_inicial,double instante,double aceleracao)
{
	instante = instante/1000;
	return (velocidade_inicial + (instante*aceleracao)/2);
}

double Calculos::torriceli(double espaco_inicial, double velocidade_inicial, double velocidade, double aceleracao)
{
	return (espaco_inicial +(velocidade*velocidade - velocidade_inicial*velocidade_inicial)/2*aceleracao);
}
