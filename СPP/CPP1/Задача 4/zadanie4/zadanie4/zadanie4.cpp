#include <iostream>
#include <fstream>

using namespace std;
 
int sort (int ish [][100],int len) {
	ofstream fout;
	fout.open("log.csv");
	if (fout.fail()) {

		cout<<"�� ������� ������� ���� ������������"<<endl;
		return -2;
	}

	int x_word[100],y_word[100]; //�������� ���������� ��� �������� ���� ��� ����������
	int x,y,z,temp;
	x=y=0;
	int column=1;
	for (int rows=0;rows<len-1;rows++) {
		//���������� ����� �� ������� �� ������� �������
		for (int qq=1; qq<=ish[rows][0];qq++) {
		   fout<<(char)ish[rows][qq];
		}
		fout<<",";
		//����� � ���� ������ �� ���������	
		for (int qq=0; qq<len;qq++) {
		  
		  int b=ish[qq][0];
		  int a=1;
		  while (a<=b) {
			  fout<<(char)ish[qq][a];
			  a++;
		  }
		  fout<<",";
		}
		fout<<endl;
		
		z=ish[rows][0];//���������� ����� �����, ������ ����
		temp=ish[rows][1];//���������� ������ �����
		
		for (int j=rows+1;j<len;j++) {//���� �� ���������� ����� �������

			if (temp>ish[j][1]) {//���� ����� ���������� �� ����� � ������� �������� - ������ ������� �����
				//������ ����� �� ��������� ������� � x_word
				{
				int temp_length_r=ish[j][0];
				for (int i=0;i<=temp_length_r;i++) {
						x_word[i]=ish[j][i];
				}
				//���������� �� ��� ����� �����, � ������� ����������
				for (int i=0;i<=z;i++) {
						ish[j][i]=ish[rows][i];
				}
				//���������� ����� �� ������ �� �������� �������
				for (int i=0;i<=temp_length_r;i++) {
						ish[rows][i]=x_word[i];
				}
				z=ish[rows][0];
				temp=ish[rows][1];
				}
			}
			else if (temp==ish[j][1]) {
				//����� ���������� �� ���� �����
				//
				bool eqv=true;//������� ��������������� ���� ����
				if (z<ish[j][0]) {
					//����� ��������� ����� ��������� ������, ��� ����������
					//���� �� ���� � ���������� ����� �� ������� �����������
					for (int i=2;i<=z;i++) {
						if (ish[j][i]<ish[rows][i]) {
							//��������� ����������� - ������ �������
							eqv=false;
							//������ �������
							//������ ����� �� ��������� ������� � x_word
							{
							int temp_length_r=ish[j][0];
							for (int i=0;i<=temp_length_r;i++) {
									x_word[i]=ish[j][i];
							}
							//���������� �� ��� ����� �����, � ������� ����������
							for (int i=0;i<=z;i++) {
									ish[j][i]=ish[rows][i];
							}
							//���������� ����� �� ������ �� �������� �������
							for (int i=0;i<=temp_length_r;i++) {
									ish[rows][i]=x_word[i];
							}
							z=ish[rows][0];
							temp=ish[rows][1];
							}
						break;
						}
						else if (ish[j][i]>ish[rows][i]) {
							eqv=false;
							break;
							//����� ��������������, �� ����� ������ �� ����
						}
							
					}
					//�������� �� ����� ��������� ����� z
					//�������������� ��� ���������� ���, ��� �������� ����� ���������� � ��������� (�������� ��� � �����)
					//�� ������ �������
				}
				else {
					//��� ����� ���������� ����� ������, ��� ��� �����
					bool eqv=true;//������� ��������������� ���� ����
					int temp_z = ish[j][0];
					for (int i=2;i<=temp_z;i++) {
						if (ish[j][i]<ish[rows][i]) {
							//��������� ����������� - ������ �������
							eqv=false;
							//������ �������

							//������ ����� �� ��������� ������� � x_word
							{
							int temp_length_r=ish[j][0];
							for (int i=0;i<=temp_length_r;i++) {
									x_word[i]=ish[j][i];
							}
							//���������� �� ��� ����� �����, � ������� ����������
							for (int i=0;i<=z;i++) {
									ish[j][i]=ish[rows][i];
							}
							//���������� ����� �� ������ �� �������� �������
							for (int i=0;i<=temp_length_r;i++) {
									ish[rows][i]=x_word[i];
							}
							z=ish[rows][0];
							temp=ish[rows][1];
							}

							break;
						} else if (ish[j][i]>ish[rows][i]) {
							eqv=false;
							break;
							//����� ��������������, �� ����� ������ �� ����
						}
							
					}
					//�������� �� ����� ��������� ����� ���������� �����
					//�������������� ��� ���������� ���, ��� ��������� ����� ���������� � �������� (�������� � ����� ��������� ���)
					//������ �������
					if (eqv) //���� ��������� ��� ����� �������� �����
					{
							int temp_length_r=ish[j][0];
							for (int i=0;i<=temp_length_r;i++) {
									x_word[i]=ish[j][i];
							}
							//���������� �� ��� ����� �����, � ������� ����������
							for (int i=0;i<=z;i++) {
									ish[j][i]=ish[rows][i];
							}
							//���������� ����� �� ������ �� �������� �������
							for (int i=0;i<=temp_length_r;i++) {
									ish[rows][i]=x_word[i];
							}
							z=ish[rows][0];
							temp=ish[rows][1];
							}

				}
				
			}
			
		}
		
		
	}

	
	  for (int qq=0; qq<len;qq++) {
		  
		  int b=ish[qq][0];
		  int a=1;
		  while (a<=b) {
			  cout<<(char)ish[qq][a];
			  a++;
		  }
		  cout<<endl;
	  }

return 0;
}
int unificator (int ish [][100],int len) {

      int temp=0;
      int temp1=0;
      int counter=0;
      int y=0;
      bool not_unic=false;
	  int unic [1024][100];
	  int unic_row=0;
 

      for (int z=0;z<len;z++) {//���� �� �������
		  for (int j=0;((temp=ish[z][j])!=0)&&(!not_unic);j++) {//���� �� ��������, ����� ����� (����� ������� �������� ��������� ���� �� ��������� �������)...
			  while ((temp1=ish[z][y])!=0) {//....� ���� �� � ���������� �����
				  if (temp==temp1) {
					  counter++;
					  }
				  y++;
				  }
			 // cout<<(char)temp<<' '<<counter;//������� ����� � ������� ��� �����������
			  if (counter>1) {//���� ����� ����������� ������ 2 - � ���, �� ��������� ����
				  not_unic=true;
				  }
			  y=0;
			  counter=0;
		  }
		  
		  if (!not_unic) {
				int a=0;
				while ((temp=ish[z][a])!=0){
					unic[unic_row][a]=temp;
					a++;
				}
				unic[unic_row][a]='\0';
				unic_row++;
			}			
            not_unic=false;
			temp=temp1=0;

      }
	  unic_row--;
	  cout<<endl<<"���������� ���� ����� ����������: "<<unic_row<<endl; 
	  int a=0;
	  for (int qq=0; qq<unic_row;qq++) {
		  cout<<"������� �"<<qq<<" : ";
		  while ((temp=unic[qq][a])!=0) {
			  if (a==0) {
					cout<<temp;
			  }
			  else {
					cout<<(char)temp;
			  }
				
			  a++;
		  }
		  a=0;
		  cout<<endl;
	  }
	  cout<<endl;
	  cout<< "���������"<<endl;
      sort(unic,unic_row-1);
	  
      return 0; 

           

}
 

int main () {

      setlocale(LC_ALL,"Russian");

      //const int r[]={32,59,46,44,58,45,33,63};//�����������

      int words [1024][100];//������ ����

     

      int k=0;//������ ������� word

      int v=1;//������� ������� word, ������� ����� ��������������� ��� ����� �����

     

 

      int n;//��������� ���������� ��� ������ �� �����

 

 

      //������� ������ ��������� ������

      ifstream ifs;

      //��������� ����

      ifs.open("test.txt");

      if (ifs.fail()) {

            cout <<"�� ������� ������� ����, ��������� ����" << endl;

            system ("Pause");

            return -1;

      } else {

            while (!ifs.eof()) {

                  n=ifs.get();

                  while ((n==32 || n==59 || n==46 || n==44 || n==58 || n==45 || n==45 || n==33 || n==63 )&& n!=(-1)) {//���������� �����������

                        n=ifs.get();

                  }

                  while (n!=32 && n!=59 && n!=46 && n!=44 && n!=58 && n!=45 && n!=45 && n!=33 && n!=63 && n!=(-1)) {//������ �����
					  if ((96<n)&&(n<123)) {
						  words [k][v]=(n-32);
						  v++;
						  n=ifs.get();
					  }
					  else{  
						  words [k][v]=n;
						  v++;
						  n=ifs.get();
					  }

                        

                  }

                  words [k][v]='\0';
				  words [k][0]=v-1;

                  v=1;

                  k++;

            }

            v=1;

            for (int i=0;i<k;i++) {
				cout<<words[i][0];
                  while (words[i][v]) {

                        cout<<(char)words[i][v];

                        v++;

                  }

                  cout<<endl;

                  v=1;

            }
			cout<<endl<<"����� ���������� ����: "<<k<<endl; 
            unificator (words,k);

            system ("pause");

      }

}