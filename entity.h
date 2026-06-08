#ifndef ENTITY_H
#define ENTITY_H

typedef enum{
    HERO,
    ENEMY_DECEPTICON,
    ENEMY_SEEKER,
    ENEMY_QUINTESSON,
    ENEMY_UNICORN

} EntityCatagory;

typedef struct {
    char name[32];
    int max_hp;
    double current_hp;
    int attack;
    int defence;
    int bravery;
    int potions;
    int magic_skill;
    EntityCatagory type;
} entity_t;   //_t shows its a unique type



#endif