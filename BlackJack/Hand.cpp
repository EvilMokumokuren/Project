#include "Hand.h"


Hand::Hand()
{
    m_cards.reserve(7);
}

Hand::~Hand()
{
    clear();
}

// ����� Add, ������� ��������� � ��������� ���� ����� �����, �������������� �� ��������� � �������� ��������� ��������� �� ����� �����
void Hand::add(Card* pCard)
{
    m_cards.push_back(pCard);
}

// ����� Clear, ������� ������� ���� �� ����
void Hand::clear()
{
    vector<Card*>::iterator iter = m_cards.begin();
    for (Card* card : m_cards)
    {
            delete* iter;
            *iter = 0;
    }
    m_cards.clear();
}

// ����� GetValue, ������� ���������� ����� ����� ���� ���� (����� ������������� ����������� ����, ��� ��� ����� ���� ����� 11)
int Hand::getHandValue() const
{
    if (m_cards.empty())
    {
        return 0;
    }
    
    if (m_cards[0]->GetValue() == 0)
        return 0;

    int get_value = 0;
    vector<Card*>::const_iterator iter;
    for (Card* card : m_cards)
    {
        get_value += (*iter)->GetValue();
    }
    
    
    bool ifAce = false;
    for (Card* card : m_cards)
    {
        if ((*iter)->GetValue() == Card::ACE)
        {
            ifAce = true;
        }
    }

    if (ifAce && get_value < 11) get_value += 10;
    {
        get_value += 10;
    }
    
    return get_value;
}