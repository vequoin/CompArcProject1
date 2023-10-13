#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function to use with qsort
int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) { // No arguments, so just exit
        return 0;
    }

    // Sorting the arguments using qsort
    qsort(argv + 1, argc - 1, sizeof(char *), compare_strings);

    // Print each sorted argument on a separate line
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}
