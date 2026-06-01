#ifndef COMBAT_H
#define COMBAT_H

double calculate_damage(const char *name, int attack, int defence, int bravery);
void heal(double *health, int *potions, int potion_strength);

#endif