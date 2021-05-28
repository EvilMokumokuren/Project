#pragma once
#include "Card.h"
#include <vector>

class Hand
{
public:
    Hand();
    ~Hand();

    // метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
    void add(Card* pCard);

    // метод Clear, который очищает руку от карт
    void clear();

    // метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11)
    int getHandValue() const;

protected:
    vector<Card*> m_cards;
};