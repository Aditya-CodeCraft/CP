// 51. N-Queens >leetcode (print all boards where N queens are placed on an N*N board so that no two attack each other) - 2D array approach

#include <iostream>
using namespace std;

 bool isSafe(int r, int c , int n , int **board)
    {
        int cr=r; //copy row
        int cc=c; //copy column
        
        while(c>=0) //row fixed         <------------------- left straight move
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

void solve(int col , int n , int **board){
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
    cin>>n>>m; //however board is always square so put n=m = same no
    
    int **board = new int *[n]; //row 
    for(int i=0;i<n;i++) //col
        board[i] = new int[m](); //() zero-initializes u cant put any 1 in first bracket remember malloc/calloc this calloc and filling with a default ur own value is possible in vectors 
    
    
    //our funda is har column me jayenge and check can Q be placed on this row or not or we check that col row-wise
    solve(0,n,board); // considering n*n only 
    
    for (int i = 0; i < n; i++)
        delete[] board[i]; //delete the row pointers or 1d ones
    delete[] board; //delete the 2d one or pointer to pointer vala
}





// Note : Imp
// So in vector<vector<int>> board(rows, vector<int>(cols, 0));:

// rows → number of rows (how many inner vectors)
// vector<int>(cols, 0) → the template for each row; its length cols is what sets the column count
