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
	ifstream fin("polynoms.dat");
	if (fin.fail()) {
		cout<<"Не удалось открыть файл polynoms.dat"<<endl;
		system("pause");
		//return -3;
	} else {
		cout<<"Файл открыт"<<endl;
		int M, n;
		fin>>M;
		cout<<"Количество полиномов: "<<M<<endl;
		Polynom* polynoms = new Polynom [M];
		for (int i=0; i<M;i++) {
			fin>>n;
			cout<<"Степень свободы : "<<n<<endl;
			Polynom p(n);
			double index = 0.0;
			for (int j=0;j<n;j++) {
				fin>>index;
				cout<<"Считан индекс: "<<index<<endl;
			}
			polynoms[i]=p;
		}
		for (int i=0;i<M;i++) {
			cout<<"Полином "<<i<<": "<<polynoms[i].count_n<<endl;
		}

	}
}

int main () {
	setlocale (LC_ALL, "Russian");
	initAndGetPolynomFromFile ();
	
	Polynom p = initAndGetPolynom ();

	////1. уточнение корня полинома на заданном отрезке методом касательных на заданном орезке [a,b]
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
		return -1;
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
			return -2;
		}
	}
	

	//2. Вычисление значения полинома для заданного аргумента
	cout<<"Введите аргумент для вычисления полинома: "<<endl;
	double polynomArg=0.0;
	cin>>polynomArg;
	cout<<"Результат вычисления для аргумента: "<<polynomArg<<endl;
	cout<<p.GetResult(polynomArg)<<endl;

	//3. Упорядочивание совокупности М полиномов по возрастанию их значений для заданного аргумента  (сортировка с использованием вектора индексов).

	system("pause");

}