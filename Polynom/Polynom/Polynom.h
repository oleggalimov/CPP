#ifndef POLYNOM_H
#define POLYNOM_H
#endif
#include <vector>

class Polynom
{
public:
	
	Polynom(int n=0);
	int count_n;//количество степеней свободы
	std::vector <double> index;
	
	double GetResult (double x=0.0);
	double getDiff (double x=0.0);
	double getDiff2 (double x=0.0);
	double Neuton_method (double init_approx, double epsilon); 
	
	void printCoef();
	bool is_init_approx(double x=0.0);

	~Polynom(void);
	
};