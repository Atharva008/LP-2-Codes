#include<bits/stdc++.h>
using namespace std;


bool isSafe(int row , int col , vector<string> board , int n){
    int drow = row , dcol = col;
    while(row >= 0 and col >= 0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }
    row = drow , col = dcol;
    while(col >= 0){
        if(board[row][col] == 'Q') return false;
        col--;
    }
    row = drow , col = dcol;
    while(row < n and col >= 0){
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    return true;
}


void solve(int col , vector<string> &board , vector<vector<string>> &ans , int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0 ; row < n ; row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 'Q';
            solve(col+1,board,ans,n);
            board[row][col] = '.';
        }
    }

}

int main(){
    int n;
    cin >> n;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i = 0 ; i < n ; i++) board[i] = s;
    solve(0,board,ans,n);

    for(auto board : ans){
         for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cout << board[i][j] << ' ';
            }
            cout << "\n";
        }
        cout << "\n";
    }
    cout << "\n";

    return 0;
}