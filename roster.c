#include "roster.h"
#include <stdio.h>


Student create_student(const char *first, const char *last, int id, double gpa){
    
    Student new_student = {
        .first_name = *first,
        .last_name = *last,
        .student_id = id,
        .gpa = gpa
    };
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
    if (roster_find_by_id(r,s.student_id) == NULL) return -1;
    int count = 0;

}

int roster_remove(Roster *r, int student_id){

}

Student *roster_find_by_id(Roster *r, int student_id){

}

Student *roster_find_by_name(Roster *r, const char *last_name){

}

void roster_sort_by_name(Roster *r){

}

void roster_sort_by_gpa(Roster *r){


}
void print_student(const Student *s){

}

void print_roster(const Roster *r){

}

const char *grade_to_string(Grade g){

}

double roster_average_gpa(const Roster *r){

}
