#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

FILE *file = fopen(argv[1], "r");
    if(!file) {
        printf("error\n");
        return 1;
    }

 char board[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = fgetc(file);
        }
        // Skip the newline
        fgetc(file);
    }
    fclose(file);


bool isCompleteSudoku(int sudoku[SIZE][SIZE]){
    for( int i = 0;i < SIZE;i++){
        for(int j = 0; j < SIZE; j++){
            if(sudoku[i][j] == '_'){
                return false;
            }
        }
    }
    return true;
}


bool isValidRow(){
    for(int i = 0;i < SIZE;i++){
        for(int j = 0 ; j < SIZE; j++){

        }
    }
}