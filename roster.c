#include "roster.h"
#include <stdio.h>
#include <string.h>


Student create_student(const char *first, const char *last, int id, double gpa){
    Student new_student = {
        .student_id = id,
        .gpa = gpa
    };
    strcpy(new_student.first_name,first);
    new_student.first_name[strcspn(new_student.first_name,"\n")] = '\0';
    strcpy(new_student.last_name,last);
    new_student.last_name[strcspn(new_student.last_name,"\n")] = '\0';
    if (gpa > 4 || gpa < 0) new_student.standing = GRADE_INVALID;
    else if (gpa >= 3.5) new_student.standing = GRADE_A;
    else if (gpa >= 3) new_student.standing = GRADE_B;
    else if (gpa >= 2) new_student.standing = GRADE_C;
    else if (gpa >= 1) new_student.standing = GRADE_D;
    else    new_student.standing = GRADE_F;
    return new_student;
}

int roster_add(Roster *r, Student s){
    if ((*r).count == MAX_STUDENTS) return 0;
    if (roster_find_by_id(r,s.student_id) == NULL) {
        (*r).students[(*r).count] = s;
        (*r).count++;
        return 1;
    } 
    return -1;
}

int roster_remove(Roster *r, int student_id){
    if (roster_find_by_id(r,student_id)==NULL) return 0;
    for (int i = 0; i < (*r).count; i++){
        if ((*r).students[i].student_id == student_id){
            for (int j = i; j < (*r).count-i;j++){
                (*r).students[i] = (*r).students[i+1];
            }
        }
    }
    (*r).count--;
    return 1;
}

Student *roster_find_by_id(Roster *r, int student_id){
    for (int i = 0; i < (*r).count; i++){
        if ((*r).students[i].student_id == student_id){
            return &(*r).students[i];
        }
    }
    return NULL;
}

Student *roster_find_by_name(Roster *r, const char *last_name){
    for (int i = 0; i < (*r).count; i++){
        if (strcmp((*r).students[i].last_name,last_name) == 0){
            return &(*r).students[i];
        }
    }
    return NULL;
}

void roster_sort_by_name(Roster *r){
    int count = (*r).count;
    while (count > 0){
        for (int i = 0; i < (*r).count-1;i++){
            if ((strcmp((*r).students[i].last_name,(*r).students[i+1].last_name)) > 0){
                Student temp = (*r).students[i+1];
                (*r).students[i+1] = (*r).students[i];
                (*r).students[i] = temp;
            }
        }
        count --;
    }
}

void roster_sort_by_gpa(Roster *r){
    int count = (*r).count;
    while (count > 0){
        for (int i = 0; i < (*r).count-1;i++){
            if (((*r).students[i].gpa<(*r).students[i+1].gpa)){
                Student temp = (*r).students[i+1];
                (*r).students[i+1] = (*r).students[i];
                (*r).students[i] = temp;
            }
        }
        count --;
    }
}
void print_student(const Student *s){
    printf("  [%d] %s, %-10s  GPA: %.2f Standing: %s\n",s->student_id,s->last_name,s->first_name,s->gpa,grade_to_string(s->standing));
}

void print_roster(const Roster *r){
    printf("╔══════════════════════════════════════════════════╗\n║  Student Roster (%d students)%-21s║\n╠══════════════════════════════════════════════════╣\n",(*r).count,"");
    for (int i = 0; i < (*r).count; i++){
        print_student(&(*r).students[i]);
    }
    printf("╠══════════════════════════════════════════════════╣\n║  Class average GPA: %.2f %-24s║\n╚══════════════════════════════════════════════════╝\n",roster_average_gpa(r),"");
}

const char *grade_to_string(Grade g){
    switch(g){
        case 0: return "A";
        case 1: return "B";
        case 2: return "C";
        case 3: return "D";
        case 4: return "F";
        default: return "Incomplete";
    }
}

double roster_average_gpa(const Roster *r){
    double avg = 0.0;
    if ((*r).count == 0) return 0.0;
    for (int i = 0; i < (*r).count; i++){
        avg += (*r).students[i].gpa;
    }
    avg /= (*r).count;
    return avg;
}
