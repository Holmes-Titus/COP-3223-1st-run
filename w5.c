#include <stdio.h>

int main(void){

//typedef creates a new name for an existing type
typedef unsigned long long unit64;  //renames the unsigned long long type to unit64
typedef int PlayerID;
PlayerID player = 42;
int player2 = 43;
//This exists for readability and convertability
//because bits/variable cna be differetn, you can hide these differences behind a typedef
//typedef int32_t Score;
typedef char * String;
//hiding the * inside can cause you to forget it is a pointer
//Structs and Ennums
struct Point { int x; int y; };
struct Point p1;
// both methods create struct, but second method doesn't need struct to call
typedef struct { int x; int y; } Point1;
Point1 p2;
/*
enum EnemyType {
    slime,  //0
    bat,    //1
    bulbasaur,  //2
    goomba  //3
};
enum EnemyType type = bulbasaur;
if (type == bulbasaur){
    printf("A bulbasaur has appeared");
}
*/

typedef enum {
    slime,  //0
    bat,    //1
    bulbasaur,  //2
    goomba  //3;
}EnemyType2;

typedef struct { char* name; int enemy_hp; int enemy_max_hp; int enemy_attack; int enemy_defence; EnemyType2 type;} Enemy;

//Enemy decepticon;

//Enemy decepticon = {"Decepticon", 40, 40, 10, 5, bulbasaur};

Enemy decepticon = {
    .name = "Decepticon",
    .enemy_hp = 40,
    .enemy_max_hp = 40,
    .enemy_attack = 10,
    .enemy_defence = 5,
    .type = goomba
};

printf("Name: %s\n",decepticon.name);

}