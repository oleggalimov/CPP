#include <iostream>
#include "Polynom.h"
#include <fstream>
using namespace std;

Polynom initAndGetPolynom () {
	cout<<"������� ������� ��������: "<<endl;
	int n=0;
	cin>>n;
	if (n>0) {
		Polynom p(n);
		p.index.resize(n);
		cout<<"������� ������������ (������� ������ ����): "<<endl;
		for (int i=n-1;i>=0;i--) {
			cin>>p.index[i];
		}
		return p;
	} else {
		cout<<"������� ������������ ����� �������� ��������, ������ ������� �������"<<endl;
		Polynom p;
		return p;
	}
}

void  initAndGetPolynomFromFile () {
	ifstream fin("polynoms.dat");
	if (fin.fail()) {
		cout<<"�� ������� ������� ���� polynoms.dat"<<endl;
		system("pause");
		//return -3;
	} else {
		cout<<"���� ������"<<endl;
		int M, n;
		fin>>M;
		cout<<"���������� ���������: "<<M<<endl;
		Polynom* polynoms = new Polynom [M];
		for (int i=0; i<M;i++) {
			fin>>n;
			cout<<"������� ������� : "<<n<<endl;
			Polynom p(n);
			double index = 0.0;
			for (int j=0;j<n;j++) {
				fin>>index;
				cout<<"������ ������: "<<index<<endl;
			}
			polynoms[i]=p;
		}
		for (int i=0;i<M;i++) {
			cout<<"������� "<<i<<": "<<polynoms[i].count_n<<endl;
		}

	}
}

int main () {
	setlocale (LC_ALL, "Russian");
	initAndGetPolynomFromFile ();
	
	Polynom p = initAndGetPolynom ();

	////1. ��������� ����� �������� �� �������� ������� ������� ����������� �� �������� ������ [a,b]
	////�������� ������� - -6x3+2x2-3.2x+12, �� -10 eps=0.001 (13 ����, 1.2277) � x3+4x-3 eps=0.001 (3 ����, 067422).
	
	double a=0, b=0;
	cout<<"������� ����� ������� �������: "<<endl;
	cin>>a;
	cout<<"������� ������ ������� �������: "<<endl;
	cin>>b;
	if (a>b) {
		double temp=a;
		a=b;
		b=temp;
	}
	if (p.GetResult(a)*p.GetResult(b)>0) {
		cout<<"�� �������� ������� ���������� ������!"<<endl;
		system("pause");
		return -1;
	} else {
		cout<<"��������� ������ �������� �� ������� ["<<a<<";"<<b<<"] � ��������� �� 0,001"<<endl;
		if (p.is_init_approx(a)) {
			double result = p.Neuton_method(a,0.001);
			cout<<"����� �������: " <<result <<endl;
		} else if (p.is_init_approx(b)) {
			double result = p.Neuton_method(b,0.001);
			cout<<"����� �������: " <<result <<endl;
		} else {
			cout<<"�� ������� ������� ��������� ����������� �� �������� �������"<<endl;
			system("pause");
			return -2;
		}
	}
	

	//2. ���������� �������� �������� ��� ��������� ���������
	cout<<"������� �������� ��� ���������� ��������: "<<endl;
	double polynomArg=0.0;
	cin>>polynomArg;
	cout<<"��������� ���������� ��� ���������: "<<polynomArg<<endl;
	cout<<p.GetResult(polynomArg)<<endl;

	//3. �������������� ������������ � ��������� �� ����������� �� �������� ��� ��������� ���������  (���������� � �������������� ������� ��������).

	system("pause");

}