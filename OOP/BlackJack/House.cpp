#include "House.h"
#include <iostream>

using namespace std;

House::House(const string& name) :
    GenericPlayer(name)
{}

//virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
bool House::IsHitting()  const
{
    if (getHandValue() <= 16) return 1;
}

//	void FlipFirstCard() - метод переворачивает первую карту дилера.
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