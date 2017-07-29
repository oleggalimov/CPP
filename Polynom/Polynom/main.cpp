#include <iostream>
#include "Polynom.h"
#include <fstream>
using namespace std;

Polynom getPolynom () {
	cout<<"������� ������� ��������: "<<endl;
	int n=0;
	cin>>n;
	if (n>0) {
		Polynom p(n);
		return p;
	} else {
		cout<<"������� ������������ ����� �������� ��������, ������ ������� �������"<<endl;
		Polynom p;
		return p;
	}
}

int main () {
	setlocale (LC_ALL, "Russian");
	//Polynom p = getPolynom();

	////1. ��������� ����� �������� �� �������� ������� ������� ����������� �� �������� ������ [a,b]
	////�������� ������� - -6x3+2x2-3.2x+12� eps=0.001 (13 ����, 1.2277) � x3+4x-3 eps=0.001 (3 ����, 067422).
	//double a=0, b=0;
	//cout<<"������� ����� ������� �������: "<<endl;
	//cin>>a;
	//cout<<"������� ������ ������� �������: "<<endl;
	//cin>>b;
	//if (a>b) {
	//	double temp=a;
	//	a=b;
	//	b=temp;
	//}
	//if (p.GetResult(a)*p.GetResult(b)>0) {
	//	cout<<"�� �������� ������� ���������� ������!"<<endl;
	//	system("pause");
	//	return -1;
	//} else {
	//	cout<<"��������� ������ �������� �� ������� ["<<a<<";"<<b<<"] � ��������� �� 0,001"<<endl;
	//	if (p.is_init_approx(a)) {
	//		double iteration=p.Neuton_method (0.001, a);
	//		cout<<"���������� ��������: "<<iteration<<endl;
	//	} else if (p.is_init_approx(b)) {
	//		double iteration=p.Neuton_method (0.001, b);
	//		cout<<"���������� ��������: "<<iteration<<endl;
	//	} else {
	//		cout<<"�� ������� ������� ��������� ����������� �� �������� �������"<<endl;
	//		system("pause");
	//		return -2;
	//	}
	//}
	////2. ���������� �������� �������� ��� ��������� ���������
	//cout<<"������� �������� ��� ���������� ��������: "<<endl;
	//double polynomArg=0.0;
	//cin>>polynomArg;
	//cout<<"��������� ���������� ��� ���������: "<<polynomArg<<endl;
	//cout<<p.GetResult(polynomArg)<<endl;
	//3. �������������� ������������ � ��������� �� ����������� �� �������� ��� ��������� ���������  (���������� � �������������� ������� ��������).
	ifstream fin("polynoms.dat");
	if (fin.fail()) {
		cout<<"�� ������� ������� ���� polynoms.dat"<<endl;
		system("pause");
		return -3;
	} else {
		cout<<"���� ������"<<endl;
		double M;
		fin>>M;
		cout<<"���������� ���������: "<<M<<endl;
		{
			int n;
			fin>>n;
			cout<<"������� ������� : "<<n<<endl;
			Polynom p(n, true);
			double* index=p.getIndexes();
			index[0]=2.5;
			p.printCoef();
		}
		
	}
	system("pause");

}