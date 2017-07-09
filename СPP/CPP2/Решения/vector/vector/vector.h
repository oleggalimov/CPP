#ifndef VECTOR_H
#define VECTOR_H
#endif
class vector
{
public:
	vector(double x=0.0, double y=0.0, double z=0.0);//����������� � ����������� ��-���������
	
	~vector(void);//���������
	//�������
	void setXCoord (double);
	void setYCoord (double);
	void setZCoord (double);
	//�������
	double getXCoord ();
	double getYCoord ();
	double getZCoord ();
	//����� �������
	double length(); 
	//���������������
	vector operator+(vector);
	vector operator-(vector);
	vector operator=(vector);

protected:
	//���������� ���������� � ������������ �������
	double x_coord, y_coord, z_coord;
};

