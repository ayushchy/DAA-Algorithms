#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void solveColumn(int);
bool isValidPlace(int , int);
void displayBoard();
void solveNqueen();
int queens;
int chessBoard[20][20];
bool hasSolution = false;
 
int main()
{
    printf("Enter number of Queens: ");
    scanf("%d", &queens);
    solveNqueen();
    return 0;
}
 
void solveNqueen(){
    solveColumn(0);
    if(!hasSolution)
        printf("No Solution!! \n");
}

void solveColumn(int col){
    if(col == queens){
        hasSolution = true;
        displayBoard();
        return;
    }
 
    for(int i=0; i<queens; i++){
        if(isValidPlace(i,col)){
            chessBoard[i][col] = 1;
            solveColumn(col+1);
            chessBoard[i][col] = 0;
        }
    }
}
 
bool isValidPlace(int row, int col){

    for(int i=col; i>=0; i--){
        if(chessBoard[row][i] == 1)
            return false;
    }

    for(int i=row, j=col; i>=0 && j>=0; i--,j--){
        if(chessBoard[i][j] == 1)
            return false;
    }

    for(int i=row, j=col; i<queens && j>=0; i++,j--){
        if(chessBoard[i][j] == 1)
            return false;
    }
    return true;
}

void displayBoard(){
    for(int i=0; i<queens; i++){
        for(int j=0; j<queens; j++){
            if(chessBoard[i][j] == 1)
                printf(" Q ");
            else
                printf(" - ");
        }
        printf("\n");
    }
     printf("\n\n");
}
