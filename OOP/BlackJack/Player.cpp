#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const string& name) :
    GenericPlayer(name)
{}

Player::~Player()
{}

//virtual bool IsHitting() const - ���������� ����� ����������� ������� �������� ������. ����� ���������� � ������������, ����� �� ��� ��� ���� ����� � ���������� ����� ������������ � ���� true ��� false.
bool Player::IsHitting() const
{
    char answer;
    cout << "You need one more card? (Y/N)" << endl;
    cin >> answer;
    if ((answer == 'y') || (answer == 'Y')) return 1;   
}
//void Win() const - ������� �� ����� ��� ������ � ���������, ��� �� �������.
void Player::Win() const
{
    cout << m_name << " WIN!" << endl;
}
//void Lose() const - ������� �� ����� ��� ������ � ���������, ��� �� ��������.
void Player::Lose() const
{
    cout << m_name << ", you LOSE" << endl;
}
//void Push() const - ������� �� ����� ��� ������ � ���������, ��� �� ������ ������.
void Player::Push() const
{
    cout << "DRAW" << endl;
}