#include "game.h"

int player_hp = 100;
int player_att = 10;
int player_def = 8;

int monster_hp = 80;
int monster_att = 10;
int monster_def = 8;

void print_status(int player_hp, int player_att, int player_def,
	int monster_hp, int monster_att, int monster_def) {
	printf("Player status==============\n");
	printf("-HP: %d\n", player_hp);
	printf("-ATT: %d\n", player_att);
	printf("-DEF: %d\n", player_def);
	printf("===========================\n");

	printf("Monster status=============\n");
	printf("-HP: %d\n", monster_hp);
	printf("-ATT: %d\n", monster_att);
	printf("-DEF: %d\n", monster_def);
	printf("===========================\n");
}

int print_menu() {
	printf("Menu=======================\n");
	printf("1. Attack.\n");
	printf("2. Defense.\n");
	printf("3. Run.\n");
	printf("===========================\n");

	int choice;
	scanf("%d", &choice);

	return choice;
}

int calculate_damage(int att, int def, int do_critical) {
	int damage = att - def;
	int is_critical = rand() % 2;

	if (is_critical && do_critical) damage *= 2;

	return damage;
}

void attack() {
	int damage = calculate_damage(player_att, monster_def, 1);

	printf("Hit the monster with damage %d.\n", damage);
	monster_hp -= damage;

	int crtatt = rand() % 2;
	if (monster_hp > 0 && crtatt) {
		printf("Watch out! Monster's Counterattack!\n");
		damage = calculate_damage(monster_att, player_def, False);
		player_hp -= damage;
		printf("Got damage %d from the monster.\n", damage);
	}
}

void defense() {
	int damage = calculate_damage(monster_att, player_def, 1);

	printf("Got damage %d from the monster.\n", damage);
	player_hp -= damage;

	int crtatt = rand() % 2;
	if (player_hp > 0 && crtatt) {
		printf("Let's counterattack\n");
		damage = calculate_damage(player_att, monster_def, False);
		monster_hp -= damage;
		printf("Hit the monster with damage %d.\n", damage);
	}
}