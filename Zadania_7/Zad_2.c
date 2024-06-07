#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int red;
    int green;
    int blue;
} DiceCount;

typedef struct {
    int gameId;
    DiceCount* diceCounts;
    int numDiceCounts;
} Game;

Game parseGame(char* line) {
    Game game;
    char* token;
    int count = 0;

    token = strtok(line, ":");
    sscanf(token, "Game %d", &game.gameId);

    token = strtok(NULL, ";");
    game.numDiceCounts = 0;
    game.diceCounts = malloc(sizeof(DiceCount));

    while (token != NULL) {
        DiceCount diceCount;
        sscanf(token, "%d %*s, %d %*s, %d %*s", &diceCount.red, &diceCount.green, &diceCount.blue);
        game.diceCounts = realloc(game.diceCounts, (count + 1) * sizeof(DiceCount));
        game.diceCounts[count] = diceCount;
        count++;
        game.numDiceCounts++;
        token = strtok(NULL, ";");
    }

    return game;
}

int isPossible(Game game, int red, int green, int blue) {
    for (int i = 0; i < game.numDiceCounts; i++) {
        if (game.diceCounts[i].red > red || game.diceCounts[i].green > green || game.diceCounts[i].blue > blue) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE* file = fopen("C:\\Users\\Owcen\\Desktop\\s\\c\\Zadania_7\\input.txt", "r");
    char line[256];
    int sumPossibleGames = 0;
    int sumMinimumPowers = 0;

    int red = 12;
    int green = 13;
    int blue = 14;

    if (file == NULL) {
        perror("Nie mozna otworzyc pliku");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        Game game = parseGame(line);

        if (isPossible(game, red, green, blue)) {
            sumPossibleGames += game.gameId;

            int minPower = red * green * blue;
            for (int i = 0; i < game.numDiceCounts; i++) {
                int power = game.diceCounts[i].red * game.diceCounts[i].green * game.diceCounts[i].blue;
                if (power < minPower) {
                    minPower = power;
                }
            }
            sumMinimumPowers += minPower;
        }

        free(game.diceCounts);
    }

    fclose(file);

    printf("Suma identyfikatorow gier mozliwych do zagrania: %d\n", sumPossibleGames);
    printf("Suma minimalnych mocy zestawów kostek: %d\n", sumMinimumPowers);

    return 0;
}
