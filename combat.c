#include "combat.h"
#include <stdio.h>
#include <stdlib.h>

double calculate_damage(int attack, int defence, int bravery) {

    float defence_modifier = 0.0;
    srand(0);
    defence_modifier = 1 + rand()%20;
    double adjusted_attack = attack * (1 + ((double) bravery/100));
    double damage =  adjusted_attack - defence;
    
    return (damage < 0) ? 0 : damage;

};