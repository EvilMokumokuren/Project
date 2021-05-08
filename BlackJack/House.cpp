#include "House.h"
#include <iostream>

using namespace std;

House::House(const string& name) :
    GenericPlayer(name)
{}

//virtual bool IsHitting() const - ����� ���������, ����� �� ������ ��� ���� �����. ���� � ������ �� ������ 16 �����, �� �� ����� ��� ���� �����.
bool House::IsHitting()  const
{
    if (getHandValue() <= 16) return 1;
}

//	void FlipFirstCard() - ����� �������������� ������ ����� ������.
void House::FlipFirstCard()
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