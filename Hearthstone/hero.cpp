#include "hero.h"
#include <iostream>
#include <cstdlib>
#include "Hearthstone.h"
using namespace std;
extern battlefield battlefield1;
Wicked_Knife knife;
Silver_Hand_Recruit shr;
void hero_t::healthminus(int n)
{
    if (armor>=n) armor=armor-n;
    else
    {
        health=health-(n-armor);
        armor=0;
    }
    if (health<=0) {cout<<heroname<<" is dead, game over"<<endl;exit(0);}
}
void hero_t::attack(int n)
{
    if (attackvalue==0) {cout<<"A hero with no attack value can not attack"<<endl;throw 0;}
    if (canattack==0) {cout<<"You have attacked this turn"<<endl;throw 0;}
    if (n>=7 && n<=13) {cout<<"Can not attack friendly minion"<<endl;throw 0;}
    else if (n==14)
    {
        if (checktaunt()==1) {cout<<"You have to attack the minion with taunt"<<endl;throw 0;}
        if (weapon!=NULL){
        weapon->durality--;
        battlefield1.enemy_hero->healthminus(attackvalue);
        if (weapon->durality==0)
        {
            attackvalue -= weapon->attack_value;
            weapon=NULL;
            have_weapon=0;
        }}
        canattack--;
    }
    else
    {
        if (checktaunt()==1 && battlefield1.minion[n]->taunt==0) {cout<<"You have to attack the minion with taunt"<<endl;throw 0;}
        if (weapon!=NULL)
        {
            weapon->durality--;
            if (weapon->durality==0)
            {
                weapon=NULL;
                have_weapon=0;
            }
        }
        battlefield1.minion[n]->health=battlefield1.minion[n]->health-attackvalue;
        healthminus(battlefield1.minion[n]->attack);
        if (battlefield1.minion[n]->health<=0)
        {
            if (battlefield1.minion[n]->have_deathrattle==1) battlefield1.minion[n]->deathrattle();
            die(n);
        }
        canattack--;
    }
}
void hero_t::startturn()
{
    if (battlefield1.myhand.max_mana<10)
    {
        battlefield1.myhand.max_mana++;
        battlefield1.myhand.current_mana=battlefield1.myhand.max_mana;
    }
    else
    {
        battlefield1.myhand.max_mana=10;
        battlefield1.myhand.current_mana=10;
    }
    if (herowindfurry==1) canattack=2;
    else canattack=1;
    for (int i=7;i<14;i++)
    {
        if (battlefield1.minion[i]!=NULL) battlefield1.minion[i]->minionstart();
    }
    use_power=0;
}
void hero_t::endturn()
{
    if (weapon!=NULL) attackvalue=weapon->attack_value;
    else attackvalue=0;
    for (int i=7;i<14;i++)
    {
        if (battlefield1.minion[i]!=NULL) battlefield1.minion[i]->minionend();
    }
}
Mage::Mage()
{
    health=30;
    maxhealth=30;
    armor=0;
    attackvalue=0;
    canattack=0;
    heropowercost=2;
    heroname="Jaina Proudmoore";
    have_weapon=0;
    herowindfurry=0;
    use_power=0;
    weapon=NULL;
}
void Mage::use_heropower(int n)
{
    if (battlefield1.myhand.current_mana<heropowercost) {cout<<"You don't have enough mana"<<endl;throw 0;}
    if (use_power==1) {cout<<"You have used your hero power"<<endl;throw 0;}
    if (n==14) battlefield1.enemy_hero->healthminus(1);
    else if (n==15) healthminus(1);
    else {battlefield1.minion[n]->health--;
    if (battlefield1.minion[n]->health<=0)
        {
            if (battlefield1.minion[n]->have_deathrattle==1) battlefield1.minion[n]->deathrattle();
            die(n);
        }}
    use_power=1;
    battlefield1.myhand.current_mana -= heropowercost;
}
Hunter::Hunter()
{
    health=30;
    maxhealth=30;
    armor=0;
    attackvalue=0;
    canattack=0;
    heropowercost=2;
    heroname="Rexxar";
    have_weapon=0;
    herowindfurry=0;
    use_power=0;
    weapon=NULL;
}
void Hunter::use_heropower(int n)
{
    if (battlefield1.myhand.current_mana<heropowercost) {cout<<"You don't have enough mana"<<endl;throw 0;}
    if (use_power==1) {cout<<"You have used your hero power"<<endl;throw 0;}
    battlefield1.enemy_hero->healthminus(2);
    use_power=1;
    battlefield1.myhand.current_mana -= heropowercost;
}
Warrior::Warrior()
{
    health=30;
    maxhealth=30;
    armor=0;
    attackvalue=0;
    canattack=0;
    heropowercost=2;
    heroname="Garrosh Hellscream";
    have_weapon=0;
    herowindfurry=0;
    use_power=0;
    weapon=NULL;
}
void Warrior::use_heropower(int n)
{
    if (battlefield1.myhand.current_mana<heropowercost) {cout<<"You don't have enough mana"<<endl;throw 0;}
    if (use_power==1) {cout<<"You have used your hero power"<<endl;throw 0;}
    armor=armor+2;
    use_power=1;
    battlefield1.myhand.current_mana -= heropowercost;
}
Priest::Priest()
{
    health=30;
    maxhealth=30;
    armor=0;
    attackvalue=0;
    canattack=0;
    heropowercost=2;
    heroname="Anduin Wrynn";
    have_weapon=0;
    herowindfurry=0;
    use_power=0;
    weapon=NULL;
}
void Priest::use_heropower(int n)
{
    if (battlefield1.myhand.current_mana<heropowercost) {cout<<"You don't have enough mana"<<endl;throw 0;}
    if (use_power==1) {cout<<"You have used your hero power"<<endl;throw 0;}
    heal(n,2);
    use_power=1;
    battlefield1.myhand.current_mana -= heropowercost;
}
Druid::Druid()
{
    health=30;
    maxhealth=30;
    armor=0;
    attackvalue=0;
    canattack=0;
    heropowercost=2;
    heroname="Malfurion Stormrage";
    have_weapon=0;
    herowindfurry=0;
    use_power=0;
    weapon=NULL;
}
void Druid::use_heropower(int n)
{
    if (battlefield1.myhand.current_mana<heropowercost) {cout<<"You don't have enough mana"<<endl;throw 0;}
    if (use_power==1) {cout<<"You have used your hero power"<<endl;throw 0;}
    armor++;
    attackvalue++;
    use_power=1;
    battlefield1.myhand.current_mana -= heropowercost;
}
Rogue::Rogue()
{
    health=30;
    maxhealth=30;
    armor=0;
    attackvalue=0;
    canattack=0;
    heropowercost=2;
    heroname="Valeera Sanguinar";
    have_weapon=0;
    herowindfurry=0;
    use_power=0;
    weapon=NULL;
}
void Rogue::use_heropower(int n)
{
    if (battlefield1.myhand.current_mana<heropowercost) {cout<<"You don't have enough mana"<<endl;throw 0;}
    if (use_power==1) {cout<<"You have used your hero power"<<endl;throw 0;}
    if (weapon!=NULL)
    {
        attackvalue=attackvalue-weapon->attack_value;
    }
    //weapon=&knife;
    weapon=&knife;
    attackvalue++;
    use_power=1;
    battlefield1.myhand.current_mana -= heropowercost;
}
Paladin::Paladin()
{
    health=30;
    maxhealth=30;
    armor=0;
    attackvalue=0;
    canattack=0;
    heropowercost=2;
    heroname="Uther Lightbringer";
    have_weapon=0;
    herowindfurry=0;
    use_power=0;
    weapon=NULL;
}
void Paladin::use_heropower(int n)
{
    if (battlefield1.myhand.current_mana<heropowercost) {cout<<"You don't have enough mana"<<endl;throw 0;}
    if (use_power==1) {cout<<"You have used your hero power"<<endl;throw 0;}
    if (battlefield1.my_minion==MAXMINION) {cout<<"You can't have more minions"<<endl;throw 0;}
    battlefield1.minion[7+battlefield1.my_minion]=&shr;
    battlefield1.minion[7+battlefield1.my_minion]->position=7+battlefield1.my_minion;
    battlefield1.my_minion++;
    battlefield1.myhand.current_mana -= heropowercost;
    use_power=1;
}
