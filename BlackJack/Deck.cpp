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
    // ������� ����������� ������
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

// ������� ����� �������� ��� � ��������� ���� Player, ��� � House
void Deck::additionalCards(GenericPlayer& aGenericPlayer)
{
    cout << endl;
    //���������� ��������� ����� �� ��� ���, ���� � ������ �� ���������
    // ������� ��� ���� �� ����� ����� ��� ���� �����
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