/*#include <iostream>

#include <fstream>

 

using namespace std;
//������� ������ �������
void printArray (int arr[][255], int n) {
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cout<<" ";
			cout<<arr[i][j];
		}
		cout <<endl;
	}
	cout <<endl;
}

int main () {
      //������ ������
      setlocale(LC_ALL,"Russian");
      //������� ������ ��������� ������
      ifstream ifs;
      //��������� ����

      ifs.open("matrix.txt");
	  
 
      //���������, ��� ���� ��������

      if (ifs.fail()) {

            cout <<"�� ������� ������� ����, ��������� ����" << endl;

            system ("Pause");

            return -1;

      } else {
		  char *temp=new char [255];
		  int temp_int, temp_cur=0, temp_col_cur=0;
		  char temp_char, temp_char_string[4];

		while (!ifs.eof()) {
			ifs.getline(temp,255);
			
			while ((temp_char=temp[temp_cur])!='\0') {
				if (temp_char!=' ') {
				temp_char_string[temp_col_cur]=temp_char;
				temp_col_cur++;
				}
				else if (temp_cur>0) {
					temp_int=temp_char_string;

				}


			}
			temp_cur=0;
			cout<<endl;

		}
      }

      system("pause");

      return 0;    

}*/