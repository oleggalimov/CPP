#include "Polynom.h"
#include <iostream>
#include <cmath>

int count_n;
double* index;
double* df_index;
double* df_2_index;

Polynom::Polynom(int N, bool formFile):count_n(N)
{
	index = new double[count_n];

	if (formFile) {
		std::cout<<"Конструктор для работы с файлом"<<std::endl;
	} else {
		df_index=new double[count_n-1];
		df_2_index=new double[count_n-2];
		std::cout<<"заполните коэффициенты при x, начиная с младшего: \n";
		for (int i=0;i<count_n;i++) {
			std::cin>>index[i];
		}
		//вычисляем коэффициенты производной
		for (int i=1;i<count_n;i++) {
			df_index[i-1]=index[i]*i;
		}
	}

}

double Polynom::GetResult(double x) {
	double result=0.0;
	double temp=x;
	for (int i=1;i<count_n;i++) {
		result+=(index[i]*temp);
		temp=temp*x;
	}
	return (result+index[0]);
};

double Polynom::GetResult_df(double x) {
	double result=0.0;
	double temp=x;
	for (int i=1;i<count_n-1;i++) {
		result+=(df_index[i]*temp);
		temp=temp*x;
	}
	return (result+df_index[0]);
}

double Polynom::GetResult_2_df(double x) {
	//вычисляем коэффициенты второй производной
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
}

bool Polynom::is_init_approx (double x){
	return (GetResult_df(x)*GetResult_2_df(x))>0;
}; 

double Polynom::Neuton_method (double epsilon, double init_approx) {
	double next_approx=init_approx,
		prev_approx=init_approx, 
		difference=epsilon;
	int iteration=0;

	do {
		prev_approx=next_approx;
		difference=GetResult(prev_approx)/GetResult_df(prev_approx);
		next_approx=prev_approx-difference;
		iteration++;
	} while (abs(difference) > epsilon);
	std::cout<<"Количество итераций - "<<iteration<<std::endl;
	return prev_approx;
}

void Polynom::printCoef () {
	std::cout<<"Полученный массив значений: \n";
	for (int i=0;i<count_n;i++) {
		std::cout<<index[i]<<std::endl;
	}
}

void Polynom::printDfCoef () {
	if (df_index) {
		std::cout<<"Полученный массив значений: \n";
		for (int i=0;i<count_n-1;i++) {
			std::cout<<df_index[i]<<std::endl;
		} 
	} else {
		std::cout<<"Производная не рассчитывалась \n";
	}
}

void Polynom::printDf_2_Coef () {
	if (df_2_index) {
		std::cout<<"Полученный массив значений: \n";
		for (int i=0;i<count_n-2;i++) {
			std::cout<<df_2_index[i]<<std::endl;
		}
	} else {
		std::cout<<"Вторая производная не рассчитывалась \n";
	}
}

double* Polynom::getIndexes() {
	return index;
}

Polynom::~Polynom(void)
{
}


