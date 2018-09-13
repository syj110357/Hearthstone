#ifndef __HERO_H_
#define __HERO_H_
#include "weapon.h"
using namespace std;
const string heroClass[] = {"mage", "hunter", "warrior", "priest", "druid"};
class hero_t
{
public:
    int health,maxhealth, armor, attackvalue, canattack, heropowercost;
    string heroname;
    bool have_weapon, herowindfurry, use_power;
    weapon_t *weapon;
    void startturn();
    void attack(int n);
    void healthminus(int n);
    virtual void use_heropower(int n=16){};
    void endturn();
};
class Mage : public hero_t
{
public:
    Mage();
    void use_heropower(int n=16);
};
class Hunter : public hero_t
{
public:
    Hunter();
    void use_heropower(int n=16);
};
class Warrior : public hero_t
{
public:
    Warrior();
    void use_heropower(int n=16);
};
class Priest : public hero_t
{
public:
    Priest();
    void use_heropower(int n=16);
};
class Druid : public hero_t
{
public:
    Druid();
    void use_heropower(int n=16);
};
class Rogue : public hero_t
{
public:
    Rogue();
    void use_heropower(int n=16);
};
class Paladin : public hero_t
{
public:
    Paladin();
    void use_heropower(int n=16);
};
#endif
