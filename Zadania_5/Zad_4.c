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

void remove_by_index(node ** head, int index){
    if(index == 0 ) {
        node * tmp = NULL;

        if (* head != NULL) {
            tmp = (* head)-> next;
            free(* head);
            * head = tmp;
        }
    }
    else {
        node * n = * head;
        node * tmp;
        int i = 0;
        while (n->next != NULL && i < index -1) {
            n = n->next;
            i++;
        }
        if (n-> next != NULL) {
            tmp = n->next;
            n->next = tmp->next;
            free(tmp);
        }
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

    int index = 1;
    remove_by_index(&head, index);

    print_list(head);

    return 0;
}