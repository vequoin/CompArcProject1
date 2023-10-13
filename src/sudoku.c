#include <stdio.h>
#include <stdbool.h>

#define SIZE 9


bool isRowValid(int board[SIZE][SIZE], int row) {
    int checker[] = {0, 0 ,0, 0, 0,0 ,0 ,0, 0};
    for (int col = 0; col < SIZE; col++) {
       if(checker[board[row][col]] == 0){
            checker[board[row][col]] = 1;
       }

       else{
         return false;
       } 
    }
    return true;
}

bool isColValid(int board[SIZE][SIZE], int col) {
    int flag[SIZE] = {0};
    for (int row = 0; row < SIZE; row++) {
        if (board[row][col] == '_') continue;
        if (flag[board[row][col] - 1]) return false;
        flag[board[row][col] - 1] = 1;
    }
    return true;
}

bool isBoxValid(int board[SIZE][SIZE], int startRow, int startCol) {
    int flag[SIZE] = {0};
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row + startRow][col + startCol] == '_') continue;
            if (flag[board[row + startRow][col + startCol] - 1]) return false;
            flag[board[row + startRow][col + startCol] - 1] = 1;
        }
    }
    return true;
}

bool isValidSudoku(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (!isRowValid(board, i) || !isColValid(board, i)) return false;
        if (!isBoxValid(board, 3 * (i / 3), 3 * (i % 3))) return false;
    }
    return true;
}

int main() {
    int board[SIZE][SIZE];
    char c;
    FILE *file = fopen("file1.txt", "r");
    if (file == NULL) {
        printf("error\n");
        return 1;
    }

    bool isComplete = true;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            c = fgetc(file);
            if(c == '_') {
                board[i][j] = 0;
                isComplete = false;
            }else{board[i][j] = c - '0'};
        }
        fgetc(file);  // Consume newline character
    }
    fclose(file);

    if (isComplete){
        if(isValidSudoku(board)){
            printf("correct \n");
        }
        else printf("incorrect ]n");
    }

    return 0;
}
