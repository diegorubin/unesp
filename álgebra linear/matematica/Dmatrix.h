#ifndef DMATRIX_H_
#define DMATRIX_H_

#include <iostream>

#include "Order.h"


namespace LLA
{

class Dmatrix
{
	
public:
	Dmatrix(int rows, int cols);
	virtual ~Dmatrix();
	
	//set
	bool set_value(int i, int j, double value);
	void transp();
	
	//prints
	void print_matrix();
	void print_order();
	
	//gets
	double get_value(int i, int j);
	order get_order();
	
	//operators
	Dmatrix operator+ (Dmatrix param);
	Dmatrix operator- (Dmatrix param);
	Dmatrix operator* (int param);	
	Dmatrix operator* (float param);	
	Dmatrix operator* (double param);
	Dmatrix operator* (Dmatrix param);
	bool operator== (Dmatrix param);
	
private:
	double pos_value[255][255];
	int num_rows;
	int num_cols;
	
	order m_order;
};

}

#endif /*DMATRIX_H_*/
