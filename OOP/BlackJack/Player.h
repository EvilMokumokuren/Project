#pragma once
#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
    Player(const string& name = "");

    virtual ~Player();
    
    //virtual bool IsHitting() const - ���������� ����� ����������� ������� �������� ������. ����� ���������� � ������������, ����� �� ��� ��� ���� ����� � ���������� ����� ������������ � ���� true ��� false.
    bool IsHitting() const override;

    //void Win() const - ������� �� ����� ��� ������ � ���������, ��� �� �������.
    void Win() const;

    //void Lose() const - ������� �� ����� ��� ������ � ���������, ��� �� ��������.
    void Lose() const;

    //void Push() const - ������� �� ����� ��� ������ � ���������, ��� �� ������ ������.
    void Push() const;
};
