/*
Колпакова Е., OOP Lesson 3, Visual Studio Code
1.	Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), 
Rhombus (ромб). Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь). Во всех остальных классах переопределить эту функцию, исходя из геометрических формул 
нахождения площади.
2.	Создать класс Car (автомобиль) с полями company (компания) и model (модель). Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов наследует класс Minivan (минивэн). 
Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. Обратить внимание на 
проблему «алмаз смерти».
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.
3.	Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
●	математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
●	унарный оператор (-)
●	логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
Продемонстрировать использование перегруженных операторов.
4.	Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой). Сделать поля масть и значение карты типом перечисления (enum).
Положение карты - тип bool. Также в этом классе должно быть два метода:
●	метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
●	метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/

#include <iostream>
#include <math.h>
#include <string>  

using namespace std;

/*
1.	Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), 
Rhombus (ромб). Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь). Во всех остальных классах переопределить эту функцию, исходя из геометрических формул 
нахождения площади.
*/

//будучи хлебушком после работы сверяла формулы тут https://ege-study.ru/ru/ege/materialy/matematika/formuly-geometrii/
class Figure
{
public:
    virtual int area() = 0;
};

class Parallelogram: public Figure
{
private:
    int m_height;
    int m_length;
public:
    Parallelogram (int height = 0, int length = 0)
    : m_height(height), m_length(length) {}
    
    int area()
    {
        return m_height * m_length;
    }

};

class Rectangle: public Parallelogram
{
public:
    Rectangle(int height = 0, int length = 0)
        :Parallelogram(height, length) {}
};

class Square: public Parallelogram
{
public:
    Square(int height = 0)
        :Parallelogram(height, height) {}
};

class Rhombus: public Parallelogram
{
public:
    Rhombus(int height = 0, int length = 0)
        :Parallelogram(height, length) {}
};

class Circle: public Figure
{
private:
    int m_r;
    const double pi = 3.14;
public:
    Circle(int r = 0)
        : m_r(r) {}
    
    int area()
    {
        return pi * pow(m_r,2);
    }
};

void Task1()
{
    Circle circle(5);
    Rectangle rectangle(5, 8);
    Square square(4);
    Rhombus rhombus(3, 5);
    
    cout << "Task 1." << endl << endl;
    cout << "Circle area: " << circle.area() << endl;
    cout << "Rectangle area: " << rectangle.area() << endl;
    cout << "Square area: " << square.area() << endl;
    cout << "Rhombus area: " << rhombus.area() << endl << endl;

    return; //да, я знаю, что vsc нормально компилирует и без него. но, если запускать не в vsc может быть ошибка. мы проверяли на введении в с++
}

/*
2.	Создать класс Car (автомобиль) с полями company (компания) и model (модель). Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов наследует класс Minivan (минивэн). 
Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. Обратить внимание на 
проблему «алмаз смерти».
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.
*/

class Car
{
protected:
    string m_company;
    string m_model;

public:
    Car(string company = "", string model = "")
        :m_company(company), m_model(model)
    {
        cout << "Car " << m_company << ", " << m_model << endl;
    }

}; 

class PassengerCar: virtual public Car
{
public:
    PassengerCar(string company = "", string model = "")
        :Car(company, model)
    {
        cout << "PassengerCar " << m_company << ", " << m_model << endl;
    }
};

class Bus: virtual public Car
{
public:
    Bus(string company = "", string model = "")
        :Car(company, model)
    {
        cout << "Bus " << m_company << ", " << m_model << endl;
    }
};

class Minivan: public PassengerCar, public Bus
{
public:
    Minivan(string company = "", string model = "")
        :Car(company, model), PassengerCar(company, model), Bus (company, model)
    {
        cout << "Minivan " << m_company << ", " << m_model << endl;
    }
};

void Task2()
{
    cout << "Task 2." << endl << endl;
    
    Car Car("LADA", "VESTA");
    cout << endl;
    PassengerCar  PassengerCar("AUDI", "Q3");
    cout << endl;
    Bus Bus("Mercedes-Benz", "Tourismo");
    cout << endl;
    Minivan("Opel", "Combo Life");
    cout << endl;

    return;
}

/*
3.	Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
●	математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
●	унарный оператор (-)
●	логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
Продемонстрировать использование перегруженных операторов.
*/

class Fraction
{
protected:
    double m_numerator;
    double m_denominator;

public:
    Fraction(int numerator, int denominator)
    {
        if (denominator != 0)
        {
            m_numerator = numerator; 
            m_denominator = denominator;
        }
        else throw runtime_error("ERROR! Denominator can't be NULL");
    }

    friend Fraction operator+(const Fraction& d1, const Fraction& d2);
    friend Fraction operator-(const Fraction& d1, const Fraction& d2);
    friend Fraction operator*(const Fraction& d1, const Fraction& d2);
    friend Fraction operator/(const Fraction& d1, const Fraction& d2);
    friend bool operator> (const Fraction& d1, const Fraction& d2);
    friend bool operator>= (const Fraction& d1, const Fraction& d2);
    friend bool operator<(const Fraction& d1, const Fraction& d2);
    friend bool operator<=(const Fraction& d1, const Fraction& d2);

    int getNumerator() const { return m_numerator; }
    int getDenominator() const { return m_denominator; }

    Fraction operator-() const
    {
        return Fraction(-m_numerator, m_denominator);
    }    
};

Fraction operator+ (const Fraction& d1, const Fraction& d2)
{
    return Fraction((d1.m_numerator * d2.m_denominator + d2.m_numerator * d1.m_denominator), d1.m_denominator * d2.m_denominator);
}

Fraction operator- (const Fraction& d1, const Fraction& d2)
{
    return Fraction((d1.m_numerator * d2.m_denominator - d2.m_numerator * d1.m_denominator), d1.m_denominator * d2.m_denominator);
}

Fraction operator* (const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.m_numerator * d2.m_numerator, d1.m_denominator * d2.m_denominator);
}

Fraction operator/ (const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.m_numerator * d2.m_denominator, d1.m_denominator * d2.m_numerator);
}

bool operator> (const Fraction& d1, const Fraction& d2)
{
    return ((d1.m_numerator / d1.m_denominator) > (d2.m_numerator / d2.m_denominator));
}

bool operator>= (const Fraction& d1, const Fraction& d2)
{
    return ((d1.m_numerator / d1.m_denominator) >= (d2.m_numerator / d2.m_denominator));
}

bool operator<(const Fraction& d1, const Fraction& d2)
{
    return !((d1.m_numerator / d1.m_denominator) >= (d2.m_numerator / d2.m_denominator));
}

bool operator<=(const Fraction& d1, const Fraction& d2)
{
    return !((d1.m_numerator / d1.m_denominator) > (d2.m_numerator / d2.m_denominator));
}

void Task3()
{
    cout << "Task 3." << endl << endl;
    
    Fraction fraction1(5, 7);
    Fraction fraction2(2, 5);
    
    // сумма
    Fraction FractionSum = fraction1 + fraction2;
    cout << "Sum: " << FractionSum.getNumerator() << "/" << FractionSum.getDenominator() << endl;

    //разница
    Fraction FractionDifference = fraction1 - fraction2;
    cout << "Difference: " << FractionDifference.getNumerator() << "/" << FractionDifference.getDenominator() << endl;

    //умножение
    Fraction FractionMultiplication = fraction1 * fraction2;
    cout << "Multiplication: " << FractionMultiplication.getNumerator() << "/" << FractionMultiplication.getDenominator() << endl;

    //деление
    Fraction FractionDivision = fraction1 / fraction2;
    cout << "Division: " << FractionDivision.getNumerator() << "/" << FractionDivision.getDenominator() << endl;

    //унарный оператор (-)
    Fraction FractionMinus = -fraction1;
    cout << "Minus: " << FractionMinus.getNumerator() << "/" << FractionMinus.getDenominator() << endl;
    
    //операторы сравнения
    
    if (fraction1 > fraction2)
    {
        cout << "fraction1 > fraction2" << endl;
    }

    if (fraction1 < fraction2)
    {
        cout << "fraction1 < fraction2" << endl;
    }

    if (fraction1 >= fraction2)
    {
        cout << "fraction1 >= fraction2" << endl;
    }

    if (fraction1 <= fraction2)
    {
        cout << "fraction1 <= fraction2" << endl;
    }

    return;
}

/*
4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой). Сделать поля масть и значение карты типом перечисления (enum).
Положение карты - тип bool. Также в этом классе должно быть два метода:
●	метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
●	метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/

class Card
{
public:
    enum SUIT { HEART, CLUB, DIAMOND, SPADE };
    enum VALUE { ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, QUEN = 10, KING = 10};

private:
    SUIT m_suit;
    VALUE m_value;
    bool m_position;

public:
    Card(SUIT s = CLUB, VALUE v = ACE, bool position = 0)
        :m_suit(s), m_value(v), m_position(position) {}
    
    bool Flip()
    {
        m_position = !(m_position);
    }
    
    int GetValue()
    {
        int value = 0;
        if (m_position)
        {
            value = m_value;
        }
        
        return value;
    }

};


int main()
{
   Task1();
   Task2();
   Task3();
}