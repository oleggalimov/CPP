/*
Задание 6: сведения о веществе: название (строка), удельный вес (вещественное число), 
свойство проводимости (одно из значений: 0 - нет проводимости, 1-полупроводник, 2- проводник),
по сведениям о некотором количестве (не более N) веществ получить список веществ заданной проводимости, отсортировать по 
возрастанию удельных весов. если нужных вещест нет - выдать сообщение. 
*/

#include <iostream>
#include <fstream>

using namespace std;



struct material  {
	//структура - вещество
	char name [50];//название
	int provodnik;//свойство проводимости
	float udVes;//удельный вес
};
void vibor (material mat [], int n,int t) {
	material *temp = new material[n];
	int counter=0;
	//отбираем нужные
	for (int i=0;i<n;i++) {
		if (mat[i].provodnik==t) {
			temp[counter]=mat[i];
			counter++;
		}
	}
	
	if (counter>0) {
		cout<<"выбрано элементов: "<<counter<<endl;

		material buff; //временная переменная для своп
		for (int i=0;i<counter-1;i++) {	//главный проход
		
			for (int j = i+1;j<counter;j++) { //проход по оставшейся части
				if (temp[i].udVes>temp[j].udVes) {
					buff = temp[i];//левый элемент сохраняем
					temp[i] = temp[j];//на его место записывем правый
					temp[j] = buff;//на место правого - левый
					buff;
				}
			}
		}
	for (int i=0;i<counter;i++) {
		cout<<"Материал: "<<temp[i].name<<endl;
		cout<<"	- признак проводимости: "<<temp[i].provodnik<<endl;
		cout<<"	- удельный вес: "<<temp[i].udVes<<endl;
	}

	} else {
		cout<<"Элементы заданного типа не найдены"<<endl;
	}
}
int main () {
		//Задаем локаль
      setlocale(LC_ALL,"Russian");
      //создаем объект файлового потока
      ifstream ifs;
     
	  int counter=0;//переменная счетчик веществ
	  material materials[25];//массив веществ
      ifs.open("materials.txt"); //открываем файл
	  if (ifs.fail())  {
		  cout<<"Ошибка открытия файла"<<endl;
		  return -1;
	  } else {
		  
		  
		  
		  float temp;
		  while (!ifs.eof()) {
			  ifs.getline(materials[counter].name, 50);//читаем название
			  cout<<materials[counter].name<<endl;//выводим название для проверки
			  ifs>>materials[counter].udVes;//ГРАБЛИ! Разделитель для вещественных чисел д.б. точка!
			  cout<<materials[counter].udVes<<endl;//выводим число
			  ifs >> materials[counter].provodnik;//записываем свойство проводимости
			  cout<<materials[counter].provodnik<<endl; //выводим свойство проводимости
			  counter++;//увеличиваем счетчик
			  ifs.get();//ГРАБЛИ! оператор >>считвает очередное значение, но курсор в файле остается в строке,
						//т.е. курсор в файле остается перед знаком '\n', для этог очитаем его в пустоту, сдвигая курсор.
		  }
	  }
	 
	  cout<<endl<<"обработано веществ: "<<counter<<endl;
	  if (counter>1) {//поиск имеет смысл только если веществ больше одного
		  int provod=-1;//критерий для поиска
		  bool exit=false;
		  cout<<"введите проводимость (0,1,2):"<<endl;
		
		  do  {
			  cin>>provod;
			  if ((provod>(-1))&&(provod<3)) {
				exit=true;
			  } else {
				  cout<<"Значение некорректное!"<<endl;
				 }
		  } while (!exit);

		  vibor(materials,counter,provod);
	  }
	  else {
	  cout<<"Слишком мало веществ для поиска!"<<endl;
	  }
	  
	  system ("pause");
	  return 0;

}