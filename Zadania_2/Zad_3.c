#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
} Point;

void change(Point *p){
    (*p).x++;
    (*p).y--;
}

typedef struct{
    Point p1;
    Point p2;
} Rectangle;

void dimensions(Rectangle *r, float *field, float *perimeter){
    float a = abs((*r).p1.x - (*r).p2.x);
    float b = abs((*r).p1.y - (*r).p2.y);
    *field = a * b;
    *perimeter = 2 * (a + b);
}

int main(){
    Point p = {1,2};
    printf("Wspolrzedne: %d, %d\n", p.x, p.y);

    change(&p);
    printf("Nowe wspolrzedne: %d, %d\n\n", p.x, p.y);

    Point p1 = {1,2};
    Point p2 = {3,8};
    Rectangle r = {p1, p2};

    float field, perimeter;
    dimensions(&r, &field, &perimeter);
    printf("Pole prostokata: %.2f\n", field);
    printf("Obwod prostokata: %.2f\n", perimeter);

    return 0;
}