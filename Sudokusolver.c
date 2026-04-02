#include <stdio.h>
#include <stdbool.h>

#define N 9

bool isSafe(int board[N][N], int row, int col, int num) {
    for(int x=0;x<9;x++) {
        if(board[row][x]==num || board[x][col]==num)
            return false;
    }

    int startRow = row - row%3;
    int startCol = col - col%3;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[startRow+i][startCol+j]==num)
                return false;

    return true;
}

bool solve(int board[N][N]) {
    int row, col, found = 0;

    for(row=0;row<9;row++) {
        for(col=0;col<9;col++) {
            if(board[row][col]==0) {
                found = 1;
                break;
            }
        }
        if(found) break;
    }

    if(!found) return true;

    for(int num=1;num<=9;num++) {
        if(isSafe(board,row,col,num)) {
            board[row][col]=num;
            if(solve(board))
                return true;
            board[row][col]=0;
        }
    }
    return false;
}

int main() {
    int board[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if(solve(board)) {
        printf("Solved Sudoku:\n");
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
    } else {
        printf("No solution\n");
    }
}
