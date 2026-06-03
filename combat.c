#include "combat.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculate_damage(const char *name, int attack, int defence, int bravery, int ran) {

    float defence_modifier = 0.0;
    srand(time(NULL)+ran);
    defence_modifier = 1 - (rand()%10)/100.0;
    double adjusted_attack = attack * (1 + ((double) bravery/100));
    double damage =  adjusted_attack - defence*defence_modifier;
    
    return (damage < 0) ? 0 : damage;

};

void heal(double *health, int *potions, const int potion_strength){
    *health += potion_strength;
    (*potions)--;

}