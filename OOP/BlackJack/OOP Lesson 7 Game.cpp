/*
Использовать пример реализации игры BlackJack (доступен в материалах к заданию)
Вместо 3, 4, 5 заданий в методички (Создать класс Deck..., Реализовать класс Game..., Написать функцию main()...)
1. Разобраться с предложенной реализацией, исследовать код, реализовать его сборку в своей IDE(Интегрированная среда разработки)
2. Попробовать что-нибудь модифицировать, улучшить логику игры.
3. Переписать внутри игры циклы для vector c итеративной версии на range base for
*/

/*1 Black Jack*/
#include <iostream> 
#include <vector>
#include <set> 
#include <string> 
#include "Game.h" 

using namespace std;

int main()
{
    cout << "\t\tWelcome to Blackjack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    //set<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
        //names.insert(name);
    }
    cout << endl;

    // игровой цикл
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }

    //!-> home task change for with iterrator to range base for

    //!-> templates in h


    return 0;
}