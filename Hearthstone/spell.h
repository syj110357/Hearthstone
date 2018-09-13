#ifndef __SPELL_H_
#define __SPELL_H_
#include <string>
#include "Hearthstone.h"
using namespace std;
class spell_t
{
public:
    int cost, original_damage;
    string name;
    int returndamage();
    virtual void usespell(int n=16){};
};
class Fireball : public spell_t
{
public:
    Fireball();
    void usespell(int n=16);
};
class Holy_Smite : public spell_t
{
public:
    Holy_Smite();
    void usespell(int n=16);
};
#endif
