#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    float grade;
} Student;

void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void sortStudents(Student *table, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (table[j].grade < table[j + 1].grade) {
                swap(&table[j], &table[j + 1]);
            }
        }
    }
}
int main(){
    int n = 100;
    Student student_list[n];
    for (int i = 0; i < n; i++){
        if (i % 7) {
            sprintf(student_list[i].name, "Anna");
        } else if (i % 5) {
            sprintf(student_list[i].name, "Dorota");
        } else if (i % 4) {
            sprintf(student_list[i].name, "Marcin");
        } else if (i % 3) {
            sprintf(student_list[i].name, "Kuba");
        } else {
            sprintf(student_list[i].name, "Darek");
        }
        student_list[i].grade = rand() % 101;
    }

    sortStudents(student_list, n);

    printf("Posortowana lista studentow:\n");
    for (int i = 0; i < n; i++){
        printf("Imie: %s, ocena: %.2f\n", student_list[i].name, student_list[i].grade);
    }

    return 0;
}