#include <stdio.h>
#include <stdlib.h>
#include "combat.h"
#include <time.h>
#include "entity.h"

void print_hero_stats(void);
void print_monster_stats(void);
void print_stats(entity_t entity);




int main(void){

    const int potion_strength = 3;


    entity_t hero = {
    .potions = 3,
    .magic_skill = 30,
    .bravery = 10,
    .attack = 10,
    .defence = 10,
    .current_hp = 10.0,
    .max_hp = 10,
    .name = "Brentel",
    .type = HERO,
    };

    entity_t enemy1 = {
    .potions = 0,
    .magic_skill = 0,
    .bravery = 0,
    .attack = 10,
    .defence = 10,
    .current_hp = 10.0,
    .max_hp = 10,
    .name = "StarScream",
    .type = ENEMY_SEEKER,
    };

    entity_t enemy2 = {
    .potions = 0,
    .magic_skill = 0,
    .bravery = 0,
    .attack = 10,
    .defence = 10,
    .current_hp = 10.0,
    .max_hp = 10,
    .name = "Frenzy",
    .type = ENEMY_DECEPTICON,
    };

   


    printf("===================================\n");
    printf("|   Legally Distinct from Zelda   |\n");
    printf("|               the sequel.       |\n");
    printf("|=================================|\n");

    printf("Enter your hero's name> ");
    fscanf(stdin, "%s", hero.name);

    print_stats(hero);
    print_stats(enemy1);

    
    
    do {

        

        

        printf("%s Attacks!\n", hero.name);
        enemy1.current_hp -= calculate_damage(hero, enemy1);
        
        if (enemy1.current_hp < 0) enemy1.current_hp = 0;
        printf("%s Counter-Attacks!\n", enemy1.name);
        hero.current_hp -= calculate_damage(enemy1, hero);
        if (hero.current_hp < 0) hero.current_hp = 0;
        //healing potions
        printf("%d potions remaining\n",hero.potions);
        if (hero.current_hp && hero.potions){
            srand(time(NULL));
            int dice_roll = rand() % 100;
            if (dice_roll < hero.magic_skill){
                hero.current_hp = heal(hero, potion_strength);
                hero.potions --;
                printf("%s used a Health Potion!\n",hero.name);
            }
        }

        print_stats(hero);
        print_stats(enemy1);
        printf("Press Enter to continue\n");
        char enter;
        fscanf(stdin, "%c", &enter);
        

    } while (hero.current_hp > 0 && enemy1.current_hp);

    if (hero.current_hp ==0&& (enemy1.current_hp == 0 || enemy1.current_hp == 0)){
        printf("DRAW!\n");

    }
    else if (enemy1.current_hp > 0 && enemy1.current_hp > 0){
        printf("%s Wins!\n", enemy1.current_hp ? enemy1.name : enemy1.name);
    }
    else if ( enemy1.current_hp > 0 || enemy1.current_hp > 0){
        printf("%s and %s Win!\n", enemy1.name, enemy1.name);

    }
    else {
        printf("%s Wins!\n", hero.name);
    }
}


void print_stats(entity_t entity){
    printf("======================\n");
    printf("| %-19s|\n", entity.name);
    if (entity.current_hp >= 10){  printf("| HP: %lf      |\n", entity.current_hp);}
        else{printf("| HP: %lf       |\n", entity.current_hp);}
    printf("| ATTACK: %d DEF: %d |\n", entity.attack, entity.defence);
    if (entity.bravery)    printf("| Bravery: %d.       |\n", entity.bravery);
    printf("======================\n");
}


