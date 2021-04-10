/* Колпакова Е., OOP Lesson 1, Visual Studio Code
1.	Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. Еще создать два метода: один с именем set, 
который позволит присваивать значения переменным, второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.
2.	Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). Задать 0 в качестве значения 
по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. 
Написать функцию print(), которая будет выводить значения переменных-членов.
3.	Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
●	private-массив целых чисел длиной 10;
●	private целочисленное значение для отслеживания длины стека;
●	public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
●	public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
●	public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
●	public-метод с именем print(), который будет выводить все значения стека.
Код main():
int main()
{
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}

Этот код должен выводить:
( )
( 3 7 5 )
( 3 7 )
( )

*/

#include <iostream>
#include <cmath>
#include <cstdint>
#include <cassert>

using namespace std;

// проверка корректности введенных символов
bool CheckSymbol()
{
    if (cin.fail()) // если предыдущее извлечение оказалось неудачным,
    {
        cin.clear(); // то возвращаем cin в 'обычный' режим работы
        cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
        cout << "Please enter correct value" << endl;
        return false;
    }
    else return true;    
}


//#1
/*Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. Еще создать два метода: один с именем set, 
который позволит присваивать значения переменным, второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.*/
class Power
{
private:
    double Number_1 = 5.4;
    double Number_2 = 4.2;
public:
    void setNumber(double number1, double number2)
    {
        Number_1 = number1;
        Number_2 = number2;
        cout << "Number 1 = " << Number_1 << ", Number 2 = " << Number_2 << endl;
    }
    double calculatePower()
    {
        double result;
        result = pow(Number_1, Number_2);
        return result;
    }
};

//#2
/*Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). Задать 0 в качестве значения 
по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. 
Написать функцию print(), которая будет выводить значения переменных-членов.*/
class RGBA
{
private: //я поменяла uint8_t на uint16_t, т.к. у меня почему-то обрезались значения для uint8_t (к примеру, 10 становилось 1. Так и не поняла почему, тк в описании типа указано, что 8t - от 0 до 255
    uint16_t m_red = 0;
    uint16_t m_green = 0;
    uint16_t m_blue = 0;
    uint16_t m_alpha = 255;

public:
    RGBA (uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
        :m_red (red), m_green (green), m_blue (blue), m_alpha (alpha)
    {
        //пустое ничего
    }    

    void printColor()
    {
        cout << endl << "red: " << m_red << ", green: " << m_green << ", blue: " << m_blue << ", alpha: " << m_alpha << endl;
    }
};

// #3
/*Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
private-массив целых чисел длиной 10;
private целочисленное значение для отслеживания длины стека;*/

class Stack
{
private:
    int* m_StackArray;
    int m_length; 
    
public:
    Stack()
        :m_length(10)
    {
        m_StackArray = new int[m_length];       
        
    }

    ~Stack ()
    {
        delete[] m_StackArray;
    }

    
    // public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
    void reset() 
    {
        for (int i = 0; i < m_length; i++)
        {
            m_StackArray[i] = 0;
        }
        m_length = 0;
        return;
    };

    // public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
    bool push(int Number) 
    {
        if (m_length == 10 && m_StackArray[9] != 0)
        {
            cout << "Array is FULL. Can't put value: " << Number << endl;
            return false;
        }
        else
        {
            if (m_length < 10)
            {         
                m_length++;                
            }
            m_StackArray[m_length - 1] = Number;
            return true;
        }

    };

    //public - метод с именем pop() для вытягивания и возврата значения из стека.Если в стеке нет значений, то должно выводиться предупреждение;
    void pop() 
    {
        if (m_length == 0)
        {
            cout << "No values in Stack" << endl;
        }
        else
        {
            m_StackArray[m_length-1] = 0;
            m_length--;
        }
        return;
    };

    //public - метод с именем print(), который будет выводить все значения стека.
    void print() 
    {
        cout << "( ";
        for (int i = 0; i < m_length; i++)
        {
            if (m_length != 0)
            {
                cout << m_StackArray[i] << " ";
            }            
        }
        cout << ")" << endl;
    };


};

void Task1()
{
    Power PowNumbers;
    double number1, number2;
    bool check;

    do {
        cout << "Please, enter Number 1: ";
        cin >> number1;
        check = CheckSymbol();
    } while (check == false);

    do {
        cout << "Please, enter Number 2: ";
        cin >> number2;
        check = CheckSymbol();
    } while (check == false);

    PowNumbers.setNumber(number1, number2);
    cout << "Number 1 to the Number 2 power: " << PowNumbers.calculatePower() << endl;
    
    return;
}

void Task2()
{
    bool check;
    uint16_t red, green, blue, alpha;

    cout << endl;

    do {
        cout << "Please, enter value of red color: ";
        cin >> red;
        check = CheckSymbol();
    } while (check == false);

    do {
        cout << "Please, enter value of green color: ";
        cin >> green;
        check = CheckSymbol();
    } while (check == false);

    do {
        cout << "Please, enter value of blue color: ";
        cin >> blue;
        check = CheckSymbol();
    } while (check == false);

    cout << "Please, enter value of alpha: ";
    cin >> alpha;

    RGBA Colors(red, green, blue, alpha);
    Colors.printColor();

    cout << endl;

    return;
}

void Task3()
{
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);    
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return;
}

int main()
{
    //#1
   Task1();
    //#2
   Task2();
   //#3
   Task3();   

   return 0; 
}
