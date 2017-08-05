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
	//3.�������������� ������������ � ��������� �� ����������� �� �������� ��� ��������� ��������� (���������� � �������������� ������� ��������).
	ifstream fin("polynoms.dat");

	if (fin.fail()) {
		cout<<"�� ������� ������� ���� polynoms.dat"<<endl;
		system("pause");
	} else {
		cout<<"���� ������"<<endl;
		int M, n;
		double argForPolynoms;
		fin>>M;
		cout<<"���������� ���������: "<<M<<endl;
		Polynom* polynoms = new Polynom [M];
		//��������� ��������� ������� �������, ������� ����� ��������� �� ������  ����������  ������� �������
		double** indexOfValPolynoms= new double* [M];
		cout<<"������� �������� ��� ���������: \n";
		cin>>argForPolynoms;
		for (int i=0; i<M;i++) {
			fin>>n;
			cout<<"������� ������� : "<<n<<endl;
			Polynom p(n);
			p.index.resize(n);
			double index = 0.0;
			for (int j=n-1;j>=0;j--) {
				fin>>index;
				cout<<"������ ������: "<<index<<endl;
				p.index[j]=index;
			}
			polynoms[i]=p;
			//��������� ������ ��������
			indexOfValPolynoms[i]=new double [2];
			indexOfValPolynoms[i][0]=p.GetResult(argForPolynoms);
			indexOfValPolynoms[i][1]=i;
		}
		//��������� ������ ��������

		for (int i = M - 1; i >= 0; i--) //������� ����
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
			//cout<<"������� "<<i<<": "<<polynoms[i].count_n<<", ���������: "<<indexOfValPolynoms[i][0]<<endl;
			cout<<"�������� ��������: "<<indexOfValPolynoms[i][0]<<endl;
			cout<<"������ �������� � ������� ���������: "<<indexOfValPolynoms[i][1]<<endl;
		}


	}
}

void task1 (Polynom p) {
	////1. ��������� ����� ��������  ������� ����������� �� �������� ������ [a,b]
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
		}
	}
}
void task2(Polynom p) {
	//2. ���������� �������� �������� ��� ��������� ���������
	cout<<"������� �������� ��� ���������� ��������: "<<endl;
	double polynomArg=0.0;
	cin>>polynomArg;
	cout<<"��������� ���������� ��� ���������: "<<polynomArg<<endl;
	cout<<p.GetResult(polynomArg)<<endl;;
}
void task3() {
	//3. �������������� ������������ � ��������� �� ����������� �� �������� ��� ��������� ���������  (���������� � �������������� ������� ��������).
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