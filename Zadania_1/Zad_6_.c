#include <stdio.h>
#include <stdlib.h>

int computerMove() {
    return rand() % 3;
}

int playerMove() {
  int move;
  printf("Wybierz ruch:\n1- papier\n2- kamien\n3 -nozyce\n");
  scanf("%i", &move);
  return move - 1;
}

int compareMoves(int playerMove, int computerMove) {
    if ((playerMove == 0 && computerMove == 1) || // papier pokonuje kamień
        (playerMove == 1 && computerMove == 2) || // kamień pokonuje nożyce
        (playerMove == 2 && computerMove == 0))   // nożyce pokonują papier
        return 1; // gracz wygrywa
    else if (playerMove == computerMove)
        return 0; // remis
    else
        return -1; // komputer wygrywa
}

int areStringsEqual(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(){
    int scores[100];
    int round = 0;
    char command[10];

    srand(0);

    while (1){
        int playerMoveResult = playerMove();
        if (playerMoveResult < 0 || playerMoveResult > 2) {
            printf("Niepoprawny ruch. Podaj liczbe od 1 do 3.\n");
            continue;
        }

        int computerMoveResult = computerMove();
        if (computerMoveResult == 0)
            printf("Komputer wybral papier\n");
        else if (computerMoveResult == 1)
            printf("Komputer wybral kamien\n");
        else
            printf("Komputer wybral nozyce\n");

        int result = compareMoves(playerMoveResult, computerMoveResult);
        scores[round] = result;
        round++;

        printf("Wynik: ");
        if (result == 0)
            printf("Remis\n");
        else if (result == 1)
            printf("Gracz wygrywa\n");
        else
            printf("Komputer wygrywa\n");

        printf("Wpisz 'scores', aby zobaczyc wyniki rund, jesli chcesz kontynuowac gre wybierz dowolna litere\n");
        scanf("%s", command);

        if (areStringsEqual("scores", command)) {
            printf("Wyniki rund:\n");
            for (int i = 0; i < round; i++) {
                if (scores[i] == 1)
                    printf("Runda %d: Wynik: Wygrana gracza\n", i +1);
                else if (scores[i] == 0)
                    printf("Runda %d: Wynik: Remis\n", i +1);
                else
                    printf("Runda %d: Wynik: Komputer wygrywa\n", i +1);
            }
            break;
        }
    }
    return 0;
};