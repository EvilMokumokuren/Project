/* Lesson 8.cpp 
1.	Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero, если второй параметр равен 0. 
В функции main выводить результат вызова функции div в консоль, а также ловить исключения.
2.	Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, инициализирующий x значением параметра. Написать класс Bar, 
хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a. Если y + a > 100, 
возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a. В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n. 
Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
3.	Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на соседнюю позицию. 
Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда (направление не находится в 
нужном диапазоне). Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения. Написать функцию main, пользующуюся этим классом и 
перехватывающую все исключения от его методов, а также выводящую подробную информацию о всех возникающих ошибках.
*/

#include <iostream>
#include <string>
using namespace std;

/*
1.	Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero, если второй параметр равен 0.
В функции main выводить результат вызова функции div в консоль, а также ловить исключения.
*/

template <typename T>
const T& div(const T& a, const T& b)
{
    if (b == 0)
    {
        throw "Can't div by zero!";              
    }
    else return (a / b);
}

void Task1()
{
    cout << "Task 1" << endl;

    double a, b;

    cout << "Please, enter a: ";
    cin >> a;
    cout << "Please, enter b (not zero): ";
    cin >> b;
    try
    {
        div(a, b);
    }
    catch (const char* exception) // обработка исключений типа const char*
    {
        cerr << "Error: " << exception << endl;
    }    
}

/*
2.	Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, инициализирующий x значением параметра. Написать класс Bar,
хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a. Если y + a > 100,
возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a. В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
*/

class Ex
{
public:
    double m_x;
    Ex(const double& x) 
    : m_x(x) {}
    
    ~Ex() {}
};

class Bar
{
private:
    double y;

public:
    Bar() 
    { 
        y = 0; 
    }
    ~Bar() {}

    void set(const double& a)
    {
        if ((y + a) > 100)
        {
            throw Ex(y * a);        
        }
        else
        {
            y = a;
        }
    }

};

void Task2()
{
    cout << "Task 2" << endl;

    Bar b;
    int number;
    
    cout << "Please, enter number < 101: ";
    cin >> number;

        try
        {
            b.set(number);
        }
        catch (Ex& err)
        {
            cerr << "Exception: ay " << err.m_x << std::endl;
        }   
}

/*
3.	Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на соседнюю позицию.
Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда (направление не находится в
нужном диапазоне). Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения. Написать функцию main, пользующуюся этим классом и
перехватывающую все исключения от его методов, а также выводящую подробную информацию о всех возникающих ошибках.
*/

const int Zero_coord = 0;
const int Max_field = 10;

class Ex_Task3
{
public:
    void OffTheField(int x, int y, string com)
    {
        cout << endl << "OffTheField" << endl << "Last command:" << com << endl << "Coord x:" << x << endl << "Coord y:" << y << endl << endl;
    }

    void IllegalCommand(string com)
    {
        cout << endl << "IllegalCommand" << endl << endl;
    }
};

class Robot
{
protected:
    int m_x, m_y;
    
public:
    Robot()
    {
        m_x = 0;
        m_y = 0;
    }
    
    void output() const
    {
        cout << "Coordinates:" << m_x << ", " << m_y << endl;
    }

    void GoUp()
    {
        if ((m_y +1) > Max_field)
        {
            Ex_Task3 temp;
            temp.OffTheField(m_x, m_y, "GoUp");
        }
        else m_y++;
        output();
    }

    void GoDown()
    {
        if ((m_y - 1) < Zero_coord)
        {
            Ex_Task3 temp;
            temp.OffTheField(m_x, m_y, "GoDown");
        }
        else m_y--;
        output();
    }

    void GoRight()
    {
        if ((m_x +1) < Max_field)
        {
            Ex_Task3 temp;
            temp.OffTheField(m_x, m_y, "GoRight");
        }
        else m_x++;
        output();
    }

    void GoLeft()
    {
        if ((m_x -1) < Zero_coord)
        {
            Ex_Task3 temp;
            temp.OffTheField(m_x, m_y, "GoLeft");
        }
        else m_x--;
        output();
    }
};

void Task3()
{
    string command;
    Robot robot;
    bool work = true;

    do
    {
        cout << "Hello! This is Robot control program. Please enter: " << endl << "'up', if you want to go up" << endl << "'down', if you want to go down"
            << endl << "'left', if you want to go left" << endl << "'right', if you want to go right" << endl << "exit, if you want to quit programm" << endl;
        cout << "Command: ";
        cin >> command;
                
            if ((command == "up") || (command == "Up") || (command == "UP"))
            {
                robot.GoUp();
            }

            if ((command == "down") || (command == "Down") || (command == "DOWN"))
            {
                robot.GoDown();
            }

            if ((command == "left") || (command == "Left") || (command == "LEFT"))
            {
                robot.GoLeft();
            }

            if ((command == "right") || (command == "Right") || (command == "RIGHT"))
            {
                robot.GoRight();
            }

            if ((command == "exit") || (command == "Exit") || (command == "EXIT"))
            {
                cout << "Goodbye";
                work = false;
            }

            else
            {                
                Ex_Task3 a;
                a.IllegalCommand(command);
            }             
    } while (work == true);
}

int main()
{
   // Task1();
   // Task2();
    Task3();


    return 0;
}
