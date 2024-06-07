#include <stdio.h>
#include <ctype.h>
#include <string.h>

int word_to_digit(const char *word) {
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1;
}

int find_first_digit(const char *line, int *index) {
    const char *words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int len = strlen(line);
    for (int i = 0; i < len; i++) {
        if (isdigit(line[i])) {
            *index = i;
            return line[i] - '0';
        }
        for (int j = 0; j < 9; j++) {
            int word_len = strlen(words[j]);
            if (strncmp(&line[i], words[j], word_len) == 0) {
                *index = i + word_len - 1;
                return word_to_digit(words[j]);
            }
        }
    }
    return -1;
}

int find_last_digit(const char *line) {
    const char *words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int len = strlen(line);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(line[i])) {
            return line[i] - '0';
        }
        for (int j = 0; j < 9; j++) {
            int word_len = strlen(words[j]);
            if (i >= word_len - 1 && strncmp(&line[i - word_len + 1], words[j], word_len) == 0) {
                return word_to_digit(words[j]);
            }
        }
    }
    return -1;
}

int main() {
    FILE *file = fopen("C:\\Users\\Owcen\\Desktop\\s\\c\\Zadania_7\\input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }

    char line[256];
    int sum = 0;

    while (fgets(line, sizeof(line), file)) {
        int first_digit_index = -1;
        int first_digit = find_first_digit(line, &first_digit_index);
        int last_digit = find_last_digit(line);

        if (first_digit != -1 && last_digit != -1) {
            int value = first_digit * 10 + last_digit;
            sum += value;
        }
    }

    fclose(file);

    printf("Total energy value: %d\n", sum);
    return 0;
}