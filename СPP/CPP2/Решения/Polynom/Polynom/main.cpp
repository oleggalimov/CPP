#include <iostream>
#include "Polynom.h"
#include <fstream>
using namespace std;

Polynom initAndGetPolynom () {
	cout<<"Введите степень полинома: "<<endl;
	int n=0;
	cin>>n;
	if (n>0) {
		Polynom p(n);
		p.index.resize(n);
		cout<<"Введите коэффициенты (включая равные нулю): "<<endl;
		for (int i=n-1;i>=0;i--) {
			cin>>p.index[i];
		}
		return p;
	} else {
		cout<<"Введено некорректное число степеней полинома, создан нулевой полином"<<endl;
		Polynom p;
		return p;
	}
}
void  initAndGetPolynomFromFile () {
	//3.Упорядочивание совокупности М полиномов по возрастанию их значений для заданного аргумента (сортировка с использованием вектора индексов).
	ifstream fin("polynoms.dat");

	if (fin.fail()) {
		cout<<"Не удалось открыть файл polynoms.dat"<<endl;
		system("pause");
	} else {
		cout<<"Файл открыт"<<endl;
		int M, n;
		double argForPolynoms;
		fin>>M;
		cout<<"Количество полиномов: "<<M<<endl;
		Polynom* polynoms = new Polynom [M];
		//объявляем указатель второго порядка, который будет указывать на массив  указателей  первого порядка
		double** indexOfValPolynoms= new double* [M];
		cout<<"Введите аргумент для полиномов: \n";
		cin>>argForPolynoms;
		for (int i=0; i<M;i++) {
			fin>>n;
			cout<<"Степень свободы : "<<n<<endl;
			Polynom p(n);
			p.index.resize(n);
			double index = 0.0;
			for (int j=n-1;j>=0;j--) {
				fin>>index;
				cout<<"Считан индекс: "<<index<<endl;
				p.index[j]=index;
			}
			polynoms[i]=p;
			//заполняем массив индексов
			indexOfValPolynoms[i]=new double [2];
			indexOfValPolynoms[i][0]=p.GetResult(argForPolynoms);
			indexOfValPolynoms[i][1]=i;
		}
		//сортируем массив значений

		for (int i = M - 1; i >= 0; i--) //главный цикл
		{
			for (int j = 0; j < i; j++)
			{
				if (indexOfValPolynoms[j][0] > indexOfValPolynoms[j + 1][0])
				{
					double tmp[1][2];
					tmp[0][0]=indexOfValPolynoms[j][0];
					tmp[0][1]=indexOfValPolynoms[j][1];
					
					indexOfValPolynoms[j][0]=indexOfValPolynoms[j + 1][0];
					indexOfValPolynoms[j][1]=indexOfValPolynoms[j + 1][1];
					indexOfValPolynoms[j + 1][0]=tmp[0][0];
					indexOfValPolynoms[j + 1][1]=tmp[0][1];
				}
			}
		}

		for (int i=0;i<M;i++) {
			//cout<<"Полином "<<i<<": "<<polynoms[i].count_n<<", результат: "<<indexOfValPolynoms[i][0]<<endl;
			cout<<"значение полинома: "<<indexOfValPolynoms[i][0]<<endl;
			cout<<"Индекс полинома в массиве полиномов: "<<indexOfValPolynoms[i][1]<<endl;
		}


	}
}

void task1 (Polynom p) {
	////1. уточнение корня полинома  методом касательных на заданном орезке [a,b]
	////тестовые примеры - -6x3+2x2-3.2x+12, пп -10 eps=0.001 (13 итер, 1.2277) и x3+4x-3 eps=0.001 (3 итер, 067422).

	double a=0, b=0;
	cout<<"Введите левую границу отрезка: "<<endl;
	cin>>a;
	cout<<"Введите правую границу отрезка: "<<endl;
	cin>>b;
	if (a>b) {
		double temp=a;
		a=b;
		b=temp;
	}
	if (p.GetResult(a)*p.GetResult(b)>0) {
		cout<<"На заданном отрезке отсуствует корень!"<<endl;
		system("pause");
	} else {
		cout<<"вычисляем корень полинома на отрезке ["<<a<<";"<<b<<"] с точностью до 0,001"<<endl;
		if (p.is_init_approx(a)) {
			double result = p.Neuton_method(a,0.001);
			cout<<"Метод ньютона: " <<result <<endl;
		} else if (p.is_init_approx(b)) {
			double result = p.Neuton_method(b,0.001);
			cout<<"Метод ньютона: " <<result <<endl;
		} else {
			cout<<"не удалось выбрать начальное приближение на заданном отрезке"<<endl;
			system("pause");
		}
	}
}
void task2(Polynom p) {
	//2. Вычисление значения полинома для заданного аргумента
	cout<<"Введите аргумент для вычисления полинома: "<<endl;
	double polynomArg=0.0;
	cin>>polynomArg;
	cout<<"Результат вычисления для аргумента: "<<polynomArg<<endl;
	cout<<p.GetResult(polynomArg)<<endl;;
}
void task3() {
	//3. Упорядочивание совокупности М полиномов по возрастанию их значений для заданного аргумента  (сортировка с использованием вектора индексов).
	initAndGetPolynomFromFile ();

}

int main () {
	setlocale (LC_ALL, "Russian");
	//Polynom p = initAndGetPolynom ();
	//task1(p);
	//task2(p);
	task3();

	system("pause");

}