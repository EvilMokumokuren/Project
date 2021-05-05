#pragma once
#include <iostream>

using namespace std;

class Card
{
public:
    enum SUIT { HEART, CLUB, DIAMOND, SPADE };
    enum VALUE { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEN, KING };

public:
    Card(VALUE v = ACE, SUIT s = SPADE, bool position = 1);   
     
    friend ostream& operator<<(ostream& os, const Card& aCard);

    // метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
    int GetValue() const;
    
    // метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
    void Flip();

protected:
    SUIT m_suit;
    VALUE m_value;
    bool m_position;
};

ostream& operator<<(std::ostream& os, const Card& aCard);