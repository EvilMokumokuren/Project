/* Колпакова Е., Lesson 7, Visual Studio Code
1. Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: для инициализации массива (типа float), печати его на экран и подсчета количества 
отрицательных и положительных элементов. Вызывайте эти 3-и функции из main для работы с массивом.
2. Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и 
возвращает true или false, вывести на экран «true» или «false».
3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком). 
Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
4. * Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. Выделите динамически переменную этого типа. Инициализируйте ее. 
Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл.
5. * Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать)
*/

#include <iostream>
#include <string>
#include <fstream>
#include "mylib.h"

using namespace std;

float* ptrArray;

/* Создайте проект из 2х cpp файлов и заголовочного(main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: для инициализации массива(типа float), печати его на экран и подсчета количества
отрицательных и положительных элементов.Вызывайте эти 3 - и функции из main для работы с массивом.*/
void Task1_5()
{
    cout << "Task 1, 5" << endl;

    int SizeArray;

    do
    {
        cout << "Please, enter size of your Array: ";
        cin >> SizeArray;

    } while (SizeArray <= 0);


    ptrArray = new (std::nothrow) float[SizeArray];

    if (ptrArray != nullptr)
    {
        MyLib::InitArray(ptrArray, SizeArray);
        cout << endl;
        MyLib::PrintFloatArray(ptrArray, SizeArray);
        cout << endl;
        MyLib::PositiveAndNegative(ptrArray, SizeArray);
        cout << endl;

        delete[] ptrArray;
        ptrArray = nullptr;
    }
    else
    {
        cout << "Error! Can not allocate memory!";
    }

    cout << endl;

    return;
}

/*2. Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и 
возвращает true или false, вывести на экран «true» или «false».*/

#define Comparison (Number_1, Number_2); if ((Number_1 > 0) && (Number_1 < Number_2)) { Result = "TRUE"; } else { Result = "FALSE"; }

void Task2()
{
    int Number_1, Number_2;
    string Result;

    cout << "Task 2" << endl;
    
    cout << "Please, enter int Number_1: ";
    cin >> Number_1;
    cout << "Please, enter int Number_2: ";
    cin >> Number_2;
    
    Comparison(Number_1, Number_2);
    cout << "Is introduced number > 0 and < " << Number_2 << "? " << Result << endl;

    cout << endl;

    return;
}

/*3. Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком). 
Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.*/

#define ARRAY_SIZE 6

void Task3()
{
    int ArrayTask3[ARRAY_SIZE];

    cout << "Task 3" << endl;
    cout << "Please, enter int array:" << endl;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << "ArrayTask3[" << i << "]: ";
        cin >> ArrayTask3[i];
    }
    
    MyLib::BubbleSortArray(ArrayTask3, ARRAY_SIZE);
    MyLib::PrintIntArray(ArrayTask3, ARRAY_SIZE);
    
    cout << endl;

    return;
}

/* 4.* Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. Выделите динамически переменную этого типа. Инициализируйте ее. 
Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл.*/

#pragma pack(push, 1)
struct Employee { // Новый тип данных Сотрудник
    long id; // ID сотрудника
    string FirstName; // имя сотрудника
    string LastName; // фамилия сотрудника
    unsigned short age; // его возраст
    double salary; // его зарплата
};
#pragma pack(pop)

ofstream fout;

// создание файла
void CreateFileTXT(string FileName)
{
    ofstream fout(FileName);
    return;
}

void Task4()
{
    cout << "Task 4" << endl;

    Employee* FirstEmployee = new Employee; // выделение памяти

    cout << "Please, enter employee's id: ";
    cin >> FirstEmployee->id;
    cout << "Please, enter employee's first name: ";
    cin >> FirstEmployee->FirstName;
    cout << "Please, enter employee's last name: ";
    cin >> FirstEmployee->LastName;
    cout << "Please, enter employee's age: ";
    cin >> FirstEmployee->age;
    cout << "Please, enter employee's salary: ";
    cin >> FirstEmployee->salary;
    
    cout << endl;
    cout << "First employee:" << endl;
    cout << "id: " << FirstEmployee->id << endl;
    cout << "first name: " << FirstEmployee->FirstName << endl;
    cout << "last name: " << FirstEmployee->LastName << endl;
    cout << "age: " << FirstEmployee->age << endl;
    cout << "salary: " << FirstEmployee->salary << endl;
    cout << "Size of struct:" << sizeof(FirstEmployee) << endl;

    string FileName;
    cout << endl << "Input File name: ";
    cin >> FileName;
    FileName = FileName + ".txt";

    CreateFileTXT(FileName);
    
    fout.open(FileName, std::ofstream::binary);
    if (fout.is_open())
    {
        fout << "First employee:" << endl;
        fout << "id: " << FirstEmployee->id << endl;
        fout << "first name: " << FirstEmployee->FirstName << endl;
        fout << "last name: " << FirstEmployee->LastName << endl;
        fout << "age: " << FirstEmployee->age << endl;
        fout << "salary: " << FirstEmployee->salary;
    }
    else
    {
        cout << "Error. Can not open file.";
    }
    fout.close();
    
    delete FirstEmployee; // удаление памяти
        
    cin.get();
    return;
}


int main()
{
    // #1, 5
    Task1_5(); 

    // #2
    Task2();

    // #3
    Task3();

    // #4
    Task4();

    cin.get();
    return 0;
}