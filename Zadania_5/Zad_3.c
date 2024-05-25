#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
} node;

void add_first(node ** head, int new_data) {
    node * n = (node *) malloc(sizeof(node));
    n->data = new_data;
    n->next = * head;
    * head = n;
}

void remove_last(node ** head){
    if (( * head)->next == NULL)
        * head = NULL;
    else {
        node * n = * head;
        while (n->next->next != NULL)
            n = n->next;
        free(n->next);
        n->next = NULL;
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

    remove_last(&head);

    print_list(head);

    return 0;
}