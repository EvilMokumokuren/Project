#pragma once
#include <string>
#include "Deck.h"
#include "House.h"
#include "Player.h"

using namespace std;

class Game
{
public:
    Game(const vector<string>& names);

    ~Game();

    // проводит игру в Blackjack
    void play();

private:
    Deck m_deck;
    House m_house;
    vector<Player> m_players;
};