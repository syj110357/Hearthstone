#ifndef __MINION_H_
#define __MINION_H_
using namespace std;
class minion_t
{
public:
    int minioncost,health, maxhealth, attack, oneturn_attack, maxattack, can_attack, position, add_spell_damage;
    string minionname;
    bool taunt, windfurry, divineshield, enrage, have_enrage, have_deathrattle, charge, oneturnattack, silence;
    void minionhealthminus(int n);
    virtual void minionattack(int n);
    virtual void minionstart()
    {
        if (windfurry==1) can_attack=2;
        else can_attack=1;
    }
    virtual void battlecry(int n,int m=16) {};
    virtual void deathrattle() {};
    virtual void enragesim() {};
    virtual void enragecancel() {};
    virtual void minionend()
    {
        if (oneturnattack==1)
        {
            attack=attack-oneturn_attack;
            oneturn_attack=0;
            oneturnattack=0;
        }
    }
    void silenceminion();
};
class Raging_Worgen : public minion_t
{
public:
    Raging_Worgen();
    void enragesim();
    void enragecancel();
};
class Dread_Infernal : public minion_t
{
public:
    Dread_Infernal();
    void battlecry(int n, int m=16);
};
class Silver_Hand_Recruit : public minion_t
{
public:
    Silver_Hand_Recruit();
};
class Spell_Breaker : public minion_t
{
public:
    Spell_Breaker();
    void battlecry(int n, int m=16);
};
class Abusive_Sergeant : public minion_t
{
public:
    Abusive_Sergeant();
    void battlecry(int n, int m=16);
};
class Defender_of_Argus : public minion_t
{
public:
    Defender_of_Argus();
    void battlecry(int n, int m=16);
};
class Korkron_Elite : public minion_t
{
public:
    Korkron_Elite();
};
class Unstable_Ghoul : public minion_t
{
public:
    Unstable_Ghoul();
    void deathrattle();
};
#endif
