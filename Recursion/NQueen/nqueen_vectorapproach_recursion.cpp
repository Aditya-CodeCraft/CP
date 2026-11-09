// 51. N-Queens >leetcode - vector approach
// Same logic as NQueen/nqueen_ArrayApproach_recursion.cpp, just changed int **board (array) to vector<vector<int>> board, so no new/delete needed

#include <iostream>
#include <vector>
using namespace std;

 bool isSafe(int r, int c , int n , vector<vector<int>> &board) //pass by reference else whole board gets copied on every call
    {
        int cr=r; //copy row
        int cc=c; //copy column
        
        while(c>=0) //row fixed         <------------------- left move straight
        {
            if(board[r][c]==1)
                return false;
            c--;
        }
        
        r=cr;
        c=cc;
        
        while(r>=0 && c>=0)
        {
            if(board[r][c]==1)
                return false;
            c--; r--;
        }
        
        r=cr;
        c=cc;
        
        while(r<n && c>=0)
        {
            if(board[r][c]==1)
                return false;
            c--; r++;
        }
        
        return true;
        
        
    }

void solve(int col , int n , vector<vector<int>> &board){ //pass by reference else whole board gets copied on every call
    if(col==n){
        for (int i = 0; i < n; i++)
        {
           for (int j = 0; j < n; j++)
                cout<<board[i][j]<< " ";
            cout<<endl;
        } 
        cout<<endl;
        return;
    }
    
    
    //now check each col row-wise
    for(int r=0; r<n; r++) //r<m
    {
        int c=col;
        if(isSafe(r,c,n,board)){
            board[r][c]=1;
            solve(col+1,n,board);
            board[r][c]=0; //undo or backtrack
        }
    }
    
}    







int main()
{
    int n,m;
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n, 0)); //check last line row , col template
    
    //our funda is har column me jayenge and check can Q be placed on this row or not or we check that col row-wise
    solve(0,n,board); // considering n*n only 
    
}





// Note : Imp
// So in vector<vector<int>> board(rows, vector<int>(cols, 0));:

// rows → number of rows (how many inner vectors)
// vector<int>(cols, 0) → the template for each row; its length cols is what sets the column count

// default value in the col template can be changed as per need, e.g.
// vector<vector<char>> grid(rows, vector<char>(cols, '.'));
// vector<vector<bool>> vis(rows, vector<bool>(cols, false));
