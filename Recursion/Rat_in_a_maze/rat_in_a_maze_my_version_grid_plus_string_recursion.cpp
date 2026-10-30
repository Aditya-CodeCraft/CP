// Rat in a Maze >gfg (rat starts at (0,0) of an n*m grid of 0/1, can move D L R U through 1-cells only, reach (n-1,m-1); find all paths) - my own version: prints the visited grid AND the direction string for each path, visit by value, output string built with output+'D' etc.

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int,int,int,int,int** ,vector<vector<int>>);

//a=row , b=col
void rat_in_a_maze(int a , int b , int n , int m , int **maze ,vector<vector<int>>visit , string output ,vector<string>&ans_gfg)  //should visit be passed by reference?
{
    if(a==n-1 && b==m-1)
    {
        visit[n-1][m-1]=1;  //will check back
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<visit[i][j]<< " ";

        cout<<endl;
        }
        // visit[n-1][m-1]=0;//will check back > undo step not needed since visit is sent to this call by value not by reference so changes made here wont reflect in actual
        cout<<output<<endl<<endl;
        ans_gfg.push_back(output); //gfg lvl sh*t

    cout<<endl;
        // visit[n-1][m-1]=0; //will check back > undo

    return;

    } //base case

    if(isSafe(a+1,b,n,m,maze,visit)) //Down
    {
        visit[a][b]=1;
        rat_in_a_maze(a+1,b,n,m,maze,visit,output+'D',ans_gfg);
        visit[a][b]=0; //undo ...kyuki picture or possibilites abhi baki h
    }

    //note u cant do else if >vrna u cant generate all possibility
    if(isSafe(a,b-1,n,m,maze,visit)) //Left
    {
        visit[a][b]=1;
        rat_in_a_maze(a,b-1,n,m,maze,visit,output+'L',ans_gfg);
        visit[a][b]=0; //undo ...kyuki picture or possibilites abhi baki h
    }

    if(isSafe(a,b+1,n,m,maze,visit)) //Right
    {
        visit[a][b]=1;
        rat_in_a_maze(a,b+1,n,m,maze,visit,output+'R',ans_gfg);
        visit[a][b]=0; //undo ...kyuki picture or possibilites abhi baki h
    }

    if(isSafe(a-1,b,n,m,maze,visit)) //Up
    {
        visit[a][b]=1;
        rat_in_a_maze(a-1,b,n,m,maze,visit,output+'U',ans_gfg);
        visit[a][b]=0; //undo ...kyuki picture or possibilites abhi baki h
    }



}


bool isSafe(int a,int b, int n , int m , int **maze ,vector<vector<int>>visit){
    if(a>=n || a<0 || b>=m || b<0 || maze[a][b]==0 || visit[a][b]==1) //visit[a][b]==1 is to block back and front or infinite loop kinda situation
        return false;
        return true;
}



int main()
{
    int n,m; //input dimension
    cin>>n>>m;

    int **maze = new int*[n]; //row
    for(int i=0;i<n;i++)
        maze[i]= new int [m](); //col

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>maze[i][j]; //take maze as ip
    }

    // DLRU (this gives lexiographical ans)

    vector<string>ans_gfg;

    vector<vector<int>>visit(n,vector<int>(m,0)); //visited array or vector
    cout<<endl;
    rat_in_a_maze(0,0,n,m,maze,visit,"",ans_gfg); //starting coordinates sent since 2D so (0,0)
    //in gfg they will ask to return vector of string direction

    //how to store a 2d vector in a 3d one ? >> check ideal vala file

     for (int i = 0; i < n; i++)
        delete[] maze[i];
    delete[] maze;
    return 0;
}
