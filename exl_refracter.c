#include <stdio.h>

void get_dimensions(double *w, double *h);
double compute_area(double w, double h);
double compute_perimeter(double w, double h);
void classify_rectangle(double w, double h);
void print_results(double area, double perimeter);

int main(void) {
    /* --- compute area and perimeter of a rectangle --- */
    double width, height;
    get_dimensions(&width, &height);
    double area = compute_area(width, height);
    double perimeter = compute_perimeter(width, height);
    /* --- classify the rectangle --- */
    classify_rectangle(width, height);
    print_results(area, perimeter);
    return 0;
}

void get_dimensions(double *w, double *h){
    printf("Enter width:  ");
    fscanf(stdin, "%lf", w);
    printf("Enter height: ");
    fscanf(stdin, "%lf", h);
}

double compute_area(double w, double h){
    double area = w * h;
    return area;
}

double compute_perimeter(double w, double h){
    double perimeter = 2.0 * (w + h);
    return perimeter;
}

void classify_rectangle(double w, double h){
    if (w == h) {
    printf("Shape: Square\n");
    } else if (w > h * 2.0 || h > w * 2.0) {
    printf("Shape: Elongated rectangle\n");
    } else {
    printf("Shape: Rectangle\n");
    }
}

void print_results(double area, double perimeter){
    printf("Area:      %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
}