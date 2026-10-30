// Rat in a Maze >gfg (rat starts at (0,0) of an n*m grid of 0/1, can move D L R U through 1-cells only, reach (n-1,m-1); return all paths as direction strings) - why the undo / backtrack step (visit[a][b]=0) is NOT required when visit is passed by value

// ANSWER: why no explicit undo here?
// 1. visit is passed by value (call by value), so every call gets its own copy. visit[a][b]=1 changes only the formal parameter (local copy), the caller's actual grid is untouched.
// 2. When the call returns, that local copy is destroyed, so the formal change itself gets lost automatically. There is nothing left to undo.
// 3. After the call comes back, no related calls are affected: the next if block (next direction) starts from the caller's own grid, which never had the change. Each direction block is a fresh subtree.
// So in call by value the undo is implicit (copy dies on return). In call by reference (see rat_in_a_maze_direction_string_gfg_recursion.cpp) the grid is shared, so there the undo MUST be done explicitly.
// Cost of this convenience: the whole grid is copied on every call, so by-reference + explicit undo is faster.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int,int,int,int,int** ,vector<vector<int>>);

//a=row , b=col
void rat_in_a_maze(int a , int b , int n , int m , int **maze ,vector<vector<int>>visit , string output ,vector<string>&ans_gfg)
{
    if(a==n-1 && b==m-1)
    {
        // The base case doesn't reset visit, because the destination is never marked in this version, and any change would only affect the local copy anyway.
        cout<<output<<endl;
        ans_gfg.push_back(output);
        return;
    } //base case

    if(isSafe(a+1,b,n,m,maze,visit)) //Down
    {
        visit[a][b]=1;
        rat_in_a_maze(a+1,b,n,m,maze,visit,output+'D',ans_gfg);
    }

    if(isSafe(a,b-1,n,m,maze,visit)) //Left
    {
        visit[a][b]=1;
        rat_in_a_maze(a,b-1,n,m,maze,visit,output+'L',ans_gfg);
    }

    if(isSafe(a,b+1,n,m,maze,visit)) //Right
    {
        visit[a][b]=1;
        rat_in_a_maze(a,b+1,n,m,maze,visit,output+'R',ans_gfg);
    }

    if(isSafe(a-1,b,n,m,maze,visit)) //Up
    {
        visit[a][b]=1;
        rat_in_a_maze(a-1,b,n,m,maze,visit,output+'U',ans_gfg);
    }
}

bool isSafe(int a,int b,int n,int m,int **maze,vector<vector<int>> visit)
{
    if(a>=n || a<0 || b>=m || b<0 || maze[a][b]==0 || visit[a][b]==1)
        return false;
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;

    int **maze = new int*[n];
    for(int i=0;i<n;i++)
        maze[i]= new int [m]();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>maze[i][j];
    }

    // DLRU (this gives lexicographical ans)
    vector<string> ans_gfg;
    vector<vector<int>> visit(n,vector<int>(m,0));

    rat_in_a_maze(0,0,n,m,maze,visit,"",ans_gfg);

    for(size_t k=0;k<ans_gfg.size();k++)
        cout<<ans_gfg[k]<<endl;

    for (int i = 0; i < n; i++)
        delete[] maze[i];
    delete[] maze;
    return 0;
}

// so according to u in call by value u never have to undo given the fact after function call returns there are no related calls regarding the element u changes like here its not needed because if block ends and eventually new if block starts so new tree means not related to previous ones
// Each call gets its own copy. When rat_in_a_maze changes visit[a][b]=1, it changes only its local copy. The caller's grid is untouched.
// The changed copy is only used by that call and its children. Once the call returns, its copy is destroyed. Nothing else holds a reference to it.
// Sibling branches start from the caller's grid. When the next if block runs, it calls isSafe and recurses with the caller's visit, which never had the change. So the new branch behaves like a fresh subtree, as you said.
