#include "Card.h"

using namespace std;

Card::Card(VALUE v, SUIT s, bool position)
    : m_value(v), m_suit(s), m_position(position) {
}

int Card::GetValue() const
{
    //���� ����� ����������� ����� ���� �� �������� ����� �
    int get_value = 0;
    if (m_position)
    {
        // �������� - ��� �����, ��������� �� �����
        get_value = m_value;
        // �������� ����� 10 ��� JACK, QUEEN � KING
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


// ����������� �������� <<, ����� �������� ����������� ���������
// ������ ���� Card � ����� cout
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