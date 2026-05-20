#include <stdio.h>
#include <stdlib.h>

void print_hero_stats(void);
void print_monster_stats(void);
double calculate_damage(int, int, int);

int hero_bravery = 10;
int hero_attack = 10;
int hero_defence = 10;
double hero_health = 10.0;
char hero_name[50] = "Brentel";
int monster_attack = 12;
int monster_defence = 10;
double monster_health = 10.0;
char monster_name[50] = "Decepticon";

int main(void){
    printf("===================================\n");
    printf("|   Legally Distinct from Zelda   |\n");
    printf("|               the sequel.       |\n");
    printf("|=================================|\n");

    printf("Enter your hero's name> ");
    fscanf(stdin, "%s", hero_name);

    print_hero_stats();
    print_monster_stats();
       
    
    do {

        printf("%s Attacks!\n", hero_name);
        monster_health -= calculate_damage(hero_attack, monster_defence, hero_bravery);
        if (monster_health < 0) monster_health = 0;
        printf("%s Counter-Attacks!\n", monster_name);
        hero_health -= calculate_damage(monster_attack, hero_defence, 0);
        if (hero_health < 0) hero_health = 0;

        print_hero_stats();
        print_monster_stats();
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

void print_hero_stats(void) {
    printf("======================\n");
    printf("| %-19s|\n", hero_name);
    printf("| HP: %lf      |\n", hero_health);
    printf("| ATTACK: %d DEF: %d |\n", hero_attack, hero_defence);
    printf("| Bravery: %d.       |\n", hero_bravery);
    printf("======================\n");

};

void print_monster_stats(void) {
    printf("======================\n");
    printf("| %-19s|\n", monster_name);
    printf("| HP: %lf      |\n", monster_health);
    printf("| ATTACK: %d DEF: %d |\n", monster_attack, monster_defence);
    printf("======================\n");
};

double calculate_damage(int attack, int defence, int bravery) {

    float defence_modifier = 0.0;
    srand(0);
    defence_modifier = 1 + rand()%20;
    double adjusted_attack = attack * (1 + ((double) bravery/100));
    double damage =  adjusted_attack - defence;
    
    return (damage < 0) ? 0 : damage;

};