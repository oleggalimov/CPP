#include <iostream>
#include <string>
using namespace std;


#define MALE false
#define FEMALE true

class Person
{
    string name;
    int age;
    bool gender;
    
    
    // ���������� ������ ����� ������ ������������
    // ���� ����������� ������ �������� ��-���������
    Person(string Name = "NoName", int Age = 0, bool Gender = MALE)
        : name(Name), age(Age), gender(Gender) // ����� ���������� ������������� �����
    {}
    
    void print()
    {
        if (gender == FEMALE)
            cout << "Girl ";
        else
            cout << "Boy ";
        cout << name << ", " << age << " years old\n";
    }
};


int main() 
{
    // ����� ������������ �������
    Person girl("Tanya", 19, FEMALE);
    // ����� ������������ ��������
    Person boy("Dima", 20, MALE), 
        boy2,           // ����� ������������ ��-��������� (��� ����������)
        girl2("Sasha"); // ������ ������ ���, ��������� ���� - ��-���������

    boy.print();
    girl.print();
    boy2.print();
    girl2.print();
    system("pause");
    return 0;
}