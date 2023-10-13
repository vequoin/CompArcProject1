#include <stdio.h>
#include <stdlib.h>

void multiply(int **A, int **B, int **result, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            result[i][j] = 0;
            for (int l = 0; l < k; l++) {
                result[i][j] += A[i][l] * B[l][j];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    int k;
    fscanf(file, "%d", &k);

    int **matrix = malloc(k * sizeof(int *));
    int **result = malloc(k * sizeof(int *));
    for (int i = 0; i < k; i++) {
        matrix[i] = malloc(k * sizeof(int));
        result[i] = malloc(k * sizeof(int));
        for (int j = 0; j < k; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    int n;
    fscanf(file, "%d", &n);
    fclose(file);

    if (n == 0) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == j) {
                    printf("1 ");
                } else {
                    printf("0 ");
                }
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                result[i][j] = matrix[i][j];
            }
        }

        int **temp = malloc(k * sizeof(int *));
        for (int i = 0; i < k; i++) {
            temp[i] = malloc(k * sizeof(int));
        }

        for (int i = 1; i < n; i++) {
            multiply(result, matrix, temp, k);
            for (int j = 0; j < k; j++) {
                for (int l = 0; l < k; l++) {
                    result[j][l] = temp[j][l];
                }
            }
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < k; i++) {
            free(temp[i]);
        }
        free(temp);
    }

    for (int i = 0; i < k; i++) {
        free(matrix[i]);
        free(result[i]);
    }
    free(matrix);
    free(result);

    return 0;
}
