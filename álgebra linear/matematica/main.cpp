#include <iostream>
#include "Dmatrix.h"
#include "Order.h"

using namespace std;
using namespace LLA;


int main(int argc, char *argv[]){
	Dmatrix d(3,3);
	Dmatrix e(3,3);
	Dmatrix resp(3,3);
	
	d.set_value(1,1,-6);
	d.set_value(1,2,4);
	d.set_value(1,3,0);
	d.set_value(2,1,1);
	d.set_value(2,2,1);
	d.set_value(2,3,4);
	d.set_value(3,1,-6);
	d.set_value(3,2,0);
	d.set_value(3,3,-6);
	
	e.set_value(1,1,6);
	e.set_value(1,2,9);
	e.set_value(1,3,-9);
	e.set_value(2,1,-1);
	e.set_value(2,2,0);
	e.set_value(2,3,-4);
	e.set_value(3,1,-6);
	e.set_value(3,2,0);
	e.set_value(3,3,-1);
	
	//d.transp();
	resp = d * d;
	//d.print_matrix();
	
	//e.transp();
	e = d*e;
	e.print_matrix();
	
	resp = resp - e;
	//resp.transp();
	resp.print_matrix();
	
	cout << "\nfim" << endl;
		
	return 0;
}
