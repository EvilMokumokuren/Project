#pragma once
#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
    Player(const string& name = "");

    virtual ~Player();
    
    //virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
    bool IsHitting() const override;

    //void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
    void Win() const;

    //void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
    void Lose() const;

    //void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
    void Push() const;
};
