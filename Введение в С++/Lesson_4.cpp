/* Колпакова Е., Lesson 4, Visual Studio Code
1. Написать программу, проверяющую что сумма двух(введенных с клавиатуры) чисел лежит в пределах от 10 до 20 (включительно), если да – вывести строку "true", в противном случае – "false";
2. Написать программу, выводящую на экран строку “true”, если две целочисленные константы, объявленные в её начале либо обе равны десяти сами по себе, либо их сумма равна десяти.Иначе "false".
3. Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50. Например: "Your numbers: 1 3 5 7 9 11 13 …".Для решения используйте любой С++ цикл.
4. * Написать программу, проверяющую, является ли некоторое число - простым.Простое число — это целое положительное число, которое делится без остатка только на единицу и себя само.
5. * Пользователь вводит с клавиатуры число(год) : от 1 до 3000. Написать программу, которая определяет является ли этот год високосным.Каждый 4 - й год является
високосным, кроме каждого 100 - го, при этом каждый 400 - й – високосный.Вывести результаты работы программы в консоль.
Замечание : Можно сделать в одном проекте(например разместить разные задания в разных функциях).Или в разных проектах если это кажется удобнее.
*/

#include <iostream>

using namespace std;

//#1
int NumberTask1;
//#2
const int NumberTask2_1 = 3, NumberTask2_2 = 6;
//#3
int Task3Array[50];
//#4
int NumberTask4;
//#5
int NumberTask5;

// 1. Написать программу, проверяющую что сумма двух(введенных с клавиатуры) чисел лежит в пределах от 10 до 20 (включительно), если да – вывести строку "true", в противном случае – "false";
void Task1(int NumberTask1)
{
	if ((NumberTask1 >= 10) && (NumberTask1 <= 20))
	{
		cout << "Your number " << NumberTask1 << " is between 10 and 20, so the answer is TRUE" << endl;
	}
	else
	{
		cout << "Your number " << NumberTask1 << " isn't between 10 and 20, so the answer is FALSE" << endl;
	}
}

// 2. Написать программу, выводящую на экран строку “true”, если две целочисленные константы, объявленные в её начале либо обе равны десяти сами по себе, либо их сумма равна десяти.Иначе "false".
void Task2(int NumberTask2_1, int NumberTask2_2)
{
	if (((NumberTask2_1 == 10) && (NumberTask2_2 == 20)) || ((NumberTask2_1 + NumberTask2_2) == 10))
	{
		cout << "Your numbers " << NumberTask2_1 << " and "<< NumberTask2_2 << " equal 10 or their summ = 10, so the answer is TRUE" << endl;
	}
	else
	{
		cout << "Your numbers " << NumberTask2_1 << " and " << NumberTask2_2 << " are not equal 10 or their summ <> 10, so the answer is FALSE" << endl;
	}
}

// 3. Написать программу которая выводит на экран список всех нечетных чисел он 1 до 50. Например: "Your numbers: 1 3 5 7 9 11 13 …".Для решения используйте любой С++ цикл.
void Task3(int Task3Array[50])
{
	cout << "Your numbers: ";
	for (size_t i = 0; i < 50; i++)
	{
		if ((Task3Array[i] % 2) != 0)
		{
			cout << Task3Array[i] << " ";
		}
			
	}
	
}

// 4. * Написать программу, проверяющую, является ли некоторое число - простым.Простое число — это целое положительное число, которое делится без остатка только на единицу и себя само.
void Task4(int NumberTask4)
{
	if ((((NumberTask4 % NumberTask4) == 0) && ((NumberTask4 % 1) == 0) && (NumberTask4 > 1) && ((NumberTask4 % 2) != 0)) || (NumberTask4 == 2))
	{
		cout << "Your number " << NumberTask4 << " is prime" << endl;
	}
	else
	{
		cout << "Your number " << NumberTask4 << " is not prime" << endl;
	}
	
}

/* 
5. * Пользователь вводит с клавиатуры число(год) : от 1 до 3000. Написать программу, которая определяет является ли этот год високосным.Каждый 4 - й год является
високосным, кроме каждого 100 - го, при этом каждый 400 - й – високосный.Вывести результаты работы программы в консоль.
*/
void Task5(int NumberTask5)
{
	if ((NumberTask5 % 4) != 0)
	{
		cout << NumberTask5 <<" is NOT leap year" << endl;
	}
	else if (((NumberTask5 % 100) == 0) && ((NumberTask5 % 400) != 0))
	{
		cout << NumberTask5 << " is NOT leap year" << endl;
	}
	else
	{
		cout << NumberTask5 << " is leap year" << endl;
	}
}

int main()
{
	cout << "Hello!" << endl;
	// #1 
	cout << "Task #1" << endl;
	cout << "Please, enter int number = ";
	cin >> NumberTask1;

	Task1(NumberTask1);

	// #2
	cout << endl << "Task #2" << endl;

	Task2(NumberTask2_1, NumberTask2_2);

	// #3 
	cout << endl << "Task #3" << endl;

	// Мне было лень задавать массив руками..
	cout << "Task3Array[i] = ";
	for (size_t i = 0; i < 50; i++)
	{
		Task3Array[i] = i + 1;
		if (Task3Array[i] < 50)
		{
			cout << Task3Array[i] << ", ";
		}
		else
		{
			cout << Task3Array[i] << endl;
		}
	}
	
	cout << endl;

	Task3(Task3Array);

	// #4
	cout << endl << endl << "Task #4" << endl;
	cout << "Please, enter int number = ";
	cin >> NumberTask4;

	Task4(NumberTask4);

	// #5
	cout << endl << "Task #5" << endl;
	
	do
	{
		cout << "Please, enter int number between 1 and 3000: ";
		cin >> NumberTask5;
	} while ((NumberTask5 < 1) || (NumberTask5 > 3000));
	
	cout << endl;
	Task5(NumberTask5);

	cout << endl << "Thank you!)" << endl;

	return 0;
}