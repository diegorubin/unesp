#ifndef ORDER_H_
#define ORDER_H_

namespace LLA
{

struct order{
	int n;
	int m;
	
	bool operator==(order param){
		if((n == param.n) && (m == param.m))
				return true;
		else
			return false;
	};
	
	bool operator!=(order param){
			if((n != param.n) || (m != param.m))
					return true;
			else
				return false;
		};
	
};
}

#endif /*ORDER_H_*/
