// Колпакова Е., Lesson 2, Visual Studio Code

// 1. Написать программу, вычисляющую выражение a* (b + (c / d)) и выводящую результат с плавающей точкой, где a, b, c, d – целочисленные константы.Используйте static_cast или СStyle cast к float чтобы выполнить точное деление.
// 2. Дано целое число.Если оно меньше или равно 21, то выведите на экран разницу между этим числом и числом 21. Если же заданное число больше, чем 21, необходимо вывести удвоенную разницу между этим числом и 21. При выполнении задания следует использовать тернарный оператор(? : ).
// 3. *Описать трёхмерный целочисленный массив, размером 3х3х3 и указатель на значения внутри массива и при помощи операции разыменования вывести на экран значение центральной ячейки получившегося куба[1][1][1].
// 4. **Написать программу, вычисляющую выражение из первого задания, а переменные для неё объявлены и инициализировать в другом cpp файле.Используйте extern.
// Предлагаю использовать 2 - а проекта в IDE.Первые 3 задания в проекте номер 1. 4 - е задание в отдельном проекте.Или можно 1 - н проект если вы сделаете 2, 3, 4 задание в нем.То есть если вы сделали 4 - е задание, то 1 - е можно не делать. = )

#include <iostream>

using namespace std;

//#2
int Number, Result;
const int TwentyOne = 21;
//#3
int MyArray[3][3][3], * pArr;
//#4
float ResultTask4;

int main()
{
	//#2 Дано целое число.Если оно меньше или равно 21, то выведите на экран разницу между этим числом и числом 21. Если же заданное число больше, чем 21, необходимо вывести удвоенную разницу между этим числом и 21. При выполнении задания следует использовать тернарный оператор(? : ).
	
	cout << "Task #2" << endl;
	cout << "Hello! Please, enter int Number = ";
	cin >> Number;
	
	Result = (Number <= TwentyOne) ? Number - TwentyOne : 2 * (Number - TwentyOne);
	
	if (Number <= TwentyOne)
	{
		cout << "Your Number "<< Number << " is <= " << TwentyOne  << ", so the Resuilt = Number - " << TwentyOne  << endl;
	}
	else
	{
		cout << "Your Number " << Number << " is > " << TwentyOne << ", so the Resuilt = 2 * (Number - " << TwentyOne << ")" << endl;
	}
	cout << "The Result is: " << Result << endl;

	//#3 *Описать трёхмерный целочисленный массив, размером 3х3х3 и указатель на значения внутри массива и при помощи операции разыменования вывести на экран значение центральной ячейки получившегося куба[1][1][1].
	
	cout << endl << "Task #3" << endl;
	
	pArr = &MyArray[1][1][1]; 
	*pArr = 111;
	
	cout << "MyArray[1][1][1] = " << MyArray[1][1][1] << endl;
	cout << endl;
	
	//Исследование, как двигается указатель по трёхмерному массиву =)
	cout << "Now I would like to see, how pointer is moving, when you start from [0][0][0] doing +1 each step" << endl;
	
	pArr = &MyArray[0][0][0]; //[0][0][0]
	*pArr = 1;

	pArr++;
	*pArr = 2; // [0][0][1]

	pArr++;
	*pArr = 3; // [0][0][2]

	pArr++;
	*pArr = 4; // [0][1][0]

	pArr++;
	*pArr = 5; // [0][1][1]

	pArr++;
	*pArr = 6; // [0][1][2]

	pArr++;
	*pArr = 7; // [0][2][0]

	pArr++;
	*pArr = 8; // [0][2][1]

	pArr++;
	*pArr = 9; // [0][2][2]

	pArr++;
	*pArr = 10; // [1][0][0]
	
	pArr++;
	*pArr = 11; // [1][0][1]
	
	pArr++;
	*pArr = 12; // [1][0][2]
	
	pArr++;
	*pArr = 13; // [1][1][0]
	
	pArr++;
	*pArr = 14; // [1][1][1]
	
	pArr++;
	*pArr = 15; // [1][1][2]
	
	pArr++;
	*pArr = 16; // [1][2][0]
	
	pArr++;
	*pArr = 17; // [1][2][1]
	
	pArr++;
	*pArr = 18; // [1][2][2]
	
	pArr++;
	*pArr = 19; // [2][0][0]
	
	pArr++;
	*pArr = 20; // [2][0][1]
	
	pArr++;
	*pArr = 21; // [2][0][2]
	
	pArr++;
	*pArr = 22; // [2][1][0]
	
	pArr++;
	*pArr = 23; // [2][1][1]
	
	pArr++;
	*pArr = 24; // [2][1][2]
	
	pArr++;
	*pArr = 25; // [2][2][0]
	
	pArr++;
	*pArr = 26; // [2][2][1]
	
	pArr++;
	*pArr = 27; // [2][2][2]

	cout << endl;
	cout << "Answer fow H/w #3 (second version) is MyArray[1][1][1] = " << MyArray[1][1][1] << endl;
	cout << "Let's see, how this array filled up from 1 to 27 (+1 each step):" << endl;
	cout << endl;

	cout << "MyArray[0][0][0] = " << MyArray[0][0][0] << ";  MyArray[0][0][1] = " << MyArray[0][0][1] << ";  MyArray[0][0][2] = " << MyArray[0][0][2] << ";" << endl;
	cout << "MyArray[0][1][0] = " << MyArray[0][1][0] << ";  MyArray[0][1][1] = " << MyArray[0][1][1] << ";  MyArray[0][1][2] = " << MyArray[0][1][2] << ";" << endl;
	cout << "MyArray[0][2][0] = " << MyArray[0][2][0] << ";  MyArray[0][2][1] = " << MyArray[0][2][1] << ";  MyArray[0][2][2] = " << MyArray[0][2][2] << ";" << endl;
	cout << "MyArray[1][0][0] = " << MyArray[1][0][0] << "; MyArray[1][0][1] = " << MyArray[1][0][1] << "; MyArray[1][0][2] = " << MyArray[1][0][2] << ";" << endl;
	cout << "MyArray[1][1][0] = " << MyArray[1][1][0] << "; MyArray[1][1][1] = " << MyArray[1][1][1] << "; MyArray[1][1][2] = " << MyArray[1][1][2] << ";" << endl;
	cout << "MyArray[1][2][0] = " << MyArray[1][2][0] << "; MyArray[1][2][1] = " << MyArray[1][2][1] << "; MyArray[1][2][2] = " << MyArray[1][2][2] << ";" << endl;
	cout << "MyArray[2][0][0] = " << MyArray[2][0][0] << "; MyArray[2][0][1] = " << MyArray[2][0][1] << "; MyArray[2][0][2] = " << MyArray[2][0][2] << ";" << endl;
	cout << "MyArray[2][1][0] = " << MyArray[2][1][0] << "; MyArray[2][1][1] = " << MyArray[2][1][1] << "; MyArray[2][1][2] = " << MyArray[2][1][2] << ";" << endl;
	cout << "MyArray[2][2][0] = " << MyArray[2][2][0] << "; MyArray[2][2][1] = " << MyArray[2][2][1] << "; MyArray[2][2][2] = " << MyArray[2][2][2] << ";" << endl;

	// #4 **Написать программу, вычисляющую выражение из первого задания, а переменные для неё объявлены и инициализировать в другом cpp файле.Используйте extern.
	//(1. Написать программу, вычисляющую выражение a* (b + (c / d)) и выводящую результат с плавающей точкой, где a, b, c, d – целочисленные константы.Используйте static_cast или СStyle cast к float чтобы выполнить точное деление.)
	cout << endl << "Task #4" << endl;
	
	extern int a, b, c, d;
	
	cout << "Please, enter a = ";
	cin >> a;
	cout << "Please, enter b = ";
	cin >> b;
	cout << "Please, enter c = ";
	cin >> c;
	cout << "Please, enter d = ";
	cin >> d;
	
	ResultTask4 = float(a) * (float(b) + (float(c) / d));
	
	cout << endl << "The Result = " << ResultTask4 << endl;
	cout << endl << "Thank you, bye! =)" << endl;
	
	// Добавила вывод константы
	
	extern const int g;
	cout << g << endl;
	
	return 0;	
}
