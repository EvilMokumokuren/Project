/* Колпакова Е., OOP Lesson 2, Visual Studio Code
1.	Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, изменения возраста и веса. Создать производный класс Student (студент), имеющий поле года обучения. 
Определить методы переназначения и увеличения этого значения. Создать счетчик количества созданных студентов. В функции main() создать несколько студентов. По запросу вывести определенного человека.
2.	Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить новый класс GrannySmith, который наследует класс Apple.
int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}

Код, приведенный выше, должен давать следующий результат:

      My apple is red.
My banana is yellow.
My Granny Smith apple is green.

3.	Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование. Сколько будет классов в программе? Какие классы будут базовыми, 
а какие производными? Продумать реализацию игры с помощью классов и записать результаты.

*/

#include <iostream>
#include <string>  

using namespace std;

/*1.	Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, изменения возраста и веса. Создать производный класс Student (студент), имеющий поле года обучения. 
Определить методы переназначения и увеличения этого значения. Создать счетчик количества созданных студентов. В функции main() создать несколько студентов. По запросу вывести определенного человека.*/
class Person
{
protected:
    string m_name;
    int m_age;
    string m_gender;
    double m_weight;

public:
    Person(string name = "", int age = 0, string gender = "", double weight = 0)
        : m_name(name), m_age(age), m_gender(gender), m_weight(weight)
    { }

    void SetName(string name)
    {
        m_name = name;
        return;
    };

    void SetAge(int age)
    {
        m_age = age;
        return;
    }

    void SetWeight(double weight)
    {
        m_weight = weight;
        return;
    }

};

class Student: public Person
{
private:
    int m_year;
    static int m_count;
    int m_temp;

public:
    Student(string name = "", int age = 0, string gender = "", double weight = 0, int year = 0)
        : m_year(year), Person(name, age, gender, weight)
    { 
        m_temp = m_count++;
    }

    void SetYear(int year)
    {
        m_year = year;
        return;
    }

    void IncreaseYear(int year)
    {
        m_year += year;
        return;
    }
    
    void PrintStudent() const
    {
        cout << "Number: " << m_count << endl << "Student: " << m_name << endl << "Age: " << m_age << endl << "Genger: " << m_gender << endl << "Weigth: " << m_weight << endl << "Year: " << m_year << endl << endl;
        return;
    }
};

int Student::m_count = 0; // счетчик начинается с 0, при создании первого студента = 1, далее увеличивается

void Task1()
{
    Student Oleg("Oleg", 18, "Male", 65.5, 1);
    Oleg.PrintStudent();
    
    Student Irina("Irina", 21, "Female", 45, 3);
    Irina.PrintStudent();

    Student Rose("Rose", 45, "Transgender", 78, 2);
    Rose.PrintStudent();

    return;
}


/*2.	Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить новый класс GrannySmith, который наследует класс Apple.
int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}

Код, приведенный выше, должен давать следующий результат:

      My apple is red.
My banana is yellow.
My Granny Smith apple is green.
*/

class Fruit
{
protected:
    string m_name;
    string m_color;
    
public:
    Fruit(string name = "apple", string color = "")
        :m_name(name), m_color(color)
    { }

    string getName() const
    {
        return m_name;
    }

    string getColor() const
    {
        return m_color;
    }

};

class Banana : public Fruit
{
public:
    Banana(string color = "yellow")
        : Fruit("banana", color)
    { } 
};

class Apple : public Fruit
{
public:
    Apple(string color = "")
        : Fruit("apple", color)
    { }    
};

class GrannySmith : public Apple
{
public:
    GrannySmith()
        :Apple("green")
    {
       m_name = "GrannySmith apple";       
    }
};

void Task2()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return;
}

/*3.	Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование. Сколько будет классов в программе? Какие классы будут базовыми, 
а какие производными? Продумать реализацию игры с помощью классов и записать результаты.*/

//я впервые читаю правила игры в блэкджек =), так что вышло не очень
class Card //согласно правилам, есть колода карт, и у каждой карты какое-то количество очков. соответственно нам надо для каждой карты задать эти очки
{
    string m_Card; //масть карты и название, 
    int m_Point; //количество очков. при этом, там нужно будет условие, т.к. туз может быть 11 или 1, в зависимости от преимущества
};

class Deck // массив карт
{
    //массив карт, которые еще ни у кого из участников (используется class Card) 
    int m_current; //указатель на текущую карту, что б вытаскивать из колоды
};

class Hand // рука игрока или "дилера"
{
    // массив из карт, которые на руках.  (используется class Card)   
};

class Deckpile   //тасование колоды и раздача
{
    // массив из оставшихся карт
    //тасование
};

class Process
{
    int SumPoints; // сумма очков. соответственно нужно проверять, есть "перенасыщение" или нет, есть ли выигрыш (21 очко)
    //нужно понимать берет карту игрок еще или нет
    //
};

class Player // игрок
{
  //+ class Process
   string name; //имя
   int rate; // ставка
};

class AI // вот не знаю, что дать ИИ
{
   //+ class Process
};

class Game
{
    //тело игры
};

int main()
{
    Task1();
    Task2();
}


