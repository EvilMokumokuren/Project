/* Колпакова Е., Lesson 5, Visual Studio Code
1. Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. Вызвать эту функцию из main.
2. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.
3. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран. 
Для продвинутых:
4. * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), при этом метод должен циклически сместить все элементы массива на n позиций.
5. ** Написать метод, в который передается не пустой одномерный целочисленный массив, метод должен вернуть истину если в массиве есть место, в котором сумма левой и правой части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false, checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти cимволы в массив не входят.
*/

#include <iostream>
#include <string>

using namespace std;

void Task1(double* ArrayTask1, int SizeArrayTask1);
void Task2(int* ArrayTask2, int SizeArrayTask2);
void Task3(int* ArrayTask3, int SizeArrayTask3);
void Task4(int* ArrayTask4, int SizeArrayTask4, int n);
void Task5(int* ArrayTask5, int SizeArrayTask5, int Separator);

int main()
{
    cout << "Hello!" << endl;
    //#1
    cout << "Task #1" << endl;
   
    const int SizeArrayTask1 = 10;
    double ArrayTask1[SizeArrayTask1];
    Task1(ArrayTask1, SizeArrayTask1);

    //#2
    cout << endl << "Task #2" << endl;
    
    const int SizeArrayTask2 = 10;
    int ArrayTask2[SizeArrayTask2];
    Task2(ArrayTask2, SizeArrayTask2);

    //#3
    cout << endl << "Task #3" << endl;

    const int SizeArrayTask3 = 8;
    int ArrayTask3[SizeArrayTask3];
    Task3(ArrayTask3, SizeArrayTask3);

    //#4
    cout << endl << "Task #4" << endl;
    const int SizeArrayTask4 = 5;
    int n, ArrayTask4[SizeArrayTask4];

    cout << "Please, enter ArrayTask4: " << endl;

    // Дадим возможность ввести Массив с клавиатуры
    for (size_t i = 0; i < SizeArrayTask4; i++)
    {
        cout << "ArrayTask4[" << i << "] = ";
        cin >> ArrayTask4[i];
    }

    // Теперь необходимо ввести n
        cout << "Please, enter n: ";
        cin >> n;
   
    Task4(ArrayTask4, SizeArrayTask4, n);
         
    //#5
    cout << endl << "Task #5" << endl;
    const int SizeArrayTask5 = 6;
    int ArrayTask5[SizeArrayTask5];
    size_t Separator;

    cout << "Please, enter ArrayTask5: " << endl;

    // Дадим возможность ввести Массив с клавиатуры
    for (size_t i = 0; i < SizeArrayTask5; i++)
    {
        cout << "ArrayTask5[" << i << "] = ";
        cin >> ArrayTask5[i];
    }
    
    // Теперь необходимо ввести "разделитель"
    do
    {
        cout << "Please, enter Separator between 0 and " << (SizeArrayTask5 + 1) << ": ";
        cin >> Separator;
    } while ((Separator < 0) || (Separator > (SizeArrayTask5 + 1)));

    Task5(ArrayTask5, SizeArrayTask5, Separator);

    return 0;
}


// 1. Написать функцию которая выводит массив double чисел на экран. Параметры функции это сам массив и его размер. Вызвать эту функцию из main.
void Task1(double* ArrayTask1, int SizeArrayTask1)
{
    cout << "Double ArrayTask1:";
    for (size_t i = 0; i < SizeArrayTask1; i++)
    {
        ArrayTask1[i] = (rand() % 100) / 3.7;
        cout << " " << ArrayTask1[i];
    }
    cout << endl;
    
    return;
}

// 2. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.
void Task2(int* ArrayTask2, int SizeArrayTask2)
{
    cout << "Init ArrayTask2:  ";
    
    for (size_t i = 0; i < SizeArrayTask2; i++)
    {
        ArrayTask2[i] = (rand() % 2);
        cout << " " << ArrayTask2[i];
    }
    cout << endl <<  "Answer ArrayTask2:";
    
    for (size_t i = 0; i < SizeArrayTask2; i++)
    {
        ArrayTask2[i] = (ArrayTask2[i] == 0) ? 1 : 0;
        cout << " " << ArrayTask2[i];
    }
    cout << endl;
    
    return;
}

// 3. Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив на экран. 
void Task3(int* ArrayTask3, int SizeArrayTask3)
{
    cout << "Answer ArrayTask3:";

    for (size_t i = 0; i < SizeArrayTask3; i++)
    {
        ArrayTask3[i] = (i == 0) ? 1 : (ArrayTask3[i-1] + 3);
        cout << " " << ArrayTask3[i];
    }
    cout << endl;

    return;
}

// 4. * Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным), при этом метод должен циклически сместить все элементы массива на n позиций.
void Task4(int* ArrayTask4, int SizeArrayTask4, int n)
{
    int tempArray[5];
    if (n != 0)
    {
        cout << "Answer ArrayTask4:";
        n = n % SizeArrayTask4;
        for (size_t i = 0; i < SizeArrayTask4; i++)
        {
            tempArray[i] = ArrayTask4[(i + n + SizeArrayTask4) % SizeArrayTask4];
            cout << " " << tempArray[i];
        }
        cout << endl;
    }
    else
    { 
        cout << "n = 0, so the array has't changed!" << endl;
    }
      
    return;
}

/* 5. ** Написать метод, в который передается не пустой одномерный целочисленный массив, метод должен вернуть истину если в массиве есть место, в котором сумма левой и правой части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false, 
checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти cимволы в массив не входят.
*/
void Task5(int* ArrayTask5, int SizeArrayTask5, int Separator)
{
    int Summ1 = 0, Summ2 = 0;
    string Result;

    if ((Separator == 0) || (Separator == (SizeArrayTask5)))
    {
        Result = "FALSE";
    }
    else
    {
        for (size_t i = 0; i < Separator; i++)
        {
            Summ1 += ArrayTask5[i];
        }

        for (size_t i = (Separator); i < SizeArrayTask5; i++)
        {
            Summ2 += ArrayTask5[i];
        }

        Result = (Summ1 == Summ2) ? "TRUE" : "FALSE";
    }
    
    cout << "Summ of the elements of ArrayTask5 before Separator = Summ after: ";
    cout << Result << endl;

    return;
}