/*
������� 6: �������� � ��������: �������� (������), �������� ��� (������������ �����), 
�������� ������������ (���� �� ��������: 0 - ��� ������������, 1-�������������, 2- ���������),
�� ��������� � ��������� ���������� (�� ����� N) ������� �������� ������ ������� �������� ������������, ������������� �� 
����������� �������� �����. ���� ������ ������ ��� - ������ ���������. 
*/

#include <iostream>
#include <fstream>

using namespace std;



struct material  {
	//��������� - ��������
	char name [50];//��������
	int provodnik;//�������� ������������
	float udVes;//�������� ���
};
void vibor (material mat [], int n,int t) {
	material *temp = new material[n];
	int counter=0;
	//�������� ������
	for (int i=0;i<n;i++) {
		if (mat[i].provodnik==t) {
			temp[counter]=mat[i];
			counter++;
		}
	}
	
	if (counter>0) {
		cout<<"������� ���������: "<<counter<<endl;

		material buff; //��������� ���������� ��� ����
		for (int i=0;i<counter-1;i++) {	//������� ������
		
			for (int j = i+1;j<counter;j++) { //������ �� ���������� �����
				if (temp[i].udVes>temp[j].udVes) {
					buff = temp[i];//����� ������� ���������
					temp[i] = temp[j];//�� ��� ����� ��������� ������
					temp[j] = buff;//�� ����� ������� - �����
					buff;
				}
			}
		}
	for (int i=0;i<counter;i++) {
		cout<<"��������: "<<temp[i].name<<endl;
		cout<<"	- ������� ������������: "<<temp[i].provodnik<<endl;
		cout<<"	- �������� ���: "<<temp[i].udVes<<endl;
	}

	} else {
		cout<<"�������� ��������� ���� �� �������"<<endl;
	}
}
int main () {
		//������ ������
      setlocale(LC_ALL,"Russian");
      //������� ������ ��������� ������
      ifstream ifs;
     
	  int counter=0;//���������� ������� �������
	  material materials[25];//������ �������
      ifs.open("materials.txt"); //��������� ����
	  if (ifs.fail())  {
		  cout<<"������ �������� �����"<<endl;
		  return -1;
	  } else {
		  
		  
		  
		  float temp;
		  while (!ifs.eof()) {
			  ifs.getline(materials[counter].name, 50);//������ ��������
			  cout<<materials[counter].name<<endl;//������� �������� ��� ��������
			  ifs>>materials[counter].udVes;//������! ����������� ��� ������������ ����� �.�. �����!
			  cout<<materials[counter].udVes<<endl;//������� �����
			  ifs >> materials[counter].provodnik;//���������� �������� ������������
			  cout<<materials[counter].provodnik<<endl; //������� �������� ������������
			  counter++;//����������� �������
			  ifs.get();//������! �������� >>�������� ��������� ��������, �� ������ � ����� �������� � ������,
						//�.�. ������ � ����� �������� ����� ������ '\n', ��� ���� ������� ��� � �������, ������� ������.
		  }
	  }
	 
	  cout<<endl<<"���������� �������: "<<counter<<endl;
	  if (counter>1) {//����� ����� ����� ������ ���� ������� ������ ������
		  int provod=-1;//�������� ��� ������
		  bool exit=false;
		  cout<<"������� ������������ (0,1,2):"<<endl;
		
		  do  {
			  cin>>provod;
			  if ((provod>(-1))&&(provod<3)) {
				exit=true;
			  } else {
				  cout<<"�������� ������������!"<<endl;
				 }
		  } while (!exit);

		  vibor(materials,counter,provod);
	  }
	  else {
	  cout<<"������� ���� ������� ��� ������!"<<endl;
	  }
	  
	  system ("pause");
	  return 0;

}