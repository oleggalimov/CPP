#ifndef POLYNOM_H
#define POLYNOM_H
#endif

class Polynom
{
public:
	Polynom(int n=0,bool formFile = false);
	int count_n;//количество степеней свободы

	double GetResult (double x=0.0);
	double GetResult_df (double x=0.0);
	double GetResult_2_df (double x=0.0);
	double Neuton_method (double epsilon=0.0, double init_approx=0.0); 

	void printCoef();
	void printDfCoef();
	void printDf_2_Coef();

	bool is_init_approx(double x=0.0);

	double* getIndexes();

	~Polynom(void);
	
};