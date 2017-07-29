#include <iostream>
#include "Polynom.h"
#include <fstream>
using namespace std;

Polynom getPolynom () {
	cout<<"¬ведите степень полинома: "<<endl;
	int n=0;
	cin>>n;
	if (n>0) {
		Polynom p(n);
		return p;
	} else {
		cout<<"¬ведено некорректное число степеней полинома, создан нулевой полином"<<endl;
		Polynom p;
		return p;
	}
}

int main () {
	setlocale (LC_ALL, "Russian");
	//Polynom p = getPolynom();

	////1. уточнение корн€ полинома на заданном отрезке методом касательных на заданном орезке [a,b]
	////тестовые примеры - -6x3+2x2-3.2x+12б eps=0.001 (13 итер, 1.2277) и x3+4x-3 eps=0.001 (3 итер, 067422).
	//double a=0, b=0;
	//cout<<"¬ведите левую границу отрезка: "<<endl;
	//cin>>a;
	//cout<<"¬ведите правую границу отрезка: "<<endl;
	//cin>>b;
	//if (a>b) {
	//	double temp=a;
	//	a=b;
	//	b=temp;
	//}
	//if (p.GetResult(a)*p.GetResult(b)>0) {
	//	cout<<"Ќа заданном отрезке отсуствует корень!"<<endl;
	//	system("pause");
	//	return -1;
	//} else {
	//	cout<<"вычисл€ем корень полинома на отрезке ["<<a<<";"<<b<<"] с точностью до 0,001"<<endl;
	//	if (p.is_init_approx(a)) {
	//		double iteration=p.Neuton_method (0.001, a);
	//		cout<<" оличество итераций: "<<iteration<<endl;
	//	} else if (p.is_init_approx(b)) {
	//		double iteration=p.Neuton_method (0.001, b);
	//		cout<<" оличество итераций: "<<iteration<<endl;
	//	} else {
	//		cout<<"Ќе удалось выбрать начальное приближение на заданном отрезке"<<endl;
	//		system("pause");
	//		return -2;
	//	}
	//}
	////2. ¬ычисление значени€ полинома дл€ заданного аргумента
	//cout<<"¬ведите аргумент дл€ вычислени€ полинома: "<<endl;
	//double polynomArg=0.0;
	//cin>>polynomArg;
	//cout<<"–езультат вычислени€ дл€ аргумента: "<<polynomArg<<endl;
	//cout<<p.GetResult(polynomArg)<<endl;
	//3. ”пор€дочивание совокупности ћ полиномов по возрастанию их значений дл€ заданного аргумента  (сортировка с использованием вектора индексов).
	ifstream fin("polynoms.dat");
	if (fin.fail()) {
		cout<<"Ќе удалось открыть файл polynoms.dat"<<endl;
		system("pause");
		return -3;
	} else {
		cout<<"‘айл открыт"<<endl;
		double M;
		fin>>M;
		cout<<" оличество полиномов: "<<M<<endl;
		{
			int n;
			fin>>n;
			cout<<"—тепень свободы : "<<n<<endl;
			Polynom p(n, true);
			double* index=p.getIndexes();
			index[0]=2.5;
			p.printCoef();
		}
		
	}
	system("pause");

}