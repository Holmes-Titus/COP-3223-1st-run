#include "combat.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "entity.h"

int rand_incr = 0;

double calculate_damage(entity_t attacker, entity_t defender) {

    float defence_modifier = 0.0;
    srand(time(NULL)+rand_incr);
    rand_incr++;
    defence_modifier = 1 - (rand()%10)/100.0;
    double adjusted_attack = attacker.attack * (1 + ((double) attacker.bravery/100));
    double damage =  adjusted_attack - defender.defence*defence_modifier;
    
    return (damage < 0) ? 0 : damage;

};

void heal(entity_t hero, int potion_strength){
    return hero.current_hp + potion_strength;
}