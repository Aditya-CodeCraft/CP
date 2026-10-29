// 51. N-Queens >leetcode - rectangular n*m board variant: why n<m (rows < columns) gives no solution, with explanation

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

void solve(int col , int n , int m, int **board){
    if(col==m){                                   //since we going col wise
        for (int i = 0; i < n; i++)
        {
           for (int j = 0; j < m; j++)
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
            solve(col+1,n,m,board);
            board[r][c]=0; //undo or backtrack
        }
    }
    
}    







int main()
{
    int n,m;
    cout<<"your 1st value has to be > 2nd else u wont get any result: However I have fixed this now so smaller 1st itself will have bigger value due to swap XD: \n" ;
    cin>>n>>m; //however board is always square
    
    if(n<m)
    swap(n,m);  //kyu yet natak see last line
    
    int **board = new int *[n]; //row 
    for(int i=0;i<n;i++) //col
        board[i] = new int[m](); //() zero-initializes u cant put any 1 in first bracket remember malloc/calloc this calloc and filling with a default ur own value is possible in vectors 
    
    
    //our funda is har column me jayenge and check can Q be placed on this row or not or we check that col row-wise
    solve(0,n,m,board); // considering n*n only 
    
    for (int i = 0; i < n; i++)
        delete[] board[i]; //delete the row pointers or 1d ones
    delete[] board; //delete the 2d one or pointer to pointer vala
}





// Note : Imp
// So in vector<vector<int>> board(rows, vector<int>(cols, 0));:

// rows → number of rows (how many inner vectors)
// vector<int>(cols, 0) → the template for each row; its length cols is what sets the column count

// For a rectangular board, solutions can only exist when rows ≥ columns (n ≥ m).  

// if n<m
// col 0: try r=0 → safe → place Q at (0,0), go to col 1
//   col 1: r=0 → attacked (same row)      ✗
//          r=1 → attacked (diagonal)      ✗
//          r=2 → safe → place Q at (2,1), go to col 2
//     col 2: r=0 → safe → place Q at (0,2)? no wait (0,0) is same row ✗
//           r=1 → safe → place Q at (1,2), go to col 3
//       col 3: r=0 → row 0 has Q (0,0)    ✗
//              r=1 → row 1 has Q (1,2)    ✗
//              r=2 → row 2 has Q (2,1)    ✗
//              for-loop ends → return       ← this is the "loop out"
//       undo (1,2), try r=2 at col 2 → attacked by (2,1) ✗ → loop ends → return
//     undo (2,1), col 1 loop ends → return
//   undo (0,0), try r=1 at col 0 ... same story
//   ...
// col 0 loop ends → solve(0,...) returns to main

// so, 
// isSafe returning false for all rows → for loop exhausts → return → that’s your dead end.
// Backtracking (board[r][c] = 0) then tries alternatives upstream.
// When every alternative is exhausted, solve(0, ...) returns silently.

// TL-DR
// we consider or have made the code in such a way that each col should have a queen right > if (col == m) { ...print...; return; }   // success only when ALL m columns are done
// thats why swap(n,m) if n<m
