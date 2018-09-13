#include <iostream>
#include <cstdlib>
#include "Hearthstone.h"
#include "minion.h"
#include "hero.h"
#include "weapon.h"
using namespace std;
extern battlefield battlefield1;
void minion_t::minionhealthminus(int n)
{
    if (divineshield==0) health=health-n;
    else divineshield=0;
}
void minion_t::minionattack(int n)
{
    if (n>=7 && n!=14) {cout<<"You can not attack a friendly target"<<endl;throw 0;}
    if (can_attack==0) {cout<<"That minion can not attack"<<endl;throw 0;};
    if (attack==0) {cout<<"That minion has no attack value"<<endl;throw 0;};
    if (n==14)
    {
        if (checktaunt()==1) {cout<<"You have to attack the minion with taunt"<<endl;throw 0;}
        else {battlefield1.enemy_hero->healthminus(attack);can_attack--;}
    }
    else
    {
        if (checktaunt()==1 && battlefield1.minion[n]->taunt==0) {cout<<"You can not attack a friendly target"<<endl;throw 0;}
        else
        {
            minionhealthminus(battlefield1.minion[n]->attack);
            can_attack--;
            battlefield1.minion[n]->minionhealthminus(attack);
            if (health<=0)
            {
                if (have_deathrattle==1) deathrattle();
                die(position);
            }
            if (battlefield1.minion[n]->health<=0)
            {
                if (battlefield1.minion[n]->have_deathrattle==1) deathrattle();
                die(n);
            }
        }
    }
}
void minion_t::silenceminion()
{
    if (windfurry==1)
    {
        windfurry=0;
        if (can_attack>0) can_attack--;
    }
    taunt=0;
    divineshield=0;
    have_enrage=0;
    have_deathrattle=0;
    if (charge==1)
    {
        charge=0;
        if (can_attack>0) can_attack--;
    }
    if (enrage==1)
    {
        enrage=0;
        enragecancel();
    }
    if (health>maxhealth) health=maxhealth;
    if (attack!=maxattack) attack=maxattack;
    oneturnattack=0;
    oneturn_attack=0;
    silence=1;
}
Raging_Worgen::Raging_Worgen()
{
    minioncost=3;
    health=3;
    maxhealth=3;
    attack=3;
    oneturn_attack=0;
    maxattack=3;
    can_attack=0;
    position=0;
    add_spell_damage=0;
    minionname="Raging Worgen";
    taunt=0;
    windfurry=0;
    divineshield=0;
    enrage=0;
    have_enrage=1;
    have_deathrattle=0;
    charge=0;
    oneturnattack=0;
    silence=0;
}

void Raging_Worgen::enragesim()
{
    attack++;
    enrage=1;
    windfurry=1;
    can_attack++;
}
void Raging_Worgen::enragecancel()
{
    attack--;
    enrage=0;
    windfurry=0;
    if (can_attack!=0) can_attack--;
}
Dread_Infernal::Dread_Infernal()
{
    minioncost=6;
    health=6;
    maxhealth=6;
    attack=6;
    oneturn_attack=0;
    maxattack=6;
    can_attack=0;
    position=0;
    add_spell_damage=0;
    minionname="Dread Infernal";
    taunt=0;
    windfurry=0;
    divineshield=0;
    enrage=0;
    have_enrage=0;
    have_deathrattle=0;
    charge=0;
    oneturnattack=0;
    silence=0;
}
void Dread_Infernal::battlecry(int n, int m)
{
    battlefield1.enemy_hero->healthminus(1);
    battlefield1.my_hero->healthminus(1);
    for (int i=0;i<14;i++)
    {
        if (battlefield1.minion[i]!=NULL)
        {
            battlefield1.minion[i]->minionhealthminus(1);
        }
    }
}
Silver_Hand_Recruit::Silver_Hand_Recruit()
{
    minioncost=1;
    health=1;
    maxhealth=1;
    attack=1;
    oneturn_attack=0;
    maxattack=1;
    can_attack=0;
    position=0;
    add_spell_damage=0;
    minionname="Silver Hand Recruit";
    taunt=0;
    windfurry=0;
    divineshield=0;
    enrage=0;
    have_enrage=0;
    have_deathrattle=0;
    charge=0;
    oneturnattack=0;
    silence=0;
}
Spell_Breaker::Spell_Breaker()
{
    minioncost=4;
    health=3;
    maxhealth=3;
    attack=4;
    oneturn_attack=0;
    maxattack=4;
    can_attack=0;
    position=0;
    add_spell_damage=0;
    minionname="Spell Breaker";
    taunt=0;
    windfurry=0;
    divineshield=0;
    enrage=0;
    have_enrage=0;
    have_deathrattle=0;
    charge=0;
    oneturnattack=0;
    silence=0;
}
void Spell_Breaker::battlecry(int n, int m)
{
    if (m==16 && battlefieldempty()==0) {cout<<"You need to define a target for it"<<endl;throw 0;}
    battlefield1.minion[m]->silenceminion();
}
Abusive_Sergeant::Abusive_Sergeant()
{
    minioncost=1;
    health=1;
    maxhealth=1;
    attack=2;
    oneturn_attack=0;
    maxattack=2;
    can_attack=0;
    position=0;
    add_spell_damage=0;
    minionname="Abusive Sergeant";
    taunt=0;
    windfurry=0;
    divineshield=0;
    enrage=0;
    have_enrage=0;
    have_deathrattle=0;
    charge=0;
    oneturnattack=0;
    silence=0;
}
void Abusive_Sergeant::battlecry(int n, int m)
{
    if (m==16 && battlefieldempty()==0) {cout<<"You need to define a target for it"<<endl;throw 0;}
    battlefield1.minion[m]->oneturnattack=1;
    battlefield1.minion[m]->oneturn_attack=2;
    battlefield1.minion[m]->attack += 2;
}
Defender_of_Argus::Defender_of_Argus()
{
    minioncost=4;
    health=3;
    maxhealth=3;
    attack=2;
    oneturn_attack=0;
    maxattack=2;
    can_attack=0;
    position=0;
    add_spell_damage=0;
    minionname="Defender of Argus";
    taunt=0;
    windfurry=0;
    divineshield=0;
    enrage=0;
    have_enrage=0;
    have_deathrattle=0;
    charge=0;
    oneturnattack=0;
    silence=0;
}
void Defender_of_Argus::battlecry(int n, int m)
{
    if (n==7)
    {
        if (battlefield1.minion[7]!=0)
        {
            battlefield1.minion[7]->taunt=1;
            battlefield1.minion[7]->attack++;
            battlefield1.minion[7]->maxattack++;
            battlefield1.minion[7]->health++;
            battlefield1.minion[7]->maxhealth++;
        }
    }
    else if (n==13)
    {
        battlefield1.minion[12]->taunt=1;
        battlefield1.minion[12]->attack++;
        battlefield1.minion[12]->maxattack++;
        battlefield1.minion[12]->health++;
        battlefield1.minion[12]->maxhealth++;
    }
    else
    {
        battlefield1.minion[n-1]->taunt=1;
        battlefield1.minion[n-1]->attack++;
        battlefield1.minion[n-1]->maxattack++;
        battlefield1.minion[n-1]->health++;
        battlefield1.minion[n-1]->maxhealth++;
        if (battlefield1.minion[n]!=NULL)
        {
            battlefield1.minion[n]->taunt=1;
            battlefield1.minion[n]->attack++;
            battlefield1.minion[n]->maxattack++;
            battlefield1.minion[n]->health++;
            battlefield1.minion[n]->maxhealth++;
        }
    }
}
Korkron_Elite::Korkron_Elite()
{
    minioncost=4;
    health=3;
    maxhealth=3;
    attack=4;
    oneturn_attack=0;
    maxattack=4;
    can_attack=1;
    position=0;
    add_spell_damage=0;
    minionname="Kor'kron Elite";
    taunt=0;
    windfurry=0;
    divineshield=0;
    enrage=0;
    have_enrage=0;
    have_deathrattle=0;
    charge=1;
    oneturnattack=0;
    silence=0;
}
Unstable_Ghoul::Unstable_Ghoul()
{
    minioncost=2;
    health=3;
    maxhealth=3;
    attack=1;
    oneturn_attack=0;
    maxattack=1;
    can_attack=0;
    position=0;
    add_spell_damage=0;
    minionname="Unstable Ghoul";
    taunt=1;
    windfurry=0;
    divineshield=0;
    enrage=0;
    have_enrage=0;
    have_deathrattle=1;
    charge=0;
    oneturnattack=0;
    silence=0;
}
void Unstable_Ghoul::deathrattle()
{
    for (int i=0;i<14;i++)
    {
        if (battlefield1.minion[i]!=NULL)
        {
            battlefield1.minion[i]->minionhealthminus(1);
        }
    }
}
