#include <iostream>
#include <cstdlib>
#include "Hearthstone.h"
using namespace std;
extern battlefield battlefield1;
hand_t::hand_t()
{
    current_mana=10;
    max_mana=10;
    cardnumber=0;
    for (int i=0;i<10;i++)
    {
        card[i]=NULL;
    }
}
void hand_t::getcard(card_t *card)
{
    if (battlefield1.myhand.cardnumber<=10)
    {
        battlefield1.myhand.card[battlefield1.myhand.cardnumber]=card;
        battlefield1.myhand.cardnumber++;
    }
}
minion::minion()
{
    Minion=NULL;
}
void minion::usecard(int p, int n,int m)
{
    if (n!=7 && battlefield1.minion[n-1]==NULL) {cout<<"Position error"<<endl;throw 0;}
    if (Minion->minioncost>battlefield1.myhand.current_mana) {cout<<"You don't have enough mana"<<endl;throw 0;}
    if (battlefield1.my_minion==MAXMINION){cout<<"You can't have more minions"<<endl;throw 0;}
    Minion->battlecry(n,m);
    insertminion(n);
    Minion->position=n;
    battlefield1.minion[n]=Minion;
    battlefield1.my_minion++;
    battlefield1.myhand.current_mana -= Minion->minioncost;
    for (int i=p;i<9;i++)
    {
        battlefield1.myhand.card[i]=battlefield1.myhand.card[i+1];
    }
    battlefield1.myhand.card[9]=NULL;
}
string minion::returnname()
{
    return Minion->minionname;
}
int minion::returncost()
{
    return Minion->minioncost;
}
string minion::returntype()
{
    return "minion";
}
weapon::weapon()
{
    Weapon=NULL;
}
void weapon::usecard(int p, int n, int m)
{
    if (Weapon->cost>battlefield1.myhand.current_mana) {cout<<"You don't have enough mana"<<endl;throw 0;}
    if (battlefield1.my_hero->weapon!=NULL)
    {
        battlefield1.my_hero->attackvalue -= battlefield1.my_hero->weapon->attack_value;
    }
    battlefield1.my_hero->weapon=Weapon;
    Weapon->weaponbattlecry(m);
    battlefield1.myhand.current_mana -= Weapon->cost;
    battlefield1.my_hero->attackvalue += Weapon->attack_value;
    for (int i=p;i<9;i++)
    {
        battlefield1.myhand.card[i]=battlefield1.myhand.card[i+1];
    }
    battlefield1.myhand.card[9]=NULL;
}
string weapon::returnname()
{
    return Weapon->name;
}
int weapon::returncost()
{
    return Weapon->cost;
}
string weapon::returntype()
{
    return "weapon";
}
spell::spell()
{
    Spell=NULL;
}
string spell::returnname()
{
    return Spell->name;
}
int spell::returncost()
{
    return Spell->cost;
}
void spell::usecard(int p, int n, int m)
{
    Spell->usespell(m);
    for (int i=p;i<9;i++)
    {
        battlefield1.myhand.card[i]=battlefield1.myhand.card[i+1];
    }
    battlefield1.myhand.card[9]=NULL;
    battlefield1.myhand.current_mana -= Spell->cost;
}
string spell::returntype()
{
    return "spell";
}
