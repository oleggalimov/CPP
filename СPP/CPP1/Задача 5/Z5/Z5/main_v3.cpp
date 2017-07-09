/*������ �5. ���������� ������� - �� ������, ������������������ ��������� ������ �� �������.
������� �� ������������ L ���������� ������, ������� �� �������� n*n,
������ ����������� �������, ����������� �� �� ����������� ����������� ��������� ������. � ������ ��������� � ������������ ������ ����������� ������ ������ ���������.

���������: ���������������� ������� � ���������� �������, � ������� ��� �������� ���� ������� ��������� (�������� ���� ���������),
����� ����.

*/


#include <iostream>

#include <fstream>

 

using namespace std;

struct Matrix {
	//�������� ��������� - �������: ������ nXn, ����� �������� arr - �� ����� 20, min -����������� ��������, type - ���
	int n;
	int arr [20][20];
	int min;
	char type;
}; 

void myShakerSort(Matrix *arr, int size)
//�-��� ���������� - ���������� ������������� ���������, �� �� ����������, ������� - �������. 
//���� ��������� ����� - ��������� �� qsort
{
	Matrix buff; //��������� ���������� ��� ����
	for (int i=0;i<size-1;i++) {
		//������� ������
		for (int j = i+1;j<size;j++) { //������ �� ���������� �����
			if (arr[i].min>arr[j].min) {
				buff = arr[i];//����� ������� ���������
				arr[i] = arr[j];//�� ��� ����� ��������� ������
				arr[j] = buff;//�� ����� ������� - �����
				buff;
			}
		}	
		
	}

} 

void printMatrixArray (Matrix *arr,int size) {
	//������� ������ �������
	//������� ����
	int temp=0;
	for (int i=0;i<size;i++) {
		cout<<"����������� ������� �������: "<<arr[i].min<<endl;
		//��������� ����������� �������
		temp=arr[i].n;

		//��������� ����� ��� ������ �������, ������ �� �������
		for (int x=0;x<temp;x++) {

			//��������� ���� ��� ������ ��������
			for (int j=0;j<temp;j++) {
				cout<<arr[i].arr[x][j];
			}
			cout<<endl;
		}
		cout<<endl;
		
	}

} //������

void typeOfMatrix (Matrix arrayOfMatrix [],int n, char lookFor) {
//������� ����������� ���� �������, ���������� � ������ �������� - ��������� ������ ������, ��� ������ � ��� ������� �������

//--------------------������ ����������------------------------------------------------------------------------------------------

	int temp_razm=0;//������ �������
	bool is_top_triangle=true, is_bottom_triangle = true, is_middle_zero=true;//��������, ��� ����� ������� �� ������� �������� 
																				//- �������, ������, ���������
	Matrix *tempMatr = new Matrix [n]; //������ ��� ������
	int tempMatrCounter = 0; //������� ���������� ������

//--------------------------------������ ����-----------------------------------------------------------------------------------------
	//������� ���� �������� ������ 
	for (int i=0;i<n;i++) {
		//��������� ����������� �������
		temp_razm=arrayOfMatrix[i].n;
		//�������� �� �������� ������������ - ���������, ��� ��� �������� ����� ����
		for (int x=0,y=0;(x<temp_razm)&&(y<=temp_razm)&&(is_top_triangle);x++,y++) {
			int z=y;
			while (z<temp_razm-1) {//���� �� ������				
				if (arrayOfMatrix[i].arr[x][z+1]!=0) { //���� ��������� �� ������� ������� - ������� ��� � ������, ������ �������
					is_top_triangle=false;
					break;
				}
				z++;
			}
			
		}
		

		//���������� ���� �� ������� ������������, ���������� ����� ������� �������� ����

		for (int a=1, b=1;(a<temp_razm)&&(b<=temp_razm)&&(is_bottom_triangle);a++,b++) {
		int t=0;
		while (t<b) {				
				if (arrayOfMatrix[i].arr[a][t]!=0) {
					is_bottom_triangle=false;
					break;
				}
				t++;
			}

		}


		//������ �� ��������� ������� � �������, ������� ��� ��� ���?

		for (int c=0;(c<temp_razm)&&(is_middle_zero);c++) {
			if (arrayOfMatrix[i].arr[c][c]!=0) {
				is_middle_zero=false;
				break;
			}
		}

	//��������� ���������� ��������� � ����������� ���� � ��������
		//���������������� - 'b'
		if (is_top_triangle&&(!is_bottom_triangle)&&(!is_middle_zero)) {
			arrayOfMatrix[i].type='b';
			
			if (lookFor=='b') {
			tempMatr[tempMatrCounter]=arrayOfMatrix[i];
			tempMatrCounter++;
			}

		}
		//����������������� - 't'
		else if ((!is_top_triangle)&&(is_bottom_triangle)&&(!is_middle_zero)) {
			arrayOfMatrix[i].type='t';
			if (lookFor=='t') {
			tempMatr[tempMatrCounter]=arrayOfMatrix[i];
			tempMatrCounter++;
			}
		}
		//������������ 'd'
		else if (is_top_triangle&&is_bottom_triangle&&(!is_middle_zero)) {
			arrayOfMatrix[i].type='d';
			
			if (lookFor=='d') {
			tempMatr[tempMatrCounter]=arrayOfMatrix[i];
			tempMatrCounter++;
			}
		}
		//������� 'z'
		else if (is_top_triangle&&is_bottom_triangle&&is_middle_zero) {
			arrayOfMatrix[i].type='z';
			
			if (lookFor=='z') {
			tempMatr[tempMatrCounter]=arrayOfMatrix[i];
			tempMatrCounter++;
			}
		}
		//������� - 'n'
		else {
			arrayOfMatrix[i].type='n';
			if (lookFor=='n') {
			tempMatr[tempMatrCounter]=arrayOfMatrix[i];
			tempMatrCounter++;
			}
		}
		//���������� �����
		is_top_triangle=true;
		is_bottom_triangle=true;
		is_middle_zero=true;

	}
//--------------------------------������ ��������� ����������, ������ ��������� ������������, ������ ������� ���������� � ������-------
	cout<<"�������� ������:"<<tempMatrCounter<<endl;
	if (tempMatrCounter==0) {
	cout<<"������� ��������� ���� �� ����������"<<tempMatrCounter<<endl;
	} else {
		//printMatrixArray(tempMatr,tempMatrCounter);//������ �� ���������
		myShakerSort(tempMatr,tempMatrCounter); //����������
		printMatrixArray(tempMatr,tempMatrCounter); //������
	}

} 

int main () {
      //������ ������
      setlocale(LC_ALL,"Russian");
      //������� ������ ��������� ������
      ifstream ifs("matrix.txt");
	  Matrix *m = new Matrix [10];//������ ��� ������, �������� - 10
	  int matrix_counter=0;//������� ������
	  
 
      //���������, ��� ���� ��������

      if (ifs.fail()) {

            cout <<"�� ������� ������� ����, ��������� ����" << endl;

            system ("Pause");

            return -1;

      } else {
		  
		  int temp,counter_n=0; //���������� ��� ��������� �������, ��������� �� ������� � ������ ������� ��������������
		  int min;//����������� �������� �������

		  while (!ifs.eof()) {
			  //���� �� ������ ���� �� ��������� �� ������� ������ ��� ����� �����
			  while (ifs.peek()!='\n' && (ifs.peek()!=-1)) { //ifs.peek() - ��������� �� ��������� �������, �� ������� ������ � �����
				  if (counter_n==0) {
				  min=ifs.peek();
				  }
			  ifs>>temp;
			  m[matrix_counter].arr[0][counter_n]=temp;//����� ������ ������ ������� �� ���������
			  cout<<temp; //������� �� �����
			  if (temp<min) {
				min=temp; //��������� �������
			  }
			  counter_n++;//���������� �� ������ ����
			  }
			  if (counter_n!=0) {//���������� �������, ���� ���-�� ������ �����, ����� - ������ ���� ������ ��� ���������� �� ������� ������ ��� ����� �����
			  cout<<endl;
			  for (int i=0;i<counter_n-1;i++) {
				for (int j=0;j<counter_n;j++) {
					ifs>>temp;
					m[matrix_counter].arr[i+1][j]=temp;
					cout<<temp;
					if (temp<min) {
						min=temp;//��� �� ��������� �������, ���� �����
					}
				}
				cout<<endl;
			  }
			  m[matrix_counter].n=counter_n;//��������� ������ �������
			  m[matrix_counter].min=min;//��������� �������
			  matrix_counter++;//��������� ������� ������
			  
			  
			  //������� ������ � �������
					cout<<"������ �������: "<<m[matrix_counter-1].n<<"X"<<counter_n<<", ����������� ������� - "<<
						m[matrix_counter-1].min<<
						" ���������� ������:"<<matrix_counter<<
						endl;
					//cout<<"\n��������� �������: "<<ifs.peek();
					
					counter_n=0;
			  }
			  else if (ifs.peek()==-1) {//�������, ���� ����� � ����� ����� - ������� ��� � ������
				break;
			  }
			  else if (ifs.peek()=='\n') {
				   ifs.get();//���� ������ ������  - ��������� ���� ����� �������� ������ � �����
			   }
			  
			  
		  }

      }
	  //
	  cout<<endl<<"==========================================������� ���������������� (\'b\') �������:============================"<<endl<<endl;
	  typeOfMatrix(m,matrix_counter,'b');

      system("pause");

      return 0;    

}