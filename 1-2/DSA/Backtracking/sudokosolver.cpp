#include<iostream>
#include<algorithm>
using namespace std;

void printsudoku(int sudoku[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int sudoku[9][9],int row,int col,int digit){
    //vertical
    for(int i=0;i<9;i++){
        if(sudoku[i][col]==digit){
            return false;
        }
    }
    //horizontal
    for(int j=0;j<9;j++){
        if(sudoku[row][j]==digit){
            return false;
        }
    }
    //in 3X3 grid
    int startRow=(row/3)*3;
    int startCol=(col/3)*3;
    for(int i=startRow;i<startRow+3;i++){
        for(int j=startCol;j<startCol+3;j++){
            if(sudoku[i][j]==digit)
                return false;
        }
    }
    return true;
}

bool sudokusolver(int sudoku[9][9],int row,int col){
    if(row==9){
        printsudoku(sudoku);
        return true;
    }
    int NextRow=row;
    int NextCol=col+1;
    if(NextCol==9){
        NextRow=row+1;
        NextCol=0;
    }

    if(sudoku[row][col]!=0){
        return sudokusolver(sudoku,NextRow,NextCol);
    }

    for(int dig=1;dig<=9;dig++){
        if(isSafe(sudoku,row,col,dig)){
            sudoku[row][col]=dig;
            if(sudokusolver(sudoku,NextRow,NextCol)){
                return true;
            }
            sudoku[row][col]=0;
        }
    }
    return false;
}

int main(){
    int sudoku[9][9]={
        {0,0,8,0,0,0,0,0,0},
        {4,9,0,1,5,7,0,0,2},
        {0,0,3,0,0,4,1,9,0},
        {1,8,5,0,6,0,0,2,0},
        {0,0,0,0,2,0,0,6,0},
        {9,6,0,4,0,5,3,0,0},
        {0,3,0,0,7,2,0,0,4},
        {0,4,9,0,3,0,0,5,7},
        {8,2,7,0,0,9,0,1,3}
    };
    sudokusolver(sudoku,0,0);
    return 0;
}