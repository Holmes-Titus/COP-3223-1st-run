#include <stdio.h>
#include <stdlib.h>
#include "combat.h"
#include <time.h>

void print_hero_stats(void);
void print_monster_stats(void);
void print_stats(char *name, int attack, double health, int defence, int bravery);




int main(void){

    const int potion_strength = 3;

    int hero_potions = 3;
    int magic_skill = 70;
    int hero_bravery = 10;
    int hero_attack = 10;
    int hero_defence = 10;
    double hero_health = 10.0;
    char hero_name[50] = "Brentel";


    int monster_bravery[] = {0,0};
    int monster_attack[] = {7,12};
    int monster_defence[] = {5,10};
    int monster_health[] = {7.0,10.0};
    char monster_name[2][50] = {
        "Megatron", "Starscream"
    };

    /*int monster_bravery = 0;
    int monster_attack = 12;
    int monster_defence = 10;
    double monster_health = 10.0;
    char monster_name[50] = "Decepticon";
    */


    printf("===================================\n");
    printf("|   Legally Distinct from Zelda   |\n");
    printf("|               the sequel.       |\n");
    printf("|=================================|\n");

    printf("Enter your hero's name> ");
    fscanf(stdin, "%s", hero_name);

    print_stats(hero_name, hero_attack, hero_health, hero_defence, hero_bravery);
    print_stats(monster_name[0], monster_attack[0], monster_health[0], monster_defence[0], monster_bravery[0]);

    for (int i=0; i < 2; i++){   
    
    do {

        

        

        printf("%s Attacks!\n", hero_name);
        monster_health[i] -= calculate_damage(hero_name, hero_attack, monster_defence[i], hero_bravery);
        
        if (monster_health[i] < 0) monster_health[i] = 0;
        printf("%s Counter-Attacks!\n", monster_name[i]);
        hero_health -= calculate_damage(monster_name[i], monster_attack[i], hero_defence, 0);
        if (hero_health < 0) hero_health = 0;
        //healing potions
        printf("%d potions remaining\n",hero_potions);
        if (hero_health && hero_potions){
            srand(time(NULL));
            int dice_roll = rand() % 100;
            if (dice_roll < magic_skill){
                heal(&hero_health, &hero_potions, potion_strength);
                printf("%s Used a Health Potion!\n",hero_name);
            }
        }

        print_stats(hero_name, hero_attack, hero_health, hero_defence, hero_bravery);
        print_stats(monster_name[i], monster_attack[i], monster_health[i], monster_defence[i], monster_bravery[i]);
        printf("Press Enter to continue\n");
        char enter;
        fscanf(stdin, "%c", &enter);
        

    } while (hero_health > 0 && monster_health[i]);

    if (hero_health ==0&& (monster_health[0] == 0 || monster_health[1] == 0)){
        printf("DRAW!\n");

    }
    else if (monster_health[0] > 0 && monster_health[1] > 0){
        printf("%s Wins!\n", monster_health[1] ? monster_name[1] : monster_name[0]);
    }
    else if ( monster_health[0] > 0 || monster_health[1] > 0){
        printf("%s and %s Win!\n", monster_name[0], monster_name[1]);

    }
    else {
        printf("%s Wins!\n", hero_name);
    }
}
}

void print_stats(char *name, int attack, double health, int defence, int bravery){
    printf("======================\n");
    printf("| %-19s|\n", name);
    if (health >= 10){  printf("| HP: %lf      |\n", health);}
        else{printf("| HP: %lf       |\n", health);}
    printf("| ATTACK: %d DEF: %d |\n", attack, defence);
    if (bravery)    printf("| Bravery: %d.       |\n", bravery);
    printf("======================\n");
}


