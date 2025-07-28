#include<iostream>
#include<vector>
using namespace std;

//int count=0;
bool done=false;

void printboard(vector<vector<char>>&board){
    int n=board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------\n";
}

bool isSafe(vector<vector<char>>&board,int row,int col){
    int n=board.size();
    //is horizontally safe
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }
    //is vertivally safe 
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q')
            return false;
    }

    //is diagonal left safe
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    //is diagonally right safr
    for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q')
            return false;
    }

    return true;

}

void NQueens(vector<vector<char>>&board,int row){
    int n=board.size();
    if(done)
        return;
    if(row==n){
        printboard(board);
        done=true;
        return;
    }
    for(int i=0;i<n;i++){
        if(isSafe(board,row,i)){
            board[row][i]='Q';
            NQueens(board,row+1);
            board[row][i]='.';
        }
    }
    return;
}

int main(){
    vector<vector<char>>board;
    int n=6;
    for(int i=0;i<n;i++){
        vector<char> Newrow;
        for(int j=0;j<n;j++){
            Newrow.push_back('.');
        }
        board.push_back(Newrow);
    }

    

    NQueens(board,0);
}
 