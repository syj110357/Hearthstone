#ifndef __HAND_H_
#define __HAND_H_
#include "Hearthstone.h"
#include "spell.h"
using namespace std;
const unsigned int MAXCARD = 10;

class card_t
{
public:
    virtual void usecard(int p, int n=16,int m=16){};
    virtual string returnname(){};
    virtual int returncost(){};
    virtual string returntype(){};
};
class minion : public card_t
{
public:
    minion_t* Minion;
    minion();
    void usecard(int p, int n=16,int m=16);
    string returnname();
    int returncost();
    string returntype();
};
class weapon : public card_t
{
public:
    weapon_t* Weapon;
    weapon();
    void usecard(int p, int n=16, int m=16);
    string returnname();
    int returncost();
    string returntype();
};
class spell : public card_t
{
public:
    spell_t* Spell;
    spell();
    void usecard(int p, int n=16, int m=16);
    string returnname();
    int returncost();
    string returntype();
};
class hand_t
{
public:
    int current_mana,max_mana,cardnumber;
    card_t* card[MAXCARD];
    hand_t();
    void getcard(card_t* card);
};
#endif
