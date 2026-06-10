#include <stdio.h>

int main(void){

    typedef struct {char* name; int hp; int max_hp;} Enemy;
    Enemy goblin = {.name = "Goblin", .hp = 40, .max_hp = 40};
    Enemy *p    = &goblin;
    (*p).hp = 30;    //will change goblin.hp to 30, dereferencing p gives back the whole struct
    // *p.hp this references incorrectly as it works in the wrong order, equivelent to *(p.hp)
    p->hp == (*p).hp;// true
    p->name == (*p).name;// true
    p->hp -= 10;
    printf("%s HP: %d\n",p->name,p->hp);
    //  -> is almost always used for pointer to struct access
    //  . is on a struct variable,  -> is on a pointer to a struct
    
    //pass-by-value will copy the struct
    //if you pass a pointer instead it avoids the copy, if you don't want ti to edit make it const/read-only
    // passing a pointer only copies the 8 bytes of the pointer
    int x;
    int y;
    x = y = 5;
    printf("%d is the sum of x and y\n",x+y);
    
}