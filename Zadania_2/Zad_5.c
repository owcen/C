#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct{
    char name[20];
    char surname[50];
    char phone[10];
} Contact;

void addContact(Contact *contacts, int *contactsNumber, char *name, char *surname, char *phone){
    if (*contactsNumber >= MAX_CONTACTS){
        printf("Ksiazka pelna, nie mozna dodac nowego kontaktu.\n");
        return;
    } else {
        strcpy(contacts[*contactsNumber].name, name);
        strcpy(contacts[*contactsNumber].surname, surname);
        strcpy(contacts[*contactsNumber].phone, phone);
        (*contactsNumber)++;
        printf("Kontakt zostal dodany.\n");
    }
}

void searchBySurname(Contact *contacts, int contactsNumber, char *surname){
    printf("Znalezione kontakty dla nazwiska '%s':\n", surname);
    int found = 0;
    for (int i = 0; i < contactsNumber; i++) {
        if (strcmp(contacts[i].surname, surname) == 0) {
            printf("Imie: %s, Nazwisko: %s, Numer telefonu: %s\n",
                   contacts[i].name, contacts[i].surname, contacts[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("Nie znaleziono kontaktu dla podanego nazwiska.\n");
    }
}

void deleteContact(Contact *contacts, int *contactsNumber, char *surname){
    int index = -1;
    for (int i = 0; i < *contactsNumber; i++) {
        if (strcmp(contacts[i].surname, surname) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1)    {
        for (int i = index; i < *contactsNumber - 1; i++){
            contacts[i] = contacts[i + 1];
        }
        (*contactsNumber)--;
        printf("Kontakt zostal usuniety.\n");
    } else {
        printf("Nie znaleziono kontaktu.\n");
    }
}

void showAll(Contact *contacts, int contactsNumber){
    printf("Wszystkie kontakty:\n");
    for (int i = 0; i < contactsNumber; i++){
        printf("Imie: %s, Nazwisko: %s, Numer telefonu: %s\n",
               contacts[i].name, contacts[i].surname, contacts[i].phone);
    }
}

int main(){
    Contact contacts[MAX_CONTACTS];
    int contactsNumber = 0;

    addContact(contacts, &contactsNumber, "Anna", "Mucha", "794561236");
    addContact(contacts, &contactsNumber, "Marcin", "Pies", "794852236");
    addContact(contacts, &contactsNumber, "Jakub", "Bober", "963561236");

    int option;
    char name[50], surname[50], phone[20];

    do {
        printf("\nWybierz opcje:\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdz kontakt\n");
        printf("3. Usun kontakt\n");
        printf("4. Wyswietl wszystkie kontakty\n");
        printf("0. Zakoncz program\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Podaj imie: ");
                scanf("%s", name);
                printf("Podaj nazwisko: ");
                scanf("%s", surname);
                printf("Podaj numer telefonu: ");
                scanf("%s", phone);
                addContact(contacts, &contactsNumber, name, surname, phone);
                break;
            case 2:
                printf("Podaj nazwisko do wyszukania: ");
                scanf("%s", surname);
                searchBySurname(contacts, contactsNumber, surname);
                break;
            case 3:
                printf("Podaj nazwisko do usuniecia: ");
                scanf("%s", surname);
                deleteContact(contacts, &contactsNumber, surname);
                break;
            case 4:
                showAll(contacts, contactsNumber);
                break;
            case 0:
                printf("Program zakonczony.\n");
                break;
            default:
                printf("Niepoprawna opcja. Wybierz ponownie.\n");
        }
    } while (option != 0);

    return 0;
}