#include "vector.h"
#include <iostream>
double x_coord, y_coord, z_coord,tempX;

vector::vector(double x, double y, double z):x_coord(x),y_coord(y),z_coord(z)
{
	std::cout<<"Создан вектор с координатами: ("<<getXCoord()<<", "<<getYCoord()<<", "<<getZCoord()<<")"<<std::endl;
}
vector::~vector(void)
{
	//std::cout<<"Уничтожен вектор с координатами: ("<<getXCoord()<<", "<<getYCoord()<<", "<<getZCoord()<<")"<<std::endl;
}

//сеттеры
void vector::setXCoord (double x) {
	x_coord=x;
}
void vector::setYCoord (double y) {
	y_coord=y;
}
void vector::setZCoord (double z) {
	z_coord=z;
}
//геттеры
double vector::getXCoord () {
	return x_coord;
}
double vector::getYCoord () {
	return y_coord;
}
double vector::getZCoord () {
	return z_coord;
}
//длина
double vector::length () {
	return sqrt(x_coord*x_coord+y_coord*y_coord+z_coord*z_coord);
}
//переопределения
vector vector::operator+ ( vector r) {
	
	return vector ((getXCoord()+r.getXCoord()),(getYCoord()+r.getYCoord()),(getZCoord()+r.getZCoord()));
}
vector vector::operator- ( vector r) {
	
	return vector ((getXCoord()-r.getXCoord()),(getYCoord()-r.getYCoord()),(getZCoord()-r.getZCoord()));
}
vector vector::operator=(vector v ) {
	x_coord=v.getXCoord();
	y_coord=v.getYCoord();
	z_coord=v.getZCoord();
	std::cout<<"Вызван переопределенный метод присваивания.\n"; 
	return *this;
}