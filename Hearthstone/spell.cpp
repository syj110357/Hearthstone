#include <iostream>
#include <cstdlib>
#include "Hearthstone.h"
using namespace std;
extern battlefield battlefield1;
int spell_t::returndamage()
{
    int add_damage=0;
    for (int i=7;i<14;i++)
    {
        if (battlefield1.minion[i]!=NULL)
        {
            add_damage += battlefield1.minion[i]->add_spell_damage;
        }
        return original_damage+add_damage;
    }
}
Fireball::Fireball()
{
    cost=4;
    original_damage=6;
    name="Fireball";
}
void Fireball::usespell(int n)
{
    if (n==16) {cout<<"You need to define a target for it"<<endl;throw 0;}
    if (n==14) {battlefield1.enemy_hero->healthminus(returndamage());}
    else if (n==15) {battlefield1.my_hero->healthminus(returndamage());}
    else
    {
        battlefield1.minion[n]->minionhealthminus(returndamage());
        if (battlefield1.minion[n]->health<=0)
            {
                if (battlefield1.minion[n]->have_deathrattle==1) battlefield1.minion[n]->deathrattle();
                die(n);
            }
    }
}
Holy_Smite::Holy_Smite()
{
    cost=1;
    original_damage=2;
    name="Holy Smite";
}
void Holy_Smite::usespell(int n)
{
    if (n==16) {cout<<"You need to define a target for it"<<endl;throw 0;}
    if (n==14) {battlefield1.enemy_hero->healthminus(returndamage());}
    else if (n==15) {battlefield1.my_hero->healthminus(returndamage());}
    else
    {
        battlefield1.minion[n]->minionhealthminus(returndamage());
        if (battlefield1.minion[n]->health<=0)
            {
                if (battlefield1.minion[n]->have_deathrattle==1) battlefield1.minion[n]->deathrattle();
                die(n);
            }
    }
}
