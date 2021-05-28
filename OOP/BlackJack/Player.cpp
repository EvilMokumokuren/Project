#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const string& name) :
    GenericPlayer(name)
{}

Player::~Player()
{}

//virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
bool Player::IsHitting() const
{
    char answer;
    cout << "You need one more card? (Y/N)" << endl;
    cin >> answer;
    if ((answer == 'y') || (answer == 'Y')) return 1;   
}
//void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
void Player::Win() const
{
    cout << m_name << " WIN!" << endl;
}
//void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
void Player::Lose() const
{
    cout << m_name << ", you LOSE" << endl;
}
//void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
void Player::Push() const
{
    cout << "DRAW" << endl;
}