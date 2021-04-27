/*
* Колпакова Е., OOP Lesson 5, Visual Studio Code
1.	Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
Следующий код:
int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}

… должен производить результат:
Pair: 6 9
Pair: 3.4 7.8
2.	Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
Следующий код:
int main()
{
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}

… должен производить следующий результат:
Pair: 6 7.8
Pair: 3.4 5
Подсказка: чтобы определить шаблон с использованием двух разных типов, просто разделите параметры типа шаблона запятой.
3.	Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа. Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string, а второй — любого типа данных.
 
Следующий код:
int main()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}

… должен производить следующий результат:
Pair: Amazing 7
Подсказка: при вызове конструктора класса Pair из конструктора класса StringValuePair не забудьте указать, что параметры относятся к классу Pair.

4.	Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер. Создать класс GenericPlayer, в который добавить поле name - имя игрока. Также добавить 3 метода:
●	IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
●	IsBoosted() - возвращает bool значение, есть ли у игрока перебор
●	Bust() - выводит на экран имя игрока и объявляет, что у него перебор.

*/

#include <iostream>
#include <string> 
#include <vector>

using namespace std;

/*
1.	Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
Следующий код:
int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}

… должен производить результат:
Pair: 6 9
Pair: 3.4 7.8
*/

template <typename T>
class Pair1
{
private:
    T m_a;
    T m_b;

public:
    Pair1 (const T& a, const T& b)
    : m_a(a), m_b(b)   {}

    const T& first() const { return m_a; }
    const T& second() const { return m_b; }
};

void Task1()
{
    cout << "Task 1" << endl;

    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    cout << endl;

    return;
}

/*
Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
Следующий код:
int main()
{
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}

… должен производить следующий результат:
Pair: 6 7.8
Pair: 3.4 5
*/

template <class V, class S>
class Pair
{
private:
    V m_c;
    S m_d;

public:
    Pair(const V& c, const S& d)
        : m_c(c), m_d(d)  {}

   const V& first() const { return m_c; }
   const S& second() const { return m_d; }
};

void Task2()
{
    cout << "Task 1" << endl;

    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    cout << endl;

    return;
}

/*
3.	Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа. Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string, а второй — любого типа данных.
 
Следующий код:
int main()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}

… должен производить следующий результат:
Pair: Amazing 7
Подсказка: при вызове конструктора класса Pair из конструктора класса StringValuePair не забудьте указать, что параметры относятся к классу Pair.
*/

template <class F>
class StringValuePair : public Pair<string, F>
{
public:
    StringValuePair(const string& N, const F& num)
        : Pair<string, F>(N, num)    {}
};

void Task3()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return;
}

/*
4.	Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер. Создать класс GenericPlayer, в который добавить поле name - имя игрока. Также добавить 3 метода:
●	IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
●	IsBoosted() - возвращает bool значение, есть ли у игрока перебор
●	Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
*/

class Card
{
public:
    enum SUIT { HEART, CLUB, DIAMOND, SPADE };
    enum VALUE { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEN, KING };

private:
    SUIT m_suit;
    VALUE m_value;
    bool m_position;

public:
    Card(SUIT s = CLUB, VALUE v = ACE, bool position = 1)
        :m_suit(s), m_value(v), m_position(position) {}

    ~Card() {}

    // метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
    void Flip()
    {
        m_position = !(m_position);
    }

    // метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
    int GetValue()
    {
        int value = 0;
        if (value > 10)
        {
            value = 10;
        }

        return value;
    }

};


class Hand
{
public:
    Hand() {}
    ~Hand() { clear(); }

private:
    vector<Card*> m_cards;

public:

    // метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
    void add(Card* pCard)
    {
        m_cards.push_back(pCard);
    }

    // метод Clear, который очищает руку от карт
    void clear()
    {
        for (Card* card : m_cards)
        {
            delete card;
            card = nullptr;
        }
    }

    // метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11)
    int getValue() const
    {
        int value = 0;
        bool ifAce = false;
        for (int i = 0; i < m_cards.size(); i++)
        {
            int cardValue = m_cards.at(i)->GetValue();
            if (cardValue > 10)
            {
                cardValue = 10;
            }
            if (cardValue == 1)
            {
                ifAce = true;
            }
            value += cardValue;
        }
        if (ifAce && value < 12) value += 10;
        return value;
    }

};

class GenericPlayer: public Hand 
{
private:
    string m_name;
    Hand m_player;
public:
    GenericPlayer(string name)
        :m_name(name) {}

//  IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
    virtual void IsHitting() = 0;
    //этот пункт не особо поняла..

//  IsBoosted() - возвращает bool значение, есть ли у игрока перебор
    bool IsBoosted()
    {        
        int playerValue = m_player.getValue();
        if (playerValue > 21) return 1;
        else return 0;
    }

//  Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
    void Bust()
    {
        int playerValue = m_player.getValue();
        if (IsBoosted())
        {
            cout << m_name << "You got bust!" << endl;
        }
    }

};

int main()
{
    //#1 
   // Task1();

    //#2
    //Task2();
    
    //#3
    Task3();
}
