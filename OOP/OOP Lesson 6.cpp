/*
Колпакова Е., OOP Lesson 6, Visual Studio Code
1.	Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»: если пользователь вводит что-то кроме одного целочисленного значения, нужно вывести сообщение об ошибке и предложить ввести число еще раз. Пример неправильных введенных строк:
rbtrb
nj34njkn
1n
2.	Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.

3.	Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
●	virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
●	void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
●	void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
●	void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.

4.	Реализовать класс House, который представляет дилера. Этот класс наследует от класса GenericPlayer. У него есть 2 метода:
●	virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
●	void FlipFirstCard() - метод переворачивает первую карту дилера.

5.	Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой вверх (мы ее не видим), вывести ХХ, если мы ее видим, вывести масть и номинал карты. Также для класса GenericPlayer написать перегрузку оператора вывода, который должен отображать имя игрока и его карты, а также общую сумму очков его карт.
*/

#include <iostream>
#include <string> 
#include <vector>

using namespace std;

/*
1.	Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»: если пользователь вводит что-то кроме одного целочисленного значения, нужно вывести сообщение об ошибке и предложить ввести число еще раз. Пример неправильных введенных строк:
rbtrb
nj34njkn
1n
*/

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

void Task1()
{
    int NumTask1;
    bool check;

    do {
        cout << "Please enter int number: ";
        cin >> NumTask1;
        check = CheckSymbol();
    } while (check == false);

    return;
}

/*
2.	Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.
*/
//https://coderoad.ru/4751972/endl-%D0%B8-%D0%BF%D1%80%D0%BE%D0%BC%D1%8B%D0%B2%D0%BA%D0%B0-%D0%B1%D1%83%D1%84%D0%B5%D1%80%D0%B0
inline ostream& endll(ostream& os)
{
    os.put(os.widen('\n\n'));   
    return os;
}



/*
3.	Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
●	virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
●	void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
●	void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
●	void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.

4.	Реализовать класс House, который представляет дилера. Этот класс наследует от класса GenericPlayer. У него есть 2 метода:
●	virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
●	void FlipFirstCard() - метод переворачивает первую карту дилера.

5.	Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой вверх (мы ее не видим), вывести ХХ, если мы ее видим, вывести масть и номинал карты. Также для класса GenericPlayer написать перегрузку оператора вывода, который 
должен отображать имя игрока и его карты, а также общую сумму очков его карт.
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
    
    friend ostream& operator<<(ostream& os, const Card& aCard);

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

protected:
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

class GenericPlayer : public Hand
{
protected:
    string m_name;   
public:
    GenericPlayer(string name)
        :m_name(name) {}

    //  IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
    virtual void IsHitting() = 0;
    //этот пункт не особо поняла..

//  IsBoosted() - возвращает bool значение, есть ли у игрока перебор
    bool IsBoosted()
    {
        return (getValue() > 21);
    }

    //  Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
    void Bust()
    {        
            cout << m_name << "You got bust!" << endl;        
    }

};

class Player: public GenericPlayer
{
public:

//virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
    virtual bool IsHitting() const
    {
        char answer;
        cout << "You need one more card? (Y/N)" << endl;
        cin >> answer;
        if (answer == 'y') return 'y';
        if (answer == 'Y') return 'y';
    }
//void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
    void Win() const
    {
        cout << m_name << " WIN!" << endl;
    }
//void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
    void Lose() const
    {
        cout << m_name << ", you LOSE" << endl;
    }
//void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
    void Push() const
    {
        cout << "DRAW" << endl;
    }
};

class House: public GenericPlayer
{
public:
    //virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
    virtual bool IsHitting() const
    {
        if (getValue() <= 16) return 1;
    }
//	void FlipFirstCard() - метод переворачивает первую карту дилера.
    void FlipFirstCard()
    {
        if (!(m_cards.empty()))
        {
            m_cards[0]->Flip();
        }
        else
        {
            cout << "Nothing to flip" << endl;
        }
    }
};

//честно стырено из методички
// перегружает оператор <<, чтобы получить возможность отправить
// объект типа Card в поток cout
ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.m_position)
    {
        os << RANKS[aCard.m_value] << SUITS[aCard.m_suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}


int main()
{
    Task1();

    return 0;
}

