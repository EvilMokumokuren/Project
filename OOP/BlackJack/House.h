#pragma once
#include "GenericPlayer.h"

using namespace std;

class House : public GenericPlayer
{
public:
    House(const string& name = "House");

    //virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
    bool IsHitting() const override;
    
    //	void FlipFirstCard() - метод переворачивает первую карту дилера.
    void FlipFirstCard();
};
