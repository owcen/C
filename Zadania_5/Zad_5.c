#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node * next;
} node;

void add_first(node ** head, int new_data) {
    node * n = (node *) malloc(sizeof(node));
    n->data = new_data;
    n->next = * head;
    * head = n;
}

void remove_by_value(node ** head, int value){
    node * current = * head;
    node * prev = NULL;

    if (current == NULL)
        return;

    if (current->data == value) {
        * head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    prev->next = current->next;
    free(current);
}

void print_list(node * n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("NULL\n");
}

int main() {
    node * head = NULL;

    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);

    print_list(head);

    int value = 3;
    remove_by_value(&head, value);

    print_list(head);

    return 0;
}