// Rat in a Maze >gfg (rat starts at (0,0) of an n*m grid of 0/1, can move D L R U through 1-cells only, reach (n-1,m-1); return all paths as direction strings) - gfg style: visit by reference, output string by reference with push_back/pop_back, paths collected in vector<string>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int,int,int,int,int** ,vector<vector<int>>&);

//a=row , b=col
void rat_in_a_maze(int a , int b , int n , int m , int **maze ,vector<vector<int>>&visit , string &output ,vector<string>&ans_gfg)
{
    if(a==n-1 && b==m-1)
    {
        cout<<output<<endl;
        ans_gfg.push_back(output);
        return;
    } //base case

    if(isSafe(a+1,b,n,m,maze,visit)) //Down
    {
        visit[a][b]=1;
        output.push_back('D'); //string push only accepts a single character ('a'), not a full string literal ("abc"). 
        rat_in_a_maze(a+1,b,n,m,maze,visit,output,ans_gfg); 
        output.pop_back();
        visit[a][b]=0;
    }


    
    if(isSafe(a,b-1,n,m,maze,visit)) //Left
    {
        visit[a][b]=1;
        output.push_back('L');
        rat_in_a_maze(a,b-1,n,m,maze,visit,output,ans_gfg);
        output.pop_back();
        visit[a][b]=0;
    }

    if(isSafe(a,b+1,n,m,maze,visit)) //Right
    {
        visit[a][b]=1;
        output.push_back('R');
        rat_in_a_maze(a,b+1,n,m,maze,visit,output,ans_gfg);
        output.pop_back();
        visit[a][b]=0;
    }

    if(isSafe(a-1,b,n,m,maze,visit)) //Up
    {
        visit[a][b]=1;
        output.push_back('U');
        rat_in_a_maze(a-1,b,n,m,maze,visit,output,ans_gfg);
        output.pop_back();
        visit[a][b]=0;
    }
}

bool isSafe(int a,int b,int n,int m,int **maze,vector<vector<int>>&visit)
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
    string output;
    vector<vector<int>> visit(n,vector<int>(m,0));

    rat_in_a_maze(0,0,n,m,maze,visit,output,ans_gfg);

    // ans_gfg now holds every path; print or return it as needed
    for(size_t k=0;k<ans_gfg.size();k++)
        cout<<ans_gfg[k]<<endl;

    for (int i = 0; i < n; i++)
        delete[] maze[i];
    delete[] maze;
    return 0;
}
