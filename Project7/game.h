#pragma once
#ifndef Game_H
#define Game_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define True 1
#define False 0

extern int player_hp;
extern int player_att;
extern int player_def;

extern int monster_hp;
extern int monster_att;
extern int monster_def;

void print_status(int, int, int, int, int, int);
int print_menu();
int calculate_damage(int, int, int);
void attack();
void defense();

#endif // !Game_H
