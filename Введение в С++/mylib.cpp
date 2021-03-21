#include <iostream>

using namespace std;
/*1. Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: для инициализации массива (типа float), печати его на экран и подсчета количества 
отрицательных и положительных элементов. Вызывайте эти 3-и функции из main для работы с массивом.*/

namespace MyLib
{   
    // Ввод массива
    void InitArray(float* ptrArray, int SizeArray)
    {
        cout << "Please, enter float array:" << endl;
        for (int i = 0; i < SizeArray; i++)
        {
            cout << "ptrArray[" << i << "]: ";
            cin >> ptrArray[i];
        }
       
        cout << endl;

        return;
    }

    //Вывод массива float
    void PrintFloatArray(float* ptrArray, int SizeArray)
    {
        cout << "Your array: [ ";
        for (int i = 0; i < SizeArray; i++)
        {
            cout << ptrArray[i] << " ";
        }

        cout << "]" << endl;

        return;
    }

    // Вывод массива int
    void PrintIntArray(int* ptrArray, int SizeArray)
    {
        cout << "Your array: [ ";
        for (int i = 0; i < SizeArray; i++)
        {
            cout << ptrArray[i] << " ";
        }

        cout << "]" << endl;

        return;
    }
        
    //Подсчет отрицательных и положительных элементов массива
    void PositiveAndNegative(float* ptrArray, int SizeArray)
    {
        int Positive = 0, Negative = 0, NullElements = 0;
        cout << "Now we'll count, how much positive and negarive elements are in your array:" << endl;
        for (int i = 0; i < SizeArray; i++)
        {
            if (ptrArray[i] > 0)
            {
                Positive += 1;
            }
            else if (ptrArray[i] < 0)
            {
                Negative += 1;
            }
            else
            {
                NullElements += 1;
            }
        }

        cout << "There are " << Positive << " POSITIVE elements in your array" << endl;
        cout << "There are " << Negative << " NEGATIVE elements in your array" << endl;
        cout << "There are " << NullElements << " NULL elements in your array" << endl << endl;

        return;
    }
   
    // Сортировка пузырьком
    void BubbleSortArray(int* MyArray, int SizeArray)
    {
        int tmp;

        for (int i = 0; i < SizeArray - 1; i++)
        {
            for (int j = 0; j < SizeArray - i - 1; j++)
            {
                if (MyArray[j] > MyArray[j + 1])
                {
                    tmp = MyArray[j];
                    MyArray[j] = MyArray[j + 1];
                    MyArray[j + 1] = tmp;

                }
            }
        }

        return;
    }  
}