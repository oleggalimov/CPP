#include <iostream>

#include <fstream>

 

using namespace std;

 

int StringTrimmer (char input[], int TempStringLength) { //������� ��� ������ ��������

      if (TempStringLength==0) { //���� ������, ���� ����

            return 0;

      }

     

      char *internal_array = new char [TempStringLength];

      internal_array=input;

      char *outp = new char [TempStringLength];

     

      //������� ������������ ������ ������, ���������� �������

      int i=0; //��������� �������� ��������� ��� ���������� ������

      int y=0; //��������� �������� ��������� ��� ������������ ������

      int counter=0; //������� ��������

      char tempReadedChar;//��������� ���������� ��� �������� ������

     

      while (i<TempStringLength) {//������� ���� �� ����� ������

            while (input[i]==' '&&i<TempStringLength) {//���� �� ������ ���� �� ������ �� ������ �����, ������ �������

            i++;

            counter++;

            }

            while ((tempReadedChar=internal_array[i])!=' '&& i<TempStringLength) { //������ �����

                 

                  outp[y]=tempReadedChar;

                  i++;

                  y++;

            }

            outp[y]=' ';//��������� ������

            y++;//�������� ������ ������ ��� ��������� �����

      }

      outp[y-1]='\0';

      if (outp[y-2]==' ') {

            outp[y-2]='\0';

      }

     

      cout<<"������������� ������: |";

      int iterator=0;

      char temp;

      while ((temp=outp[iterator])!=0) {

            cout << temp;

            iterator++;

      }

      cout<<"|������� ��������: "<<counter<<endl;

      return 0;

}

 

int main () {

      char TempString [255];

      //������ ������

      setlocale(LC_ALL,"Russian");

 

      //������� ������ ��������� ������

      ifstream ifs;

 

      //��������� ����

      ifs.open("FileWithSpaces.txt");

 

      //���������, ��� ���� ��������

      if (ifs.fail()) {

            cout <<"�� ������� ������� ����, ��������� ����" << endl;

            system ("Pause");

            return -1;

      } else {

            while (!ifs.eof()) {

                  TempString[0]='\n';

                  ifs.getline(TempString,255);

                  cout <<"�������� ������: " <<"|" << TempString <<"|"<<endl;

                  StringTrimmer(TempString,strlen(TempString));

            }

      }

      system("pause");

      return 0;

     

}