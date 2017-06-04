#include <iostream>

#include <fstream>

 

using namespace std;

 

int StringTrimmer (char input[], int TempStringLength) { //функция для сжатия пробелов

      if (TempStringLength==0) { //ноль пришел, ноль ушел

            return 0;

      }

     

      char *internal_array = new char [TempStringLength];

      internal_array=input;

      char *outp = new char [TempStringLength];

     

      //заводим динамический массив длинны, переданной функции

      int i=0; //указатель текущего положения для ПОЛУЧЕННОЙ строки

      int y=0; //указатель текущего положения для ЗАПИСЫВАЕМОЙ строки

      int counter=0; //счетчик пробелов

      char tempReadedChar;//временная переменная для читаемой строки

     

      while (i<TempStringLength) {//главный цикл до конца строки

            while (input[i]==' '&&i<TempStringLength) {//идем по строке пока не дойдем до первой буквы, считая пробелы

            i++;

            counter++;

            }

            while ((tempReadedChar=internal_array[i])!=' '&& i<TempStringLength) { //читаем буквы

                 

                  outp[y]=tempReadedChar;

                  i++;

                  y++;

            }

            outp[y]=' ';//добавляем пробел

            y++;//сдвигаем курсор вправо для следующей буквы

      }

      outp[y-1]='\0';

      if (outp[y-2]==' ') {

            outp[y-2]='\0';

      }

     

      cout<<"Подстриженная строка: |";

      int iterator=0;

      char temp;

      while ((temp=outp[iterator])!=0) {

            cout << temp;

            iterator++;

      }

      cout<<"|Удалено пробелов: "<<counter<<endl;

      return 0;

}

 

int main () {

      char TempString [255];

      //Задаем локаль

      setlocale(LC_ALL,"Russian");

 

      //создаем объект файлового потока

      ifstream ifs;

 

      //открываем файл

      ifs.open("FileWithSpaces.txt");

 

      //проверяем, что файл открылся

      if (ifs.fail()) {

            cout <<"Не удалось открыть файл, проверьте путь" << endl;

            system ("Pause");

            return -1;

      } else {

            while (!ifs.eof()) {

                  TempString[0]='\n';

                  ifs.getline(TempString,255);

                  cout <<"Исходная строка: " <<"|" << TempString <<"|"<<endl;

                  StringTrimmer(TempString,strlen(TempString));

            }

      }

      system("pause");

      return 0;

     

}