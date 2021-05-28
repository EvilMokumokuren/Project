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

    //  IsHitting() - чисто виртуальна€ функци€, возвращает информацию, нужна ли игроку еще одна карта.
    virtual bool IsHitting() const = 0;
    
//  IsBoosted() - возвращает bool значение, есть ли у игрока перебор
    bool IsBoosted() const;

    //  Bust() - выводит на экран им€ игрока и объ€вл€ет, что у него перебор.
    void Bust() const;

protected:
    string m_name;
};

ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);