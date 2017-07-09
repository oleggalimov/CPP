/*Задача №5. Квадратная матрица - ее размер, последовательность элементов строка за строкой.
Выбрать из совокупности L квадратных матриц, размера не большего n*n,
нижние треугольные матрицы, упорядочить их по возрастанию минимальных элементов матриц. В случае отсуствия в совокупности нижних треугольных матриц выдать сообщение.

УТОЧНЕНИЕ: Нижнетреугольная матрица — квадратная матрица, в которой все элементы выше главной диагонали (исключая саму диагональ),
равны нулю.

*/


#include <iostream>

#include <fstream>

 

using namespace std;

struct Matrix {
	//описание структуры - матрица: размер nXn, набор значений arr - не более 20, min -минимальное значение, type - тип
	int n;
	int arr [20][20];
	int min;
	char type;
}; 

void myShakerSort(Matrix *arr, int size)
//ф-ция сортировки - изначально планировалась шейкреная, но не получилось, поэтому - пузырек. 
//ЕСли останется время - исправить на qsort
{
	Matrix buff; //временная переменная для своп
	for (int i=0;i<size-1;i++) {
		//главный проход
		for (int j = i+1;j<size;j++) { //проход по оставшейся части
			if (arr[i].min>arr[j].min) {
				buff = arr[i];//левый элемент сохраняем
				arr[i] = arr[j];//на его место записывем правый
				arr[j] = buff;//на место правого - левый
				buff;
			}
		}	
		
	}

} 

void printMatrixArray (Matrix *arr,int size) {
	//функция печати массива
	//главный цикл
	int temp=0;
	for (int i=0;i<size;i++) {
		cout<<"Минимальный элемент матрицы: "<<arr[i].min<<endl;
		//сохраняем размерность матрицы
		temp=arr[i].n;

		//вложенные циклы для печати матрицы, проход по строкам
		for (int x=0;x<temp;x++) {

			//вложенный цикл для печати столбцов
			for (int j=0;j<temp;j++) {
				cout<<arr[i].arr[x][j];
			}
			cout<<endl;
		}
		cout<<endl;
		
	}

} //печать

void typeOfMatrix (Matrix arrayOfMatrix [],int n, char lookFor) {
//функция определения типа матрицы, сортировки и печати значений - принимает массив матриц, его размер и тип искомой матрицы

//--------------------секция переменных------------------------------------------------------------------------------------------

	int temp_razm=0;//размер матрицы
	bool is_top_triangle=true, is_bottom_triangle = true, is_middle_zero=true;//признаки, что часть состоит из нулевых значений 
																				//- верхняя, нижняя, диагональ
	Matrix *tempMatr = new Matrix [n]; //массив для матриц
	int tempMatrCounter = 0; //счетчик количества матриц

//--------------------------------секция кода-----------------------------------------------------------------------------------------
	//главный цикл перебора матриц 
	for (int i=0;i<n;i++) {
		//извлекаем размерность матрицы
		temp_razm=arrayOfMatrix[i].n;
		//проходим по верхнему треугольнику - проверяем, что все элементы равны нулю
		for (int x=0,y=0;(x<temp_razm)&&(y<=temp_razm)&&(is_top_triangle);x++,y++) {
			int z=y;
			while (z<temp_razm-1) {//идем по строке				
				if (arrayOfMatrix[i].arr[x][z+1]!=0) { //если встретили не нулевой элемент - бросаем все и уходим, ставим признак
					is_top_triangle=false;
					break;
				}
				z++;
			}
			
		}
		

		//аналогично идем по нижнему треугольнику, достаточно найти элемент неравный нулю

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


		//шагаем по диагонали матрицы и смотрим, нулевая она или нет?

		for (int c=0;(c<temp_razm)&&(is_middle_zero);c++) {
			if (arrayOfMatrix[i].arr[c][c]!=0) {
				is_middle_zero=false;
				break;
			}
		}

	//проверяем комбинации признаков и проставляем типы в матрицах
		//нижнетреугольная - 'b'
		if (is_top_triangle&&(!is_bottom_triangle)&&(!is_middle_zero)) {
			arrayOfMatrix[i].type='b';
			
			if (lookFor=='b') {
			tempMatr[tempMatrCounter]=arrayOfMatrix[i];
			tempMatrCounter++;
			}

		}
		//верхнетреугольная - 't'
		else if ((!is_top_triangle)&&(is_bottom_triangle)&&(!is_middle_zero)) {
			arrayOfMatrix[i].type='t';
			if (lookFor=='t') {
			tempMatr[tempMatrCounter]=arrayOfMatrix[i];
			tempMatrCounter++;
			}
		}
		//диагональная 'd'
		else if (is_top_triangle&&is_bottom_triangle&&(!is_middle_zero)) {
			arrayOfMatrix[i].type='d';
			
			if (lookFor=='d') {
			tempMatr[tempMatrCounter]=arrayOfMatrix[i];
			tempMatrCounter++;
			}
		}
		//нулевая 'z'
		else if (is_top_triangle&&is_bottom_triangle&&is_middle_zero) {
			arrayOfMatrix[i].type='z';
			
			if (lookFor=='z') {
			tempMatr[tempMatrCounter]=arrayOfMatrix[i];
			tempMatrCounter++;
			}
		}
		//обычная - 'n'
		else {
			arrayOfMatrix[i].type='n';
			if (lookFor=='n') {
			tempMatr[tempMatrCounter]=arrayOfMatrix[i];
			tempMatrCounter++;
			}
		}
		//сбрасываем флаги
		is_top_triangle=true;
		is_bottom_triangle=true;
		is_middle_zero=true;

	}
//--------------------------------секция обработки результата, вывода сообщения пользователю, вызова функции сортировки и печати-------
	cout<<"Отобрано матриц:"<<tempMatrCounter<<endl;
	if (tempMatrCounter==0) {
	cout<<"матрицы заданного типа не обнаружены"<<tempMatrCounter<<endl;
	} else {
		//printMatrixArray(tempMatr,tempMatrCounter);//печать до обработки
		myShakerSort(tempMatr,tempMatrCounter); //сортировка
		printMatrixArray(tempMatr,tempMatrCounter); //печать
	}

} 

int main () {
      //Задаем локаль
      setlocale(LC_ALL,"Russian");
      //создаем объект файлового потока
      ifstream ifs("matrix.txt");
	  Matrix *m = new Matrix [10];//массив для матриц, максимум - 10
	  int matrix_counter=0;//счетчик матриц
	  
 
      //проверяем, что файл открылся

      if (ifs.fail()) {

            cout <<"Не удалось открыть файл, проверьте путь" << endl;

            system ("Pause");

            return -1;

      } else {
		  
		  int temp,counter_n=0; //переменная для перескока позиции, указатель на позицию в строке матрицы соответственно
		  int min;//минимальное значение матрицы

		  while (!ifs.eof()) {
			  //идем по строке пока не наткнемся на перевод строки или конец файла
			  while (ifs.peek()!='\n' && (ifs.peek()!=-1)) { //ifs.peek() - указатель на следующий элемент, не двигает курсор в файле
				  if (counter_n==0) {
				  min=ifs.peek();
				  }
			  ifs>>temp;
			  m[matrix_counter].arr[0][counter_n]=temp;//пишем первую строку матрицы из структуры
			  cout<<temp; //выводим на экран
			  if (temp<min) {
				min=temp; //обновляем минимум
			  }
			  counter_n++;//спускаемся на строку ниже
			  }
			  if (counter_n!=0) {//дописываем остаток, если что-то писали ранее, иначе - попали сюда потому что наткнулись на перевод строки или конец файла
			  cout<<endl;
			  for (int i=0;i<counter_n-1;i++) {
				for (int j=0;j<counter_n;j++) {
					ifs>>temp;
					m[matrix_counter].arr[i+1][j]=temp;
					cout<<temp;
					if (temp<min) {
						min=temp;//так же обновляем минимум, если нашли
					}
				}
				cout<<endl;
			  }
			  m[matrix_counter].n=counter_n;//фиксируем размер матрицы
			  m[matrix_counter].min=min;//фиксируем минимум
			  matrix_counter++;//добавляем счетчик матриц
			  
			  
			  //выводим данные о матрице
					cout<<"Размер матрицы: "<<m[matrix_counter-1].n<<"X"<<counter_n<<", минимальный элемент - "<<
						m[matrix_counter-1].min<<
						" Обработано матриц:"<<matrix_counter<<
						endl;
					//cout<<"\nСледующий элемент: "<<ifs.peek();
					
					counter_n=0;
			  }
			  else if (ifs.peek()==-1) {//смотрим, если стоим у конца файла - бросаем все и уходим
				break;
			  }
			  else if (ifs.peek()=='\n') {
				   ifs.get();//если первод строки  - считываем знак чтобы сдвинуть курсор в файле
			   }
			  
			  
		  }

      }
	  //
	  cout<<endl<<"==========================================Печатаю нижнетреугольные (\'b\') матрицы:============================"<<endl<<endl;
	  typeOfMatrix(m,matrix_counter,'b');

      system("pause");

      return 0;    

}