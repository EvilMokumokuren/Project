#pragma once
#include "Card.h"
#include <vector>

class Hand
{
public:
    Hand();
    ~Hand();

    // ����� Add, ������� ��������� � ��������� ���� ����� �����, �������������� �� ��������� � �������� ��������� ��������� �� ����� �����
    void add(Card* pCard);

    // ����� Clear, ������� ������� ���� �� ����
    void clear();

    // ����� GetValue, ������� ���������� ����� ����� ���� ���� (����� ������������� ����������� ����, ��� ��� ����� ���� ����� 11)
    int getHandValue() const;

protected:
    vector<Card*> m_cards;
};