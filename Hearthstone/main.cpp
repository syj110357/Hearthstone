#include "Hearthstone.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    extern battlefield battlefield1;
    Mage jaina;
    Warrior war;
    Druid dru;
    Priest pr;
    Rogue ro;
    Paladin pa;
    Raging_Worgen rag,rag2;
    Dread_Infernal dr;
    Spell_Breaker sp;
    Abusive_Sergeant ab;
    Defender_of_Argus de;
    Korkron_Elite ko;
    Unstable_Ghoul un,un2;
    Fireball fire;
    Holy_Smite holy;
    minion Mi,pofa,unstable;
    minion* mi;
    minion* fa;
    minion* Unstable;
    Fiery_War_Axe waraxe;
    Wicked_Knife wicked;
    weapon We;
    weapon* we;
    spell s;
    spell *S;
    spell ss;
    spell *SS;
    battlefield1.my_hero=&pa;
    battlefield1.enemy_hero=&war;
    unstable.Minion=&un2;
    Unstable=&unstable;
    Mi.Minion=&dr;
    mi=&Mi;
    pofa.Minion=&un;
    fa=&pofa;
    We.Weapon=&wicked;
    we=&We;
    s.Spell=&fire;
    S=&s;
    ss.Spell=&holy;
    SS=&ss;
    battlefield1.myhand.getcard(mi);
    battlefield1.myhand.getcard(we);
    battlefield1.myhand.getcard(fa);
    battlefield1.myhand.getcard(S);
    battlefield1.myhand.getcard(SS);
    battlefield1.myhand.getcard(Unstable);
    battlefield1.enemy_hero->health=7;
    battlefield1.enemy_hero->armor=3;
    battlefield1.minion[7]=&rag;
    battlefield1.my_minion=1;
    print_battlefield();
    battlefield1.my_hero->startturn();
    //initialize battlefield
    string line;
    int a,b,c;
    cin>>line;
    while (line.compare("endturn")!=0)
    {
        try
        {
            if (line.compare("usecard")==0)
            {
                cin>>a>>b>>c;
                battlefield1.myhand.card[a]->usecard(a,b,c);
            }
            else if (line.compare("attack")==0)
            {
                cin>>a>>b;
                if (a!=15)
                {
                    battlefield1.minion[a]->minionattack(b);
                }
                else
                {
                    battlefield1.my_hero->attack(b);
                }
            }
            else if (line.compare("useheropower")==0)
            {
                cin>>a;
                battlefield1.my_hero->use_heropower(a);
            }
            checkenrage();
            checkdeath();
            print_battlefield();
        }
        catch (int v)
        {
            goto here;
        }
        here:
        cin>>line;
    }
    battlefield1.my_hero->endturn();
    print_battlefield();
    cout<<"You failed to kill your enemy"<<endl;
    /*
    battlefield1.myhand.card[0]->usecard(0,7);
    print_battlefield();
    checkenrage();
    battlefield1.minion[8]->minionattack(14);
    print_battlefield();
    battlefield1.minion[8]->minionattack(14);
    print_battlefield();*/
    return 0;
}
