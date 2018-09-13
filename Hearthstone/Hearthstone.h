#ifndef __HEARTHSTONE_H_
#define __HEARTHSTONE_H_
#include <string>
#include "hero.h"
#include "minion.h"
#include "hand.h"
#include "spell.h"
using namespace std;
const unsigned int MAXMINION = 7;

struct battlefield
{
    hero_t *enemy_hero, *my_hero;
    minion_t *minion[2*MAXMINION];
    hand_t myhand;
    int enemy_minion, my_minion;
};
bool checktaunt();
void die(int n);
void heal(int n, int m);
void print_enemyhero();
void print_myhero();
void print_minion();
void print_hand();
void print_battlefield();
void insertminion(int n);
void checkenrage();
void checkdeath();
bool battlefieldempty();
bool havedeath();
#endif
