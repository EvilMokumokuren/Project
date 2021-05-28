#include "GenericPlayer.h"

using namespace std;

GenericPlayer::GenericPlayer(const string& name) :
    m_name(name)
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::IsBoosted() const
{
    return (getHandValue() > 21);
}

void GenericPlayer::Bust() const
{
    cout << m_name << "You got bust!" << endl;
}

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_name << ":\t";

    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_cards.empty())
    {
        //!-> home task 
        // ����� ����� ������������ range base for?

        //for (pCard = aGenericPlayer.m_cards.begin();
        //    pCard != aGenericPlayer.m_cards.end();
        //    ++pCard)
        //{
        //    os << *(*pCard) << "\t";
        //}

        for (Card* card : aGenericPlayer.m_cards)
        {
            os << *card << "\t";
        }

        if (aGenericPlayer.getHandValue() != 0)
        {
            cout << "(" << aGenericPlayer.getHandValue() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }

    return os;
}