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
		  char tempReadedVal;//��������� ���������� ��� ������
		  int counter_n=0;//������� ����������� �������
		  int tempArray[255][255];
		  int columnCounterCursor=0;//��������� ���������� ��� ������������ �� �������� �������
		  
		  
		  //������� ���� ��� ������ �����, ������ ���� �� ����������

		  while (!ifs.eof()) {
			//������ ������ ������, ���������� ����������� �������  
			  while ((tempReadedVal=ifs.get())!='\n') {
				  //������ ������ ������
				  if (tempReadedVal!=' ') {
					  tempArray[0][counter_n]=tempReadedVal;
					  counter_n++;
				  }
				  //������ ���������� ������
				  //��������� ������
				  
				}
			  tempReadedVal=0;
			  for (int i=1;i<counter_n;i++) {
				  columnCounterCursor=0;
					while (((tempReadedVal=ifs.get())!='\n') && (!ifs.eof())) {
						if (tempReadedVal!=' ') {
						tempArray[i][columnCounterCursor]=tempReadedVal;
						columnCounterCursor++;
						}
					}
				  
				  }

			  if (counter_n!=0) {
			  cout<<"����������� �������: "<<counter_n<<"X"<<counter_n<<endl;
			  printArray(tempArray,counter_n);
			  counter_n=0;
			  }

			  
		  }
      }

      system("pause");

      return 0;    

}*/