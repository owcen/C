#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void add_first(node **head, int new_data) {
    node *n = (node *)malloc(sizeof(node));
    n->data = new_data;
    n->next = *head;
    *head = n;
}

int list_size(node *head) {
    int counter = 0;
    node *n = head;
    while (n != NULL) {
        counter++;
        n = n->next;
    }
    return counter;
}

void add_by_index(node **head, int value, int index) {
    if (index == 0) {
        add_first(head, value);
    } else {
        node *current = *head;
        int i = 0;

        while (current != NULL && i < index - 1) {
            current = current->next;
            i++;
        }

        if (current == NULL) {
            printf("Nie można wstawić elementu na indeksie %d - indeks przekracza rozmiar listy.\n", index);
            return;
        }

        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = value;

        new_node->next = current->next;
        current->next = new_node;
    }
}

void print_list(node *n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("NULL\n");
}

int main() {
    node *head = NULL;

    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);

    print_list(head);

    add_by_index(&head, 5, 3);
    add_by_index(&head, 4, 0);
    add_by_index(&head, 6, 2);

    print_list(head);

    return 0;
}
