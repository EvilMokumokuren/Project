/* Колпакова Е., Игра "Крестики нолики", Visual Studio Code
Запрограммировать игру крестики нолики на поле 3х3. Прислать архив всего проекта или ссылку на гит репозиторий.

Для джуниоров: не обязательно делать крутой искусственный интеллект в игре. Но у вас должны корректно работать все основные моменты в игре, как например и главный цикл игры в main.

Челендж для опытных и продвинутых: сделать решение на поле 4х4 или 5х5 или на динамическом поле, размер которого ввел пользователь. Также можно запросить у пользователя количество фигур необходимое для выигрыша, 3-5. */


#include <iostream>
#include <chrono>
#include <random>
#include <stdlib.h>
#include <windows.h>

using namespace std;

// необходимые символы
enum Symbol
{
	Symbol_X = 'X',
	Symbol_O = '0',
	Symbol_Zero = '_',
};

// прогресс игры
enum GameProgress
{
	IN_PROGRESS,
	AI_WON,
	HUMAN_WON,
	DRAW,
};

struct Game
{
	Symbol** ptrField = nullptr;		// динамическое выделение
	size_t SizeX, SizeY;				// размер игрового поля	
	Symbol human, ai;					// Чем ходит игрок, искусственный интеллект
	bool humanfirst;					// кто ходит первым
	GameProgress Progress;				// прогресс игры
	size_t turn;						// счетчик ходов
	size_t complexity;					// сложность	
};

// координаты
struct Coord
{
	size_t x, y;
};

// очистка поля
void ClearField()
{
	system("cls");
}

// честно стащенный рандом
int32_t GetRandomNum(int32_t min, int32_t max)
{
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}

// прорисовка поля
void PrintField(Game& rGame)
{
	if (rGame.complexity == 1)
	{
		cout << "Для победы необходимо сложить комбинацию из 3 символов" << endl;
	}
	if (rGame.complexity == 2)
	{
		cout << "Для победы необходимо сложить комбинацию из 4 символов" << endl;
	}
	if (rGame.complexity == 3)
	{
		cout << "Для победы необходимо сложить комбинацию из 5 символов" << endl;
	}
	cout << endl;
	cout << "     ";
	for (size_t j = 0; j < rGame.SizeX; j++)
	{
		cout << (j + 1) << "   ";
	}
	cout << endl;

	for (size_t i = 0; i < rGame.SizeY; i++)
	{
		cout << " " << (i + 1) << " | ";

		for (size_t j = 0; j < rGame.SizeX; j++)
		{
			cout << static_cast <char>(rGame.ptrField[i][j]) << " | ";
		}
		cout << endl;
	}
	
	cout << endl << "Вы играете: " << static_cast <char>(rGame.human) << endl;
	cout << "Ваш противник играет: " << static_cast <char>(rGame.ai) << endl;

	return;
}

// выделение памяти
void InitMemory(Game& rGame)
{
	rGame.ptrField = new Symbol * [rGame.SizeY];

	for (size_t i = 0; i < rGame.SizeY; i++)
	{
		rGame.ptrField[i] = new Symbol[rGame.SizeX];
	}

	for (size_t i = 0; i < rGame.SizeY; i++)
	{
		for (size_t j = 0; j < rGame.SizeX; j++)
		{
			rGame.ptrField[i][j] = Symbol_Zero;
		}
	}

	if ((GetRandomNum(0, 100) > 50))
	{
		rGame.human = Symbol_X;
		rGame.ai = Symbol_O;
		rGame.humanfirst = true;		
	}
	else
	{
		rGame.human = Symbol_O;
		rGame.ai = Symbol_X;
		rGame.humanfirst = false;		
	}
	
	rGame.Progress = IN_PROGRESS;	
}

// ввод игроком
Coord getPlayerCoord(Game& rGame)
{
	Coord Step = { 0 };
	
	if (rGame.SizeX == 3)
	{
		do {
			cout << endl << "Введите X: ";
			cin >> Step.x;
			cout << "Введите Y: ";
			cin >> Step.y;	

		} while ((Step.x <= 0) || (Step.y <= 0) || (Step.x > 3) || (Step.y > 3) || rGame.ptrField[Step.y - 1][Step.x - 1] != Symbol_Zero);
	}
	
	if (rGame.SizeX == 4)
	{
		do {
			cout << endl << "Введите X: ";
			cin >> Step.x;
			cout << "Введите Y: ";
			cin >> Step.y;		

		} while ((Step.x <= 0) || (Step.y <= 0) || (Step.x > 4) || (Step.y > 4) || rGame.ptrField[Step.y - 1][Step.x - 1] != Symbol_Zero);
	}
	
	if (rGame.SizeX == 5)
	{
		do {
			cout << endl << "Введите X: ";
			cin >> Step.x;
			cout << "Введите Y: ";
			cin >> Step.y;

		} while ((Step.x <= 0) || (Step.y <= 0) || (Step.x > 5) || (Step.y > 5) || rGame.ptrField[Step.y - 1][Step.x - 1] != Symbol_Zero);
	}
	
	Step.x--;
	Step.y--;

	return Step;
}

// кто выиграл?
GameProgress WhoWin(Game& rGame)
{
	if (rGame.SizeX == 3)
	{
		for (size_t y = 0; y < rGame.SizeY; y++)
		{
			if ((rGame.ptrField[y][0] == rGame.ptrField[y][1]) && (rGame.ptrField[y][0] == rGame.ptrField[y][2]))
			{
				if (rGame.ptrField[y][0] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[y][0] == rGame.ai)
				{
					return AI_WON;
				}
			}
		}

		for (size_t x = 0; x < rGame.SizeX; x++)
		{
			if ((rGame.ptrField[0][x] == rGame.ptrField[1][x]) && (rGame.ptrField[0][x] == rGame.ptrField[2][x]))
			{
				if (rGame.ptrField[0][x] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[0][x] == rGame.ai)
				{
					return AI_WON;
				}
			}
		}

		if ((rGame.ptrField[0][0] == rGame.ptrField[1][1]) && (rGame.ptrField[1][1] == rGame.ptrField[2][2]))
		{
			if (rGame.ptrField[0][0] == rGame.human)
			{
				return HUMAN_WON;
			}
			if (rGame.ptrField[0][0] == rGame.ai)
			{
				return AI_WON;
			}
		}

		if ((rGame.ptrField[0][2] == rGame.ptrField[1][1]) && (rGame.ptrField[1][1] == rGame.ptrField[2][0]))
		{
			if (rGame.ptrField[0][2] == rGame.human)
			{
				return HUMAN_WON;
			}
			if (rGame.ptrField[0][2] == rGame.ai)
			{
				return AI_WON;
			}
		}

		bool tmp = true;
		for (size_t y = 0; y < rGame.SizeY; y++)
		{
			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if (rGame.ptrField[y][x] == Symbol_Zero)
				{
					tmp = false;
				}
			}
		}

		if (tmp == true)
		{
			return DRAW;
		}

		return IN_PROGRESS;
	}

	if (rGame.SizeX == 4)
	{
		if (rGame.complexity == 1)
		{
			for (size_t y = 0; y < rGame.SizeY; y++)
			{
				if ((rGame.ptrField[y][0] == rGame.ptrField[y][1]) && (rGame.ptrField[y][0] == rGame.ptrField[y][2]))
				{
					if (rGame.ptrField[y][0] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[y][0] == rGame.ai)
					{
						return AI_WON;
					}
				}
				if ((rGame.ptrField[y][1] == rGame.ptrField[y][2]) && (rGame.ptrField[y][1] == rGame.ptrField[y][3]))
				{
					if (rGame.ptrField[y][1] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[y][1] == rGame.ai)
					{
						return AI_WON;
					}
				}

				for (size_t x = 0; x < rGame.SizeX; x++)
				{
					if ((rGame.ptrField[0][x] == rGame.ptrField[1][x]) && (rGame.ptrField[0][x] == rGame.ptrField[2][x]))
					{
						if (rGame.ptrField[0][x] == rGame.human)
						{
							return HUMAN_WON;
						}
						if (rGame.ptrField[0][x] == rGame.ai)
						{
							return AI_WON;
						}
					}
					if ((rGame.ptrField[1][x] == rGame.ptrField[2][x]) && (rGame.ptrField[1][x] == rGame.ptrField[3][x]))
					{
						if (rGame.ptrField[1][x] == rGame.human)
						{
							return HUMAN_WON;
						}
						if (rGame.ptrField[1][x] == rGame.ai)
						{
							return AI_WON;
						}
					}
				}

				if ((rGame.ptrField[0][0] == rGame.ptrField[1][1]) && (rGame.ptrField[0][0] == rGame.ptrField[2][2]))
				{
					if (rGame.ptrField[0][0] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[0][0] == rGame.ai)
					{
						return AI_WON;
					}
				}

				if ((rGame.ptrField[1][1] == rGame.ptrField[2][2]) && (rGame.ptrField[0][0] == rGame.ptrField[3][3]))
				{
					if (rGame.ptrField[1][1] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[1][1] == rGame.ai)
					{
						return AI_WON;
					}
				}

				if ((rGame.ptrField[0][3] == rGame.ptrField[1][2]) && (rGame.ptrField[0][3] == rGame.ptrField[2][1]))
				{
					if (rGame.ptrField[0][3] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[0][3] == rGame.ai)
					{
						return AI_WON;
					}
				}

				if ((rGame.ptrField[1][2] == rGame.ptrField[2][1]) && (rGame.ptrField[1][2] == rGame.ptrField[3][0]))
				{
					if (rGame.ptrField[1][2] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[1][2] == rGame.ai)
					{
						return AI_WON;
					}
				}

			}
		}
		if (rGame.complexity == 2)
		{
			for (size_t y = 0; y < rGame.SizeY; y++)
			{
				if ((rGame.ptrField[y][0] == rGame.ptrField[y][1]) && (rGame.ptrField[y][0] == rGame.ptrField[y][2]) && (rGame.ptrField[y][0] == rGame.ptrField[y][3]))
				{
					if (rGame.ptrField[y][0] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[y][0] == rGame.ai)
					{
						return AI_WON;
					}
				}
			}

			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if ((rGame.ptrField[0][x] == rGame.ptrField[1][x]) && (rGame.ptrField[0][x] == rGame.ptrField[2][x]) && (rGame.ptrField[0][x] == rGame.ptrField[3][x]))
				{
					if (rGame.ptrField[0][x] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[0][x] == rGame.ai)
					{
						return AI_WON;
					}
				}
			}
			if ((rGame.ptrField[0][0] == rGame.ptrField[1][1]) && (rGame.ptrField[0][0] == rGame.ptrField[2][2]) && (rGame.ptrField[0][0] == rGame.ptrField[3][3]))
			{
				if (rGame.ptrField[0][0] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[0][0] == rGame.ai)
				{
					return AI_WON;
				}
			}

			if ((rGame.ptrField[0][3] == rGame.ptrField[1][2]) && (rGame.ptrField[0][3] == rGame.ptrField[2][1]) && (rGame.ptrField[0][3] == rGame.ptrField[3][0]))
			{
				if (rGame.ptrField[0][3] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[0][3] == rGame.ai)
				{
					return AI_WON;
				}
			}
		}

		bool tmp = true;
		for (size_t y = 0; y < rGame.SizeY; y++)
		{
			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if (rGame.ptrField[y][x] == Symbol_Zero)
				{
					tmp = false;
				}
			}
		}

		if (tmp == true)
		{
			return DRAW;
		}

		return IN_PROGRESS;
	}

	else
	{
		if (rGame.complexity == 1)
		{
			// сверяем по вертикали по 3 штуки
			for (size_t y = 0; y < rGame.SizeY; y++)
			{
				if ((rGame.ptrField[y][0] == rGame.ptrField[y][1]) && (rGame.ptrField[y][0] == rGame.ptrField[y][2]))
				{
					if (rGame.ptrField[y][0] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[y][0] == rGame.ai)
					{
						return AI_WON;
					}
				}

				if ((rGame.ptrField[y][1] == rGame.ptrField[y][2]) && (rGame.ptrField[y][1] == rGame.ptrField[y][3]))
				{
					if (rGame.ptrField[y][1] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[y][1] == rGame.ai)
					{
						return AI_WON;
					}
				}

				if ((rGame.ptrField[y][2] == rGame.ptrField[y][3]) && (rGame.ptrField[y][2] == rGame.ptrField[y][4]))
				{
					if (rGame.ptrField[y][2] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[y][2] == rGame.ai)
					{
						return AI_WON;
					}
				}
			}

			// по горизонтали по 3 штуки
			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if ((rGame.ptrField[0][x] == rGame.ptrField[1][x]) && (rGame.ptrField[0][x] == rGame.ptrField[2][x]))
				{
					if (rGame.ptrField[0][x] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[0][x] == rGame.ai)
					{
						return AI_WON;
					}
				}

				if ((rGame.ptrField[1][x] == rGame.ptrField[2][x]) && (rGame.ptrField[1][x] == rGame.ptrField[3][x]))
				{
					if (rGame.ptrField[1][x] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[1][x] == rGame.ai)
					{
						return AI_WON;
					}
				}

				if ((rGame.ptrField[2][x] == rGame.ptrField[3][x]) && (rGame.ptrField[2][x] == rGame.ptrField[4][x]))
				{
					if (rGame.ptrField[2][x] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[2][x] == rGame.ai)
					{
						return AI_WON;
					}
				}
			}

			// диагональ 0.0 - 2.2
			if ((rGame.ptrField[0][0] == rGame.ptrField[1][1]) && (rGame.ptrField[0][0] == rGame.ptrField[2][2]))
			{
				if (rGame.ptrField[0][0] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[0][0] == rGame.ai)
				{
					return AI_WON;
				}
			}

			// диагональ 1.1 - 3.3
			if ((rGame.ptrField[1][1] == rGame.ptrField[2][2]) && (rGame.ptrField[1][1] == rGame.ptrField[3][3]))
			{
				if (rGame.ptrField[1][1] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[1][1] == rGame.ai)
				{
					return AI_WON;
				}
			}

			// диагональ 2.2 - 4.4
			if ((rGame.ptrField[2][2] == rGame.ptrField[3][3]) && (rGame.ptrField[2][2] == rGame.ptrField[4][4]))
			{
				if (rGame.ptrField[2][2] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[2][2] == rGame.ai)
				{
					return AI_WON;
				}
			}

			// диагональ 4.0 - 2.2
			if ((rGame.ptrField[0][4] == rGame.ptrField[1][3]) && (rGame.ptrField[0][4] == rGame.ptrField[2][2]))
			{
				if (rGame.ptrField[0][4] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[0][4] == rGame.ai)
				{
					return AI_WON;
				}
			}

			// диагональ 3.1 - 1.3
			if ((rGame.ptrField[1][3] == rGame.ptrField[2][2]) && (rGame.ptrField[1][3] == rGame.ptrField[3][1]))
			{
				if (rGame.ptrField[1][3] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[1][3] == rGame.ai)
				{
					return AI_WON;
				}
			}

			// диагональ 2.2 - 0.4
			if ((rGame.ptrField[2][2] == rGame.ptrField[3][1]) && (rGame.ptrField[2][2] == rGame.ptrField[4][0]))
			{
				if (rGame.ptrField[2][2] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[2][2] == rGame.ai)
				{
					return AI_WON;
				}
			}
		}
		if (rGame.complexity == 2)
		{
			for (size_t y = 0; y < rGame.SizeY; y++)
			{
				if ((rGame.ptrField[y][0] == rGame.ptrField[y][1]) && (rGame.ptrField[y][0] == rGame.ptrField[y][2]) && (rGame.ptrField[y][0] == rGame.ptrField[y][3]))
				{
					if (rGame.ptrField[y][0] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[y][0] == rGame.ai)
					{
						return AI_WON;
					}
				}

				if ((rGame.ptrField[y][1] == rGame.ptrField[y][2]) && (rGame.ptrField[y][1] == rGame.ptrField[y][3]) && (rGame.ptrField[y][1] == rGame.ptrField[y][4]))
				{
					if (rGame.ptrField[y][1] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[y][1] == rGame.ai)
					{
						return AI_WON;
					}
				}
			}
			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if ((rGame.ptrField[0][x] == rGame.ptrField[1][x]) && (rGame.ptrField[0][x] == rGame.ptrField[2][x]) && (rGame.ptrField[0][x] == rGame.ptrField[3][x]))
				{
					if (rGame.ptrField[0][x] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[0][x] == rGame.ai)
					{
						return AI_WON;
					}
				}
				if ((rGame.ptrField[1][x] == rGame.ptrField[2][x]) && (rGame.ptrField[1][x] == rGame.ptrField[3][x]) && (rGame.ptrField[1][x] == rGame.ptrField[4][x]))
				{
					if (rGame.ptrField[1][x] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[1][x] == rGame.ai)
					{
						return AI_WON;
					}
				}
			}
			if ((rGame.ptrField[0][0] == rGame.ptrField[1][1]) && (rGame.ptrField[0][0] == rGame.ptrField[2][2]) && (rGame.ptrField[0][0] == rGame.ptrField[3][3]))
			{
				if (rGame.ptrField[0][0] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[0][0] == rGame.ai)
				{
					return AI_WON;
				}
			}
			if ((rGame.ptrField[1][1] == rGame.ptrField[2][2]) && (rGame.ptrField[1][1] == rGame.ptrField[3][3]) && (rGame.ptrField[1][1] == rGame.ptrField[4][4]))
			{
				if (rGame.ptrField[1][1] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[1][1] == rGame.ai)
				{
					return AI_WON;
				}
			}
			if ((rGame.ptrField[0][4] == rGame.ptrField[1][3]) && (rGame.ptrField[0][4] == rGame.ptrField[2][2]) && (rGame.ptrField[0][4] == rGame.ptrField[3][1]))
			{
				if (rGame.ptrField[0][4] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[0][4] == rGame.ai)
				{
					return AI_WON;
				}
			}
			if ((rGame.ptrField[1][3] == rGame.ptrField[2][2]) && (rGame.ptrField[1][3] == rGame.ptrField[3][1]) && (rGame.ptrField[1][3] == rGame.ptrField[4][0]))
			{
				if (rGame.ptrField[1][3] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[1][3] == rGame.ai)
				{
					return AI_WON;
				}
			}
		}
		if (rGame.complexity == 3)
		{
			for (size_t y = 0; y < rGame.SizeY; y++)
			{
				if ((rGame.ptrField[y][0] == rGame.ptrField[y][1]) && (rGame.ptrField[y][0] == rGame.ptrField[y][2]) && (rGame.ptrField[y][0] == rGame.ptrField[y][3]) && (rGame.ptrField[y][0] == rGame.ptrField[y][4]))
				{
					if (rGame.ptrField[y][0] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[y][0] == rGame.ai)
					{
						return AI_WON;
					}
				}
			}

			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if ((rGame.ptrField[0][x] == rGame.ptrField[1][x]) && (rGame.ptrField[0][x] == rGame.ptrField[2][x]) && (rGame.ptrField[0][x] == rGame.ptrField[3][x]) && (rGame.ptrField[0][x] == rGame.ptrField[4][x]))
				{
					if (rGame.ptrField[0][x] == rGame.human)
					{
						return HUMAN_WON;
					}
					if (rGame.ptrField[0][x] == rGame.ai)
					{
						return AI_WON;
					}
				}
			}

			if ((rGame.ptrField[0][0] == rGame.ptrField[1][1]) && (rGame.ptrField[0][0] == rGame.ptrField[2][2]) && (rGame.ptrField[0][0] == rGame.ptrField[3][3]) && (rGame.ptrField[0][0] == rGame.ptrField[4][4]))
			{
				if (rGame.ptrField[0][0] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[0][0] == rGame.ai)
				{
					return AI_WON;
				}
			}

			if ((rGame.ptrField[0][4] == rGame.ptrField[1][3]) && (rGame.ptrField[0][4] == rGame.ptrField[2][2]) && (rGame.ptrField[0][4] == rGame.ptrField[3][1]) && (rGame.ptrField[0][4] == rGame.ptrField[4][0]))
			{
				if (rGame.ptrField[0][4] == rGame.human)
				{
					return HUMAN_WON;
				}
				if (rGame.ptrField[0][4] == rGame.ai)
				{
					return AI_WON;
				}
			}
		}

		bool tmp = true;
		for (size_t y = 0; y < rGame.SizeY; y++)
		{
			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if (rGame.ptrField[y][x] == Symbol_Zero)
				{
					tmp = false;
				}
			}
		}

		if (tmp == true)
		{
			return DRAW;
		}

		return IN_PROGRESS;
	}
}

// ввод ии
Coord getAICoord(Game& rGame)
{
	Coord Step = { 0 };
			
	if (rGame.SizeX == 3)
	{
		for (size_t y = 0; y < rGame.SizeY; y++)
		{
			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if (rGame.ptrField[y][x] == Symbol_Zero)
				{
					rGame.ptrField[y][x] = rGame.ai;
					if (WhoWin(rGame) == AI_WON)
					{
						rGame.ptrField[y][x] = Symbol_Zero;
						Step = {x, y};
						return Step;
					}
					rGame.ptrField[y][x] = Symbol_Zero;					
				}
			}
		}

		for (size_t y = 0; y < rGame.SizeY; y++)
		{
			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if (rGame.ptrField[y][x] == Symbol_Zero)
				{
					rGame.ptrField[y][x] = rGame.human;
					if (WhoWin(rGame) == HUMAN_WON)
					{
						rGame.ptrField[y][x] = Symbol_Zero;
						Step = { x, y };
						return Step;
					}
					rGame.ptrField[y][x] = Symbol_Zero;					
				}
			}
		}

		// середина
		if (rGame.ptrField[1][1] == Symbol_Zero)
		{
			Step = {1,1};
			return Step;
		}

		// края
		if (rGame.ptrField[0][0] == Symbol_Zero)
		{
			Step = { 0,0 };
			return Step;
		}

		if (rGame.ptrField[0][2] == Symbol_Zero)
		{
			Step = { 2,0 };
			return Step;
		}

		if (rGame.ptrField[2][0] == Symbol_Zero)
		{
			Step = { 0,2 };
			return Step;
		}

		if (rGame.ptrField[2][2] == Symbol_Zero)
		{
			Step = { 2,2 };
			return Step;
		}

		// остальные
		if (rGame.ptrField[1][0] == Symbol_Zero)
		{
			Step = { 0,1 };
			return Step;
		}

		if (rGame.ptrField[0][1] == Symbol_Zero)
		{
			Step = { 1,0 };
			return Step;
		}

		if (rGame.ptrField[1][2] == Symbol_Zero)
		{
			Step = { 2,1 };
			return Step;
		}

		if (rGame.ptrField[2][1] == Symbol_Zero)
		{
			Step = { 1,2 };
			return Step;
		}

	}

	if (rGame.SizeX == 4)
	{
		for (size_t y = 0; y < rGame.SizeY; y++)
		{
			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if (rGame.ptrField[y][x] == Symbol_Zero)
				{
					rGame.ptrField[y][x] = rGame.ai;
					if (WhoWin(rGame) == AI_WON)
					{
						rGame.ptrField[y][x] = Symbol_Zero;
						Step = { x, y };
						return Step;
					}
					rGame.ptrField[y][x] = Symbol_Zero;
				}
			}
		}

		for (size_t y = 0; y < rGame.SizeY; y++)
		{
			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if (rGame.ptrField[y][x] == Symbol_Zero)
				{
					rGame.ptrField[y][x] = rGame.human;
					if (WhoWin(rGame) == HUMAN_WON)
					{
						rGame.ptrField[y][x] = Symbol_Zero;
						Step = { x, y };
						return Step;
					}
					rGame.ptrField[y][x] = Symbol_Zero;					
				}
			}
		}
				
		// края
		if (rGame.ptrField[0][0] == Symbol_Zero)
		{
			Step = { 0,0 };
			return Step;
		}

		if (rGame.ptrField[3][0] == Symbol_Zero)
		{
			Step = { 0,3 };
			return Step;
		}

		if (rGame.ptrField[0][3] == Symbol_Zero)
		{
			Step = { 3,0 };
			return Step;
		}

		if (rGame.ptrField[3][3] == Symbol_Zero)
		{
			Step = { 3,3 };
			return Step;
		}

		// середина
		if (rGame.ptrField[1][1] == Symbol_Zero)
		{
			Step = { 1,1 };
			return Step;
		}

		if (rGame.ptrField[2][1] == Symbol_Zero)
		{
			Step = { 1,2 };
			return Step;
		}

		if (rGame.ptrField[1][2] == Symbol_Zero)
		{
			Step = { 2,1 };
			return Step;
		}

		if (rGame.ptrField[2][2] == Symbol_Zero)
		{
			Step = { 2,2 };
			return Step;
		}

		// остальные клетки
		if (rGame.ptrField[1][0] == Symbol_Zero)
		{
			Step = { 0,1 };
			return Step;
		}

		if (rGame.ptrField[0][1] == Symbol_Zero)
		{
			Step = { 1,0 };
			return Step;
		}

		if (rGame.ptrField[2][0] == Symbol_Zero)
		{
			Step = { 0,2 };
			return Step;
		}
		
		if (rGame.ptrField[0][2] == Symbol_Zero)
		{
			Step = { 2,0 };
			return Step;
		}

		if (rGame.ptrField[3][1] == Symbol_Zero)
		{
			Step = { 1,3 };
			return Step;
		}

		if (rGame.ptrField[1][3] == Symbol_Zero)
		{
			Step = { 3,1 };
			return Step;
		}

		if (rGame.ptrField[2][3] == Symbol_Zero)
		{
			Step = { 3,2 };
			return Step;
		}

		if (rGame.ptrField[3][2] == Symbol_Zero)
		{
			Step = { 2,3 };
			return Step;
		}
	}

	else
	{
	
		for (size_t y = 0; y < rGame.SizeY; y++)
		{
			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if (rGame.ptrField[y][x] == Symbol_Zero)
				{
					rGame.ptrField[y][x] = rGame.ai;
					if (WhoWin(rGame) == AI_WON)
					{
						rGame.ptrField[y][x] = Symbol_Zero;
						Step = { x, y };
						return Step;
					}
					rGame.ptrField[y][x] = Symbol_Zero;
				}
			}
		}

		for (size_t y = 0; y < rGame.SizeY; y++)
		{
			for (size_t x = 0; x < rGame.SizeX; x++)
			{
				if (rGame.ptrField[y][x] == Symbol_Zero)
				{
					rGame.ptrField[y][x] = rGame.human;
					if (WhoWin(rGame) == HUMAN_WON)
					{
						rGame.ptrField[y][x] = Symbol_Zero;
						Step = { x, y };
						return Step;
					}
					rGame.ptrField[y][x] = Symbol_Zero;
				}
			}
		}

		// середина
		if (rGame.ptrField[2][2] == Symbol_Zero)
		{
			Step = { 2,2 };
			return Step;
		}
		
		// края
		if (rGame.ptrField[0][0] == Symbol_Zero)
		{
			Step = { 0,0 };
			return Step;
		}

		if (rGame.ptrField[0][4] == Symbol_Zero)
		{
			Step = { 4,0 };
			return Step;
		}

		if (rGame.ptrField[4][0] == Symbol_Zero)
		{
			Step = { 0,4 };
			return Step;
		}

		if (rGame.ptrField[4][4] == Symbol_Zero)
		{
			Step = { 4,4 };
			return Step;
		}

		// вокруг середины
		if (rGame.ptrField[1][1] == Symbol_Zero)
		{
			Step = { 1,1 };
			return Step;
		}

		if (rGame.ptrField[1][2] == Symbol_Zero)
		{
			Step = { 2,1 };
			return Step;
		}

		if (rGame.ptrField[2][1] == Symbol_Zero)
		{
			Step = { 1,2 };
			return Step;
		}

		if (rGame.ptrField[1][3] == Symbol_Zero)
		{
			Step = { 3,1 };
			return Step;
		}

		if (rGame.ptrField[3][1] == Symbol_Zero)
		{
			Step = { 1,3 };
			return Step;
		}

		if (rGame.ptrField[2][3] == Symbol_Zero)
		{
			Step = { 3,2 };
			return Step;
		}

		if (rGame.ptrField[3][2] == Symbol_Zero)
		{
			Step = { 2,3 };
			return Step;
		}

		if (rGame.ptrField[3][3] == Symbol_Zero)
		{
			Step = { 3,3 };
			return Step;
		}

		//остальное
		if (rGame.ptrField[1][0] == Symbol_Zero)
		{
			Step = { 0,1 };
			return Step;
		}

		if (rGame.ptrField[0][1] == Symbol_Zero)
		{
			Step = { 1,0 };
			return Step;
		}

		if (rGame.ptrField[2][0] == Symbol_Zero)
		{
			Step = { 0,2 };
			return Step;
		}

		if (rGame.ptrField[0][2] == Symbol_Zero)
		{
			Step = { 2,0 };
			return Step;
		}

		if (rGame.ptrField[3][0] == Symbol_Zero)
		{
			Step = { 0,3 };
			return Step;
		}

		if (rGame.ptrField[0][3] == Symbol_Zero)
		{
			Step = { 3,0 };
			return Step;
		}

		if (rGame.ptrField[1][4] == Symbol_Zero)
		{
			Step = { 4,1 };
			return Step;
		}

		if (rGame.ptrField[2][4] == Symbol_Zero)
		{
			Step = { 4,2 };
			return Step;
		}

		if (rGame.ptrField[3][4] == Symbol_Zero)
		{
			Step = { 4,3 };
			return Step;
		}

		if (rGame.ptrField[4][1] == Symbol_Zero)
		{
			Step = { 1,4 };
			return Step;
		}

		if (rGame.ptrField[4][2] == Symbol_Zero)
		{
			Step = { 2,4 };
			return Step;
		}

		if (rGame.ptrField[4][3] == Symbol_Zero)
		{
			Step = { 3,4 };
			return Step;
		}

	}
}

// удаление памяти
void DeleteMemory(Game& rGame)
{
	for (size_t i = 0; i < rGame.SizeY; i++)
	{
		delete[] rGame.ptrField[i];
	}
	delete[] rGame.ptrField;
	rGame.ptrField = nullptr;

	return;
}

// основной модуль
int main()
{
	setlocale(LC_ALL, "Russian"); // локализация
	ClearField();
	Game game;

	do
	{
		cout << "Введите размер игрового поля (3x3, 4х4 или 5х5, вводить нужно 1 цифру): ";
		cin >> game.SizeX;
	} while ((game.SizeX < 3) || (game.SizeX > 5));
	game.SizeY = game.SizeX;

	game.complexity = 0;

	if (game.SizeY == 4)
	{
		do
		{
			cout << "Введите сложность игры (1, в случае победы комбинаций из 3 символов, 2 - из 4): ";
			cin >> game.complexity;
		} while ((game.complexity < 1) || (game.complexity > 2));
	}

	if (game.SizeY == 5)
	{
		do
		{
			cout << "Введите сложность игры (1, в случае победы комбинаций из 3 символов, 2 - из 4, 3 - из 5): ";
			cin >> game.complexity;
		} while ((game.complexity < 1) || (game.complexity > 3));
	}
	
	long long time1 = GetTickCount64();
	
	InitMemory(game);
	PrintField(game);
	
	game.turn = (game.humanfirst) ? 0 : 1;
	cout << endl;	
		
	while (game.Progress == IN_PROGRESS)
	{
		if (game.turn % 2 == 0)
		{
			Coord Step = getPlayerCoord(game);
			game.ptrField[Step.y][Step.x] = game.human;
		}

		else
		{
			Coord Step = getAICoord(game);
			game.ptrField[Step.y][Step.x] = game.ai;
		}

		ClearField();
		PrintField(game);
		game.turn ++;

		game.Progress = WhoWin(game);		
	}

	long long time2 = GetTickCount64();
	long long winnig_time = int(float(time2 - time1) / 1000);

	if (game.Progress == HUMAN_WON)
	{
		cout << endl << "Поздравляем! Вы выиграли!" << endl;
		cout << "Игра длилась " << winnig_time << " сек" << endl;
		cin.get();
	}

	if (game.Progress == AI_WON)
	{
		cout << endl << "Выиграл компьютер!" << endl;
		cout << "Игра длилась " << winnig_time << " сек" << endl;
		cin.get();
	}
	
	if (game.Progress == DRAW)
	{
		cout << endl << "НИЧЬЯ!" << endl;
		cout << "Игра длилась " << winnig_time << " сек" << endl;
		cin.get();
	}	

	cin.get();

	DeleteMemory(game);
}


