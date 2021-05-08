#include "Deck.h"
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;

Deck::Deck()
{
    m_cards.reserve(52);
    populate();
}

Deck::~Deck()
{}

void Deck::populate()
{
    clear();
    // создает стандартную колоду
    for (int s = Card::CLUB; s <= Card::SPADE; ++s)
    {
        for (int v = Card::ACE; v <= Card::KING; ++v)
        {
            add(new Card(static_cast<Card::VALUE>(v),
                static_cast<Card::SUIT>(s)));
        }
    }
}

void Deck::shuffle()
{
    srand(static_cast<unsigned int>(time(0)));
    std::random_shuffle(m_cards.begin(), m_cards.end());
}

// функция может работать как с объектами типа Player, так и House
void Deck::additionalCards(GenericPlayer& aGenericPlayer)
{
    cout << endl;
    //продолжает раздавать карты до тех пор, пока у игрока не случается
    // перебор или пока он хочет взять еще одну карту
    while (!(aGenericPlayer.IsBoosted()) && aGenericPlayer.IsHitting())
    {
        deal(aGenericPlayer);
        cout << aGenericPlayer << endl;

        if (aGenericPlayer.IsBoosted())
        {
            aGenericPlayer.Bust();
        }
    }
}

void Deck::deal(Hand& aHand)
{
    if (!m_cards.empty())
    {
        aHand.add(m_cards.back());
        m_cards.pop_back();
    }
    else
    {
       cout << "Out of cards. Unable to deal.";
    }
}