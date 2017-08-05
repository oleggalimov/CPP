#include "Polynom.h"
#include <iostream>
#include <cmath>
#include <vector>


int count_n;

std::vector <double> index;

Polynom::Polynom(int N):count_n(N)
{
	;

}

double Polynom::GetResult(double x) {
	if (index.size()>0) {

		double result=0.0;
		double temp=x;
		for (int i=1;i<count_n;i++) {
			result+=(index[i]*temp);
			temp=temp*x;
		}
		return (result+index[0]);
	} else {
		std::cout<<"Полином не проинициализирован!\n";
		return 0;
	}

};

double Polynom::getDiff(double x) {
	if (index.size()>0) {
		std::vector <double> df_index;
		df_index.resize(count_n-1);
		for (int i=1;i<count_n;i++) {
			df_index[i-1]=index[i]*i;
		}
		double result=0.0;
		double temp=x;
		for (int i=1;i<count_n-1;i++) {
			result+=(df_index[i]*temp);
			temp=temp*x;
		}
		return (result+df_index[0]);
	} else {
		std::cout<<"Полином не проинициализирован!\n";
		return 0;
	}
}

double Polynom::getDiff2(double x) {
	//вычисляем коэффициенты второй производной
	if (index.size()>0) {
		std::vector <double> df_index;
		df_index.resize(count_n-1);
		for (int i=1;i<count_n;i++) {
			df_index[i-1]=index[i]*i;
		}
		std::vector <double> df_2_index;
		df_2_index.resize(count_n-2);
		for (int i=1;i<count_n-1;i++) {
			df_2_index[i-1]=df_index[i]*i;
		}
		double result=0.0;
		double temp=x;
		for (int i=1;i<count_n-2;i++) {
			result+=(df_2_index[i]*temp);
			temp=temp*x;
		}
		return (result+df_2_index[0]);
	} else {
		std::cout<<"Полином не проинициализирован!\n";
		return 0;
	}
}

bool Polynom::is_init_approx (double x){
	return (GetResult(x)*getDiff2(x))>0;
}; 

double Polynom::Neuton_method ( double init_approx,double epsilon) {
	double next_approx=init_approx,
		prev_approx=init_approx, 
		difference=epsilon;
	int iteration=0;

	do {
		prev_approx=next_approx;
		difference=GetResult(prev_approx)/getDiff(prev_approx);
		next_approx=prev_approx-difference;
		iteration++;
	} while (abs(difference) > epsilon);
	std::cout<<"Количество итераций - "<<iteration<<std::endl;
	return prev_approx;
}

void Polynom::printCoef () {
	if (index.size()>0) {
		std::cout<<"Массив значений: \n";
		for (int i=0;i<count_n;i++) {
			std::cout<<index[i]<<std::endl;
		}
	} else {
		std::cout<<"Полином не проинициализирован!\n";
	}
}

Polynom::~Polynom(void)
{
}


