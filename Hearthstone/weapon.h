#ifndef __WEAPON_H_
#define __WEAPON_H_
#include <string>
using namespace std;
class weapon_t
{
public:
    int attack_value,durality,cost;
    string name;
    virtual void weaponbattlecry(int n=16){};
    virtual void deathrattle(){};
};

class Fiery_War_Axe : public weapon_t
{
public:
    Fiery_War_Axe();
};
class Wicked_Knife : public weapon_t
{
public:
    Wicked_Knife();
};
#endif
