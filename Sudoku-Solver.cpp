#include<iostream>
#include<vector>
using namespace std;
bool isvaild(int i,int j,char ch,vector<vector<char>>& board){
    for(int k=0;k<board.size();k++){
        if(board[k][j]==ch) return false;
        if(board[i][k]== ch)  return false;
        if(board[3*(i/3)+k/3][3*(j/3)+k%3]== ch) return false;
    }
    return true;
}
bool sudokusolver(vector<vector<char>>&board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[i][j]=='.'){
                for(char ch='1';ch<='9';ch++){
                    if(isvaild(i,j,ch,board)){
                        board[i][j]=ch;
                        if(sudokusolver(board)) return true;
                        board[i][j]='.';
                    }
                
                }
                 return false;
            }
           
        }
    }
    return true;
}
int main() {

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
     if(sudokusolver(board)) {
        cout << "Solved Sudoku:\n";

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No solution exists\n";
    }

    return 0;
}