// Колпакова Е., Lesson 2, Visual Studio Code

//В одном main.cpp файле / проекте:
//1. Создать и инициализировать переменные пройденных типов данных(short int, int, long long, char, bool, float, double).
//2. Создать перечисление(enum) с возможными вариантами символов для игры в крестики - нолики.
//3. Создать массив, способный содержать значения такого перечисления и инициализировать его.
//4. * Создать структуру(struct) данных «Поле для игры в крестики - нолики» и снабдить его всеми необходимыми свойствами(подумайте что может понадобиться).
//5. **Создать структуру(struct) объединяющую : union (int, float, char) и 3 - и битовых поля(флага) указывающими какого типа значение в данный момент содержится в объединении(isInt, isFloat, isChar).Продемонстрировать пример использования в коде этой структуры.
//Для программирования используйте установленную среду программирования(IDE).Если задания 4 и 5 кажутся сложными постарайтесь сделать первые 3.

#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

// 1. Создать и инициализировать переменные пройденных типов данных(short int, int, long long, char, bool, float, double).
short int shA = 5;
int iA = 105;
long long lA = 1005;
char ChA = 'С';
bool bA = true;
float fA = 1.555;
double dA = 15.521255;
string name, message;

// 2. Создать перечисление(enum) с возможными вариантами символов для игры в крестики - нолики.
enum Game
{
	Symbol_X,
	Symbol_O,
	Symbol_Zero,
};

// 3. Создать массив, способный содержать значения такого перечисления и инициализировать его.
Game array[3][3] = { { Symbol_Zero, Symbol_Zero, Symbol_Zero },
					 { Symbol_Zero, Symbol_Zero, Symbol_Zero }, 
					 { Symbol_Zero, Symbol_Zero, Symbol_Zero } };

// 4. * Создать структуру(struct) данных «Поле для игры в крестики - нолики» и снабдить его всеми необходимыми свойствами(подумайте что может понадобиться).
struct Game_XandO
{
	Game array[3][3];					// Массив клеток
	bool isGameFinished;				// Флаг, закончена ли игра
	bool isFirstPlayerWon;				// Флаг, победил ли первый игрок
	long long Player1ID, Player2ID;		// ID игрок1, игрок2
	string Player1Name, Player2Name;	// Имена игрок1, игрок2
	Game Player1, Player2;				// Чем ходит игрок1, игрок2
	const unsigned int FieldSize = 3;	// Длина игрового поля
	double duration; 					// сколько времени длилась партия. Нашла в гугле интересную библиотеку chrono. Я ведь правильно понимаю, что с помощью этой библиотеки удобно считать затраченное время и не надо хитро изворачиваться и делать счетчик? Или в такой игре лучше счетчик по секундам делать? если да, то как?
};

// 5. **Создать структуру(struct) объединяющую : union (int, float, char) и 3 - и битовых поля(флага) указывающими какого типа значение в данный момент содержится в объединении(isInt, isFloat, isChar).Продемонстрировать пример использования в коде этой структуры.
union flags
{
	int iInt;
	float fFloat;
	char ChChar;
};

struct task5
{
	flags flag;
	unsigned int Int   : 1;
	unsigned int Float : 1;
	unsigned int Char : 1;
};

int main()
{
	cout << "Hello. Please, enter your name: ";
	cin >> name;
	cout << " " << endl;
	
	// #1
	cout << "short int shA = " << shA << "; int iA = " << iA << "; long long lA = " << lA << "; char ChA = " << ChA << "; bool bA = " << bA << "; float fA = " << fA << "; double dA = " << dA << endl;

	// #2
	//array[0][0] = Symbol_Zero; у меня на такую инициализацию ругается компилятор. Почему? array неоднозначный символ
	//array[1][2] = Symbol_O; 
	
	// #5
	task5 dot;

	dot.flag.iInt = 77;
	dot.Int = 1;
	dot.Float = 0;
	dot.Char = 0;

	dot.flag.fFloat = 77.777;
	dot.Int = 0;
	dot.Float = 1;
	dot.Char = 0;

	dot.flag.ChChar = 'F';
	dot.Int = 0;
	dot.Float = 0;
	dot.Char = 1;
	
	cout << " " << endl;
	message = "Thank you for watching, " + name + "!";
	cout << message << endl;

	return 0;
}