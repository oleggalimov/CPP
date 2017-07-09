#ifndef VECTOR_H
#define VECTOR_H
#endif
class vector
{
public:
	vector(double x=0.0, double y=0.0, double z=0.0);//конструктор с параметрами по-умолчанию
	
	~vector(void);//дестрктор
	//сеттеры
	void setXCoord (double);
	void setYCoord (double);
	void setZCoord (double);
	//геттеры
	double getXCoord ();
	double getYCoord ();
	double getZCoord ();
	//длина вектора
	double length(); 
	//переопределения
	vector operator+(vector);
	vector operator-(vector);
	vector operator=(vector);

protected:
	//защищенные переменные с координатами вектора
	double x_coord, y_coord, z_coord;
};

