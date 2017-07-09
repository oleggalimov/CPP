#include <iostream>
#include "vector.h"
using namespace std;


int main () {
	setlocale (LC_ALL, "Russian");

	
	vector defConstr,/*вызов с конструктором по умолчанию - A*/
		   oneParamConstr(1.0, -2.5),/*вызов с одним параметром - B*/
		   allParamConstr(1.2, -3.7,8);//вызов со всеми параметрами - C

	cout<<"Координаты вектора c конструктором по-умолчанию: A("<<defConstr.getXCoord()<<","<<defConstr.getYCoord()<<","<<defConstr.getZCoord()<<")"<<endl;
	cout<<"Длина вектора c конструктором по-умолчанию: "<<defConstr.length()<<endl;

	cout<<"Координаты вектора c конструктором (один параметр): B("<<oneParamConstr.getXCoord()<<","<<oneParamConstr.getYCoord()<<","<<oneParamConstr.getZCoord()<<")"<<endl;
	cout<<"Длина вектора вектора c конструктором (один параметр): "<<oneParamConstr.length()<<endl;

	cout<<"Координаты вектора c конструктором (Все параметры): C("<<allParamConstr.getXCoord()<<","<<allParamConstr.getYCoord()<<","<<allParamConstr.getZCoord()<<")"<<endl;
	cout<<"Длина вектора вектора c конструктором (Все параметры): "<<allParamConstr.length()<<endl;
	
	vector BC=oneParamConstr+allParamConstr;
	cout<<"Сумма векторов B и С: BC("<<BC.getXCoord()<<","<<BC.getYCoord()<<","<<BC.getZCoord()<<")"<<endl;
	cout<<"Длина вектора вектора BC: "<<BC.length()<<endl;

	vector D=oneParamConstr-allParamConstr;
	cout<<"Разность векторов B и С: D("<<D.getXCoord()<<","<<D.getYCoord()<<","<<D.getZCoord()<<")"<<endl;
	cout<<"Длина вектора вектора BC: "<<D.length()<<endl;

	cout<<"Координаты вектора A ДО присваивания: А("<<defConstr.getXCoord()<<","<<defConstr.getYCoord()<<","<<defConstr.getZCoord()<<")"<<endl;
	defConstr=oneParamConstr;
	cout<<"Координаты вектора A ПОСЛЕ присваивания: А("<<defConstr.getXCoord()<<","<<defConstr.getYCoord()<<","<<defConstr.getZCoord()<<")"<<endl;
	
	system("pause");
	return 0;
}