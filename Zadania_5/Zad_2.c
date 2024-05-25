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

void pop(node ** head) {
    node * tmp = NULL;

    if (* head != NULL) {
        tmp = (* head)-> next;
        free(* head);
        * head = tmp;
    }
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

    pop(&head);

    print_list(head);

    return 0;
}