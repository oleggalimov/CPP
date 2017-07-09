#include <iostream>
#include "vector.h"
using namespace std;


int main () {
	setlocale (LC_ALL, "Russian");

	
	vector defConstr,/*����� � ������������� �� ��������� - A*/
		   oneParamConstr(1.0, -2.5),/*����� � ����� ���������� - B*/
		   allParamConstr(1.2, -3.7,8);//����� �� ����� ����������� - C

	cout<<"���������� ������� c ������������� ��-���������: A("<<defConstr.getXCoord()<<","<<defConstr.getYCoord()<<","<<defConstr.getZCoord()<<")"<<endl;
	cout<<"����� ������� c ������������� ��-���������: "<<defConstr.length()<<endl;

	cout<<"���������� ������� c ������������� (���� ��������): B("<<oneParamConstr.getXCoord()<<","<<oneParamConstr.getYCoord()<<","<<oneParamConstr.getZCoord()<<")"<<endl;
	cout<<"����� ������� ������� c ������������� (���� ��������): "<<oneParamConstr.length()<<endl;

	cout<<"���������� ������� c ������������� (��� ���������): C("<<allParamConstr.getXCoord()<<","<<allParamConstr.getYCoord()<<","<<allParamConstr.getZCoord()<<")"<<endl;
	cout<<"����� ������� ������� c ������������� (��� ���������): "<<allParamConstr.length()<<endl;
	
	vector BC=oneParamConstr+allParamConstr;
	cout<<"����� �������� B � �: BC("<<BC.getXCoord()<<","<<BC.getYCoord()<<","<<BC.getZCoord()<<")"<<endl;
	cout<<"����� ������� ������� BC: "<<BC.length()<<endl;

	vector D=oneParamConstr-allParamConstr;
	cout<<"�������� �������� B � �: D("<<D.getXCoord()<<","<<D.getYCoord()<<","<<D.getZCoord()<<")"<<endl;
	cout<<"����� ������� ������� BC: "<<D.length()<<endl;

	cout<<"���������� ������� A �� ������������: �("<<defConstr.getXCoord()<<","<<defConstr.getYCoord()<<","<<defConstr.getZCoord()<<")"<<endl;
	defConstr=oneParamConstr;
	cout<<"���������� ������� A ����� ������������: �("<<defConstr.getXCoord()<<","<<defConstr.getYCoord()<<","<<defConstr.getZCoord()<<")"<<endl;
	
	system("pause");
	return 0;
}