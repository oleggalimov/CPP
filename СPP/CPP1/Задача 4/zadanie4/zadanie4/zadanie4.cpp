#include <iostream>
#include <fstream>

using namespace std;
 
int sort (int ish [][100],int len) {
	ofstream fout;
	fout.open("log.csv");
	if (fout.fail()) {

		cout<<"не удалось открыть файл логгирования"<<endl;
		return -2;
	}

	int x_word[100],y_word[100]; //временые переменные для хранения слов для сортировки
	int x,y,z,temp;
	x=y=0;
	int column=1;
	for (int rows=0;rows<len-1;rows++) {
		//вычитываем слово из массива на текущей позиции
		for (int qq=1; qq<=ish[rows][0];qq++) {
		   fout<<(char)ish[rows][qq];
		}
		fout<<",";
		//пишем в файл массив до изменения	
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
		
		z=ish[rows][0];//запоминаем длину слова, которе ищем
		temp=ish[rows][1];//запоминаем первую букву
		
		for (int j=rows+1;j<len;j++) {//идем по оставшейся части массива

			if (temp>ish[j][1]) {//если слово начинается на букву с меньшим индексом - меняем местами слова
				//читаем слово из исходного массива в x_word
				{
				int temp_length_r=ish[j][0];
				for (int i=0;i<=temp_length_r;i++) {
						x_word[i]=ish[j][i];
				}
				//записываем на его место слово, с которым сравнивали
				for (int i=0;i<=z;i++) {
						ish[j][i]=ish[rows][i];
				}
				//записиваем слово из буфера на исходную позицию
				for (int i=0;i<=temp_length_r;i++) {
						ish[rows][i]=x_word[i];
				}
				z=ish[rows][0];
				temp=ish[rows][1];
				}
			}
			else if (temp==ish[j][1]) {
				//слова начинаются на одну букву
				//
				bool eqv=true;//признак эквивалентности двух слов
				if (z<ish[j][0]) {
					//длина исходного слова оказалась меньше, чем найденного
					//идем по нему и сравниваем буквы до первого расхождения
					for (int i=2;i<=z;i++) {
						if (ish[j][i]<ish[rows][i]) {
							//встретили расхождение - ломаем признак
							eqv=false;
							//меняем местами
							//читаем слово из исходного массива в x_word
							{
							int temp_length_r=ish[j][0];
							for (int i=0;i<=temp_length_r;i++) {
									x_word[i]=ish[j][i];
							}
							//записываем на его место слово, с которым сравнивали
							for (int i=0;i<=z;i++) {
									ish[j][i]=ish[rows][i];
							}
							//записиваем слово из буфера на исходную позицию
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
							//буквы неэквивалентны, но слова менять не надо
						}
							
					}
					//прошлись по слову используя длину z
					//перезаписались или получилось так, что исходное слово помещается в найденном (например арб в арбуз)
					//не меняем местами
				}
				else {
					//или длина найденного слова меньше, или все равно
					bool eqv=true;//признак эквивалентности двух слов
					int temp_z = ish[j][0];
					for (int i=2;i<=temp_z;i++) {
						if (ish[j][i]<ish[rows][i]) {
							//встретили расхождение - ломаем признак
							eqv=false;
							//меняем местами

							//читаем слово из исходного массива в x_word
							{
							int temp_length_r=ish[j][0];
							for (int i=0;i<=temp_length_r;i++) {
									x_word[i]=ish[j][i];
							}
							//записываем на его место слово, с которым сравнивали
							for (int i=0;i<=z;i++) {
									ish[j][i]=ish[rows][i];
							}
							//записиваем слово из буфера на исходную позицию
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
							//буквы неэквивалентны, но слова менять не надо
						}
							
					}
					//прошлись по слову используя длину найденного слова
					//перезаписались или получилось так, что найденное слово помещается в исходном (например в арбуз найденное арб)
					//меняем местами
					if (eqv) //флаг указывает что слова частично схожи
					{
							int temp_length_r=ish[j][0];
							for (int i=0;i<=temp_length_r;i++) {
									x_word[i]=ish[j][i];
							}
							//записываем на его место слово, с которым сравнивали
							for (int i=0;i<=z;i++) {
									ish[j][i]=ish[rows][i];
							}
							//записиваем слово из буфера на исходную позицию
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
 

      for (int z=0;z<len;z++) {//идем по строкам
		  for (int j=0;((temp=ish[z][j])!=0)&&(!not_unic);j++) {//идем по столбцам, берем букву (после первого двойного вхождения идем на следующую строчку)...
			  while ((temp1=ish[z][y])!=0) {//....и ищем ее в оставшейся части
				  if (temp==temp1) {
					  counter++;
					  }
				  y++;
				  }
			 // cout<<(char)temp<<' '<<counter;//выводим букву и сколько она встречается
			  if (counter>1) {//если буква встречается больше 2 - х раз, то поднимаем флаг
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
	  cout<<endl<<"Количество слов после отсеивания: "<<unic_row<<endl; 
	  int a=0;
	  for (int qq=0; qq<unic_row;qq++) {
		  cout<<"Позиция №"<<qq<<" : ";
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
	  cout<< "Сортируем"<<endl;
      sort(unic,unic_row-1);
	  
      return 0; 

           

}
 

int main () {

      setlocale(LC_ALL,"Russian");

      //const int r[]={32,59,46,44,58,45,33,63};//разделители

      int words [1024][100];//массив слов

     

      int k=0;//строка массива word

      int v=1;//столбец массива word, нулевое место зарезервировано под длину слова

     

 

      int n;//временная переменная для чтения из файла

 

 

      //создаем объект файлового потока

      ifstream ifs;

      //открываем файл

      ifs.open("test.txt");

      if (ifs.fail()) {

            cout <<"Не удалось открыть файл, проверьте путь" << endl;

            system ("Pause");

            return -1;

      } else {

            while (!ifs.eof()) {

                  n=ifs.get();

                  while ((n==32 || n==59 || n==46 || n==44 || n==58 || n==45 || n==45 || n==33 || n==63 )&& n!=(-1)) {//пропускаем разделители

                        n=ifs.get();

                  }

                  while (n!=32 && n!=59 && n!=46 && n!=44 && n!=58 && n!=45 && n!=45 && n!=33 && n!=63 && n!=(-1)) {//читаем слово
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
			cout<<endl<<"Общее количество слов: "<<k<<endl; 
            unificator (words,k);

            system ("pause");

      }

}