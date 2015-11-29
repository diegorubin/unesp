#include "Dmatrix.h"

namespace LLA
{

Dmatrix::Dmatrix(int rows, int cols)
{
	int i,j;
	
	num_rows = rows;
	num_cols = cols;
	
	for(i = 1; i <= num_rows; i++)
		for(j = 1; j <= num_cols; j++)
			pos_value[i][j] = 0;
	
	
}
order Dmatrix::get_order()
{
	m_order.m = num_rows;
	m_order.n = num_cols;
	
	return (m_order);
	
}

bool Dmatrix::set_value(int i, int j, double value)
{
	if((i > num_rows || j > num_cols) || (i == 0 || j == 0))
		return false;
	else{
		pos_value[i][j] = value;
		return true;
	}
	
			
}

void Dmatrix::print_matrix()
{
	int i,j;
	
	for(i =1; i <= num_rows; i++){
		std::cout << "| ";
		for(j = 1; j <= num_cols; j++){
			std::cout << " " << pos_value[i][j] << " ";
			if( j == num_cols) std::cout << " |" << std::endl;
		}
	}
	
}

void Dmatrix::print_order()
{
	std::cout << "a ordem da matriz e " << num_rows << " por " << num_cols << std::endl;
}

double Dmatrix::get_value(int i, int j)
{
	return pos_value[i][j];
}

Dmatrix Dmatrix::operator+(Dmatrix param)
{
	int i,j;
	order tmp1,tmp2;
		
	tmp1 = get_order();
	tmp2 = param.get_order();
	
	Dmatrix tmp(tmp1.m,tmp1.n);
	
	if(tmp1 == tmp2){
		for(i = 1; i <= tmp1.m; i++ )
			for(j =1; j <= tmp1.n; j++)
				tmp.set_value(i,j,(get_value(i,j)+param.get_value(i,j)));
		return (tmp);
	}
	else
		std::cout << "ERROR:sum of matrix with diferent order";
		abort();
	
}

Dmatrix Dmatrix::operator-(Dmatrix param)
{
	int i,j;
	order tmp1,tmp2;
		
	tmp1 = get_order();
	tmp2 = param.get_order();
	
	Dmatrix tmp(tmp1.m,tmp1.n);
	
	if(tmp1 == tmp2){
		for(i = 1; i <= tmp1.m; i++ )
			for(j =1; j <= tmp1.n; j++)
				tmp.set_value(i,j,(get_value(i,j)-param.get_value(i,j)));
		return (tmp);
	}
	else
		std::cout << "ERROR:sum of matrix with diferent order";
		abort();
	
}

Dmatrix Dmatrix::operator *(int param)
{
	int i,j;
	order tmp1 = get_order();
	
	Dmatrix tmp(tmp1.m,tmp1.n);
	for(i = 1; i <= tmp1.m; i++)
		for(j = 1; j <= tmp1.n; j++)
			tmp.set_value(i,j,get_value(i,j) * param);
	return (tmp);
}

Dmatrix Dmatrix::operator *(float param)
{
	int i,j;
	order tmp1 = get_order();
	
	Dmatrix tmp(tmp1.m,tmp1.n);
	for(i = 1; i <= tmp1.m; i++)
		for(j = 1; j <= tmp1.n; j++)
			tmp.set_value(i,j,get_value(i,j) * param);
	return (tmp);
}

Dmatrix Dmatrix::operator *(double param)
{
	int i,j;
	order tmp1 = get_order();
	
	Dmatrix tmp(tmp1.m,tmp1.n);
	for(i = 1; i <= tmp1.m; i++)
		for(j = 1; j <= tmp1.n; j++)
			tmp.set_value(i,j,get_value(i,j) * param);
	return (tmp);
}

Dmatrix Dmatrix::operator *(Dmatrix param)
{
	int i,j,k;
	order tmp1,tmp2;
	
	tmp1 = get_order();
	tmp2 = param.get_order();
	
	Dmatrix tmp(tmp1.m,tmp2.n);
	
	if(tmp1.n == tmp2.m){
		for(i = 1; i <= tmp1.m; i++)
			for(j = 1; j <= tmp2.n; j++)
				for(k = 1; k <= tmp1.n; k++)
					tmp.set_value(i,j,tmp.get_value(i,j) + (get_value(i,k)*param.get_value(k,j)));
		return(tmp);
	}
	else
		abort();
	
}

bool Dmatrix::operator ==(Dmatrix param)
{
	int i,j;
	
	order tmp;
	bool resp;
	
	resp = true;
	
	if(get_order() != param.get_order())
		return false;
	else{
		tmp = get_order();
		for(i = 1; i <= tmp.m; i++)
			for(j = 1; j <= tmp.n; j++)
				if(get_value(i,j) != param.get_value(i,j)){
					resp = false;
					break;
				}
		return resp;
	}
		
	
}

void Dmatrix::transp()
{
	int i,j;
	order tmp1;
	tmp1 = get_order();
	
	Dmatrix tmp(tmp1.n,tmp1.m);
	
	for(i=1; i<=tmp1.m; i++)
		for(j=1; j<=tmp1.n; j++)
			tmp.set_value(j,i, pos_value[i][j]);
	*this = tmp; 
}

Dmatrix::~Dmatrix()
{
}


}
