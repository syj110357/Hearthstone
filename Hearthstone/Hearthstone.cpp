#include "Hearthstone.h"
#include <cstdlib>
#include <iostream>
using namespace std;

battlefield battlefield1;
bool checktaunt()
{
    for (int i=0; i<7; i++)
    {
        if (battlefield1.minion[i]==NULL) return 0;
        else if (battlefield1.minion[i]->taunt==1) return 1;
    }
    return 0;
}
void die(int n)
{
    if (n<=6)
    {
        for (int i=n; i<6; i++)
        {
            battlefield1.minion[i]=battlefield1.minion[i+1];
            if (battlefield1.minion[i+1]!=NULL) battlefield1.minion[i+1]->position--;
        }
        battlefield1.minion[6]=NULL;
        battlefield1.enemy_minion--;
    }
    else
    {
        for (int i=n; i<13; i++)
        {
            battlefield1.minion[i]=battlefield1.minion[i+1];
            if (battlefield1.minion[i+1]!=NULL) battlefield1.minion[i+1]->position--;
        }
        battlefield1.minion[13]=NULL;
        battlefield1.my_minion--;
    }
}
void heal(int n, int m)
{
    if (n==14)
    {
        battlefield1.enemy_hero->health += m;
        if (battlefield1.enemy_hero->health>battlefield1.enemy_hero->maxhealth) battlefield1.enemy_hero->health=battlefield1.enemy_hero->maxhealth;
    }
    else if (n==15)
    {
        battlefield1.my_hero->health += m;
        if (battlefield1.my_hero->health>battlefield1.my_hero->maxhealth) battlefield1.my_hero->health=battlefield1.my_hero->maxhealth;
    }
    else
    {
        battlefield1.minion[n]->health += m;
        if (battlefield1.minion[n]->health>battlefield1.minion[n]->maxhealth) battlefield1.minion[n]->health=battlefield1.minion[n]->maxhealth;
    }
}
void print_enemyhero()
{
    cout<<battlefield1.enemy_hero->heroname<<" "<<battlefield1.enemy_hero->health<<" "<<battlefield1.enemy_hero->armor<<" "<<battlefield1.enemy_hero->attackvalue<<endl;
    if (battlefield1.enemy_hero->weapon!=NULL)
    {
        weapon_t *enemyweapon=battlefield1.enemy_hero->weapon;
        cout<<enemyweapon->name<<" "<<enemyweapon->attack_value<<" "<<enemyweapon->durality<<endl;
    }
}
void print_myhero()
{
    cout<<battlefield1.my_hero->heroname<<" "<<battlefield1.my_hero->health<<" "<<battlefield1.my_hero->armor<<" "<<battlefield1.my_hero->attackvalue<<endl;
    if (battlefield1.my_hero->weapon!=NULL)
    {
        cout<<battlefield1.my_hero->weapon->name<<" "<<battlefield1.my_hero->weapon->attack_value<<" "<<battlefield1.my_hero->weapon->durality<<endl;
    }
    cout<<endl;
}
void insertminion(int n)
{
    if (n<=6)
    {
        for (int i=5; i>=n; i--)
        {
            battlefield1.minion[i+1]=battlefield1.minion[i];
            if (battlefield1.minion[i]!=NULL) battlefield1.minion[i]->position++;
        }
        battlefield1.enemy_minion++;
    }
    else
    {
        for (int i=12; i>=n; i--)
        {
            battlefield1.minion[i+1]=battlefield1.minion[i];
            if (battlefield1.minion[i]!=NULL) battlefield1.minion[i]->position++;
        }
        battlefield1.my_minion++;
    }
}
void checkenrage()
{
    for (int i=0; i<14; i++)
    {
        if (battlefield1.minion[i]!=NULL)
        {
            if (battlefield1.minion[i]->have_enrage==1)
            {
                if (battlefield1.minion[i]->health<battlefield1.minion[i]->maxhealth && battlefield1.minion[i]->enrage==0)
                {
                    battlefield1.minion[i]->enragesim();
                    battlefield1.minion[i]->enrage=1;
                }
                else if (battlefield1.minion[i]->health==battlefield1.minion[i]->maxhealth && battlefield1.minion[i]->enrage==1)
                {
                    battlefield1.minion[i]->enragecancel();
                    battlefield1.minion[i]->enrage=0;
                }
            }
        }
    }
}
void print_minion()
{
    cout<<"Enemy minion"<<endl;
    for (int i=0; i<7; i++)
    {
        if (battlefield1.minion[i]!=NULL)
        {
            cout<<"Position "<<i<<":"<<battlefield1.minion[i]->minionname<<" "<<battlefield1.minion[i]->attack<<" "<<battlefield1.minion[i]->health<<" "<<battlefield1.minion[i]->can_attack<<" ";
            if (battlefield1.minion[i]->taunt==1) cout<<"taunt ";
            if (battlefield1.minion[i]->divineshield==1) cout<<"divineshield ";
            if (battlefield1.minion[i]->windfurry==1) cout<<"windfurry ";
            if (battlefield1.minion[i]->enrage==1) cout<<"enraged ";
            if (battlefield1.minion[i]->charge==1) cout<<"charge ";
            if (battlefield1.minion[i]->silence==1) cout<<"silenced ";
            cout<<endl;
        }
    }
    cout<<"Friendly minion"<<endl;
    for (int i=7; i<14; i++)
    {
        if (battlefield1.minion[i]!=NULL)
        {
            cout<<"Position "<<i<<":"<<battlefield1.minion[i]->minionname<<" "<<battlefield1.minion[i]->attack<<" "<<battlefield1.minion[i]->health<<" "<<battlefield1.minion[i]->can_attack<<" ";
            if (battlefield1.minion[i]->taunt==1) cout<<"taunt ";
            if (battlefield1.minion[i]->divineshield==1) cout<<"divineshield ";
            if (battlefield1.minion[i]->windfurry==1) cout<<"windfurry ";
            if (battlefield1.minion[i]->enrage==1) cout<<"enraged ";
            if (battlefield1.minion[i]->charge==1) cout<<"charge ";
            if (battlefield1.minion[i]->silence==1) cout<<"silenced ";
            cout<<endl;
        }
    }
}
void print_hand()
{
    cout<<"Current mana: "<<battlefield1.myhand.current_mana<<" Max mana: "<<battlefield1.myhand.max_mana<<endl;
    cout<<"My hand:"<<endl;
    for (int i=0; i<10; i++)
    {
        if (battlefield1.myhand.card[i]!=NULL)
        {
            cout<<battlefield1.myhand.card[i]->returnname()<<" "<<battlefield1.myhand.card[i]->returncost()<<" "<<endl;
        }
    }
}
void print_battlefield()
{
    print_enemyhero();
    print_minion();
    print_hand();
    print_myhero();
}
bool battlefieldempty()
{
    for (int i=0; i<14; i++)
    {
        if (battlefield1.minion[i]!=NULL) return false;
    }
    return true;
}
bool havedeath()
{
    for (int i=0; i<14; i++)
    {
        if (battlefield1.minion[i]!=NULL)
        {
            if (battlefield1.minion[i]->health<=0) return true;
        }
    }
    return false;
}
void checkdeath()
{
    if (battlefield1.enemy_hero->health<=0 && battlefield1.my_hero->health<=0)
    {
        cout<<"Draw"<<endl;
        exit(0);
    }
    else if (battlefield1.enemy_hero->health<=0)
    {
        cout<<battlefield1.enemy_hero->heroname<<" is dead, game over"<<endl;
        exit(0);
    }
    else if (battlefield1.my_hero->health<=0)
    {
        cout<<battlefield1.my_hero->heroname<<" is dead, game over"<<endl;
        exit(0);
    }
    while (havedeath()==1)
    {
        for (int i=0; i<14; i++)
        {
            if (battlefield1.minion[i]!=NULL)
            {
                if (battlefield1.minion[i]->health<=0)
                {
                    if (battlefield1.minion[i]->have_deathrattle==1) battlefield1.minion[i]->deathrattle();
                    die(i);
                    break;
                }
            }
        }
    }
}
