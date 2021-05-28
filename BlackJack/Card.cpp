#include "Card.h"

using namespace std;

Card::Card(VALUE v, SUIT s, bool position)
    : m_value(v), m_suit(s), m_position(position) {
}

int Card::GetValue() const
{
    //если карта перевернута лицом вниз ее значение равно О
    int get_value = 0;
    if (m_position)
    {
        // значение - это число, указанное на карте
        get_value = m_value;
        // значение равно 10 для JACK, QUEEN и KING
        if (get_value > 10)
        {
            get_value = 10;
        }
    }
    return get_value;
}

void Card::Flip()
{
    m_position = !(m_position);
}


// перегружает оператор <<, чтобы получить возможность отправить
// объект типа Card в поток cout
ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "J", "Q", "K" };
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