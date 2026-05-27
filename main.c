#include <stdio.h>
#include <stdlib.h>

void print_hero_stats(void);
void print_monster_stats(void);
void print_stats(char *name, int attack, double health, int defence, int bravery);
double calculate_damage(int attack, int defence, int bravery);



int main(void){


    int hero_bravery = 10;
    int hero_attack = 10;
    int hero_defence = 10;
    double hero_health = 10.0;
    char hero_name[50] = "Brentel";

    int monster_bravery = 0;
    int monster_attack = 12;
    int monster_defence = 10;
    double monster_health = 10.0;
    char monster_name[50] = "Decepticon";


    printf("===================================\n");
    printf("|   Legally Distinct from Zelda   |\n");
    printf("|               the sequel.       |\n");
    printf("|=================================|\n");

    printf("Enter your hero's name> ");
    fscanf(stdin, "%s", hero_name);

    print_stats(hero_name, hero_attack, hero_health, hero_defence, hero_bravery);
    print_stats(monster_name, monster_attack, monster_health, monster_defence, monster_bravery);

       
    
    do {

        printf("%s Attacks!\n", hero_name);
        monster_health -= calculate_damage(hero_attack, monster_defence, hero_bravery);
        
        if (monster_health < 0) monster_health = 0;
        printf("%s Counter-Attacks!\n", monster_name);
        hero_health -= calculate_damage(monster_attack, hero_defence, 0);
        if (hero_health < 0) hero_health = 0;

        print_stats(hero_name, hero_attack, hero_health, hero_defence, hero_bravery);
        print_stats(monster_name, monster_attack, monster_health, monster_defence, monster_bravery);
        printf("Press Enter to continue\n");
        char enter;
        fscanf(stdin, "%c", &enter);
        

    } while (hero_health > 0 && monster_health > 0);

    if (hero_health ==0&& monster_health == 0) {
        printf("DRAW!\n");

    }
    else if (hero_health > 0 && monster_health == 0){
        printf("Hero Succeeds!\n");

    }
    else {
        printf("You have been DEFEATED\n");
    }
}

void print_stats(char *name, int attack, double health, int defence, int bravery){
    printf("======================\n");
    printf("| %-19s|\n", name);
    printf("| HP: %lf      |\n", health);
    printf("| ATTACK: %d DEF: %d |\n", attack, defence);
    if (bravery)    printf("| Bravery: %d.       |\n", bravery);
    printf("======================\n");
}


double calculate_damage(int attack, int defence, int bravery) {

    float defence_modifier = 0.0;
    srand(0);
    defence_modifier = 1 + rand()%20;
    double adjusted_attack = attack * (1 + ((double) bravery/100));
    double damage =  adjusted_attack - defence;
    
    return (damage < 0) ? 0 : damage;

};