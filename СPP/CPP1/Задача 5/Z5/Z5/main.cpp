/*#include <iostream>

#include <fstream>

 

using namespace std;
//функция печати массива
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
      //Задаем локаль
      setlocale(LC_ALL,"Russian");
      //создаем объект файлового потока
      ifstream ifs;
      //открываем файл

      ifs.open("matrix.txt");
	  
 
      //проверяем, что файл открылся

      if (ifs.fail()) {

            cout <<"Не удалось открыть файл, проверьте путь" << endl;

            system ("Pause");

            return -1;

      } else {
		  char tempReadedVal;//временная переменная для чтения
		  int counter_n=0;//счетчик размерности матрицы
		  int tempArray[255][255];
		  int columnCounterCursor=0;//временная переменная для передвижения по колонкам массива
		  
		  
		  //главный цикл для чтения файла, шагаем пока не закончится

		  while (!ifs.eof()) {
			//читаем первую строку, определяем размерность матрицы  
			  while ((tempReadedVal=ifs.get())!='\n') {
				  //читаем первую строку
				  if (tempReadedVal!=' ') {
					  tempArray[0][counter_n]=tempReadedVal;
					  counter_n++;
				  }
				  //читаем оставшиеся строки
				  //заполняем строку
				  
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
			  cout<<"размерность матрицы: "<<counter_n<<"X"<<counter_n<<endl;
			  printArray(tempArray,counter_n);
			  counter_n=0;
			  }

			  
		  }
      }

      system("pause");

      return 0;    

}*/