#pragma once
#include "GenericPlayer.h"

using namespace std;

class House : public GenericPlayer
{
public:
    House(const string& name = "House");

    //virtual bool IsHitting() const - ����� ���������, ����� �� ������ ��� ���� �����. ���� � ������ �� ������ 16 �����, �� �� ����� ��� ���� �����.
    bool IsHitting() const override;
    
    //	void FlipFirstCard() - ����� �������������� ������ ����� ������.
    void FlipFirstCard();
};
