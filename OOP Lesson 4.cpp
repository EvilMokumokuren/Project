/*
Колпакова Е., OOP Lesson 4, Visual Studio Code
1.	Добавить в контейнерный класс, который был написан в этом уроке, методы:
●	для удаления последнего элемента массива (аналог функции pop_back() в векторах)
●	для удаления первого элемента массива (аналог pop_front() в векторах)
●	для сортировки массива
●	для вывода на экран элементов.
2.	Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм.
3.	Реализовать класс Hand, который представляет собой коллекцию карт. В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card). Также в классе Hand должно быть 3 метода:
●	метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
●	метод Clear, который очищает руку от карт
●	метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).

*/

#include <iostream>
#include <vector>
#include <cassert> // для assert()
#include <set>

using namespace std;

/*Контейнерный класс из методички*/
class ArrayInt
{
private:
    size_t m_length;
    int* m_data;
    //int capacity

public:
    ArrayInt() 
        : m_length(0), m_data(nullptr)
    { }

   ArrayInt(size_t length) :
        m_length(length)
    {       
        m_data = new int[length];
        fill(m_data, m_data + length, 0);
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    int& operator[](int index)
    {
       assert(index < m_length);
       return m_data[index];
    }
          
    void erase()
    {
       
    }
    void push_back(int val)
    {

    }

    void resize()
    {

    }
    
    void print()
    {
        cout << "{ ";
        for (size_t i = 0; i < m_length; ++i)
        {
            cout << m_data[i] << " ";
        }
        cout << "}" << endl;
    }

/*
    1.	Добавить в контейнерный класс, который был написан в этом уроке, методы:
●	для удаления последнего элемента массива (аналог функции pop_back() в векторах)
●	для удаления первого элемента массива (аналог pop_front() в векторах)
●	для сортировки массива
●	для вывода на экран элементов. <- уже был реализован на уроке, void print(), немного видоизменила его
*/

    void fillarray()
    {
        for (size_t i = 0; i < m_length; ++i)
        {
            m_data[i] = m_length - i + 1;
        }
    }
    
    void pop_back()
    {
        m_data[m_length - 1] = 0;
        --m_length;

    }

    void pop_front()
    {
        for (size_t i = 0; i < m_length; ++i)
        {
            m_data[i] = m_data[i + 1];
        }
        
        m_data[m_length - 1] = 0;
        --m_length;
    }

    void sorting()
    {
        for (size_t i = 0; i < m_length - 1; ++i)
        {
            int temp = m_data[i];
            for (size_t j = i + 1; j < m_length; ++j)
            {
                if (m_data[j] < m_data[i])
                    temp = m_data[j];
                    m_data[j] = m_data[i];
                    m_data[i] = temp;
            }            
        }
    }

};


//вывод вектора
void printVector(const vector<int>& a) {
    cout << "The length is: " << a.size() << '\n';

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << ' ';

    cout << endl;
}


/*
3.	Реализовать класс Hand, который представляет собой коллекцию карт. В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card). Также в классе Hand должно быть 3 метода:
●	метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
●	метод Clear, который очищает руку от карт
●	метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).
*/

class Card
{
public:
    enum SUIT { HEART, CLUB, DIAMOND, SPADE };
    enum VALUE { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEN, KING};

private:
    SUIT m_suit;
    VALUE m_value;
    bool m_position;

public:
    Card(SUIT s = CLUB, VALUE v = ACE, bool position = 1)
        :m_suit(s), m_value(v), m_position(position) {}

    ~Card() {}

    void Flip()
    {
        m_position = !(m_position);
    }

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

    void add(Card* pCard)
    {
        m_cards.push_back(pCard);
    }
    
    void clear()
    {
        for (Card* card : m_cards)
        {
            delete card;
            card = nullptr;
        }
    }

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

//скажу честно, п. 3 подсматривала. Меня в скуку вгоняет эта карточная игра =с

int main()
{    
//1. Добавить в контейнерный класс, который был написан в этом уроке, методы...
    ArrayInt arr(5);
    arr.print();  
    arr.fillarray();
    arr.print();
    arr.pop_back();
    arr.print();
    arr.pop_front();
    arr.print();
    arr.sorting();
    arr.print();

/*
2.	Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм.
*/
    cout << endl;
    
    vector<int> myVector;
    for (int count = 0; count < 5; ++count)
    {
       myVector.push_back(count);        
    }
    myVector.at(1) = 3;

    printVector(myVector);
    set<int> DiffNumbers(myVector.begin(), myVector.end());
    cout << "There are " << DiffNumbers.size() << " different numbers" << endl;
    
    return 0;    
}

