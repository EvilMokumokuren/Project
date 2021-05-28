#pragma once
#include <iostream>
#include <string>
#include "Hand.h"

using namespace std;

class GenericPlayer : public Hand
{
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

public:      

    GenericPlayer(const string& name = "");
    virtual ~GenericPlayer();

    //  IsHitting() - ����� ����������� �������, ���������� ����������, ����� �� ������ ��� ���� �����.
    virtual bool IsHitting() const = 0;
    
//  IsBoosted() - ���������� bool ��������, ���� �� � ������ �������
    bool IsBoosted() const;

    //  Bust() - ������� �� ����� ��� ������ � ���������, ��� � ���� �������.
    void Bust() const;

protected:
    string m_name;
};

ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);