#include "Game.h" 
using namespace std;


// ����������� ����� ������ ��������� ������ �� ������ �����, ��������������
// ����� ������� - �����. ����������� ������� ������ ������ Player ��� ������� �����
Game::Game(const vector<string>& names)
{
    // ������� ������ ������� �� ������� � �������
   vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName) // � �������� �������� ���������� �������� ����������� https://www.math.ucla.edu/~akrieger/teaching/19w/pic10c/vector.html �� �������� �����. �� ������� =)
    {
        m_players.push_back(Player(*pName));
    }

    // ��������� ��������� ��������� �����
    srand(static_cast<unsigned int>(time(0)));
    m_deck.populate();
    m_deck.shuffle();
}


Game::~Game()
{}

void Game::play()
{
    const int startCardCount = 2;
    // ������� ������� �� ��� ��������� �����
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < startCardCount; ++i)
    {
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        {
            m_deck.deal(*pPlayer);
        }
        m_deck.deal(m_house);
    }

    // ������ ������ ����� ������
    m_house.FlipFirstCard();

    // ��������� ���� ���� �������
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    {
        cout << *pPlayer << endl;
    }
    cout << m_house << endl;

    // ������� ������� �������������� �����
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer) 
    {
        m_deck.additionalCards(*pPlayer);
    }

    // ���������� ������ ����� ������
    m_house.FlipFirstCard();
    cout << endl << m_house;

    // ������� ������ �������������� �����
    m_deck.additionalCards(m_house);

    if (m_house.IsBoosted())
    {
        // ���, ��� ������� � ����, ���������
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        {
            if (!(pPlayer->IsBoosted()))
            {
                pPlayer->Win();
            }
        }
    }
    else
    {
        // ���������� ����� ����� ���� ���������� ������� � ������ ����� ������
        for (pPlayer = m_players.begin(); pPlayer != m_players.end();
            ++pPlayer)
        {
            if (!(pPlayer->IsBoosted()))
            {
                if (pPlayer->getHandValue() > m_house.getHandValue())
                {
                    pPlayer->Win();
                }
                else if (pPlayer->getHandValue() < m_house.getHandValue())
                {
                    pPlayer->Lose();
                }
                else
                {
                    pPlayer->Push();
                }
            }
        }

    }

    // ������� ���� ���� �������
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    {
        pPlayer->clear();
    }
    m_house.clear();
}
