#include <stdio.h>
#include <ctype.h>

char rot13_char(char c) {
    if (isalpha(c)) {
        if (c >= 'a' && c <= 'z') {
            int offset = c - 'a';
            int rotated = (offset + 13) % 26;
            char result = rotated + 'a';
            return result;
        } else if (c >= 'A' && c <= 'Z') {
            int offset = c - 'A';
            int rotated = (offset + 13) % 26;
            char result = rotated + 'A';
            return result;
        }
    }
    return c;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./rot13 <string>\n");
        return 1;
    }

    char *input_string = argv[1];
    int i = 0;
    while (input_string[i] != '\0') {
        char result_char = rot13_char(input_string[i]);
        putchar(result_char);
        i = i + 1;
    }
    putchar('\n');

    return 0;
}
