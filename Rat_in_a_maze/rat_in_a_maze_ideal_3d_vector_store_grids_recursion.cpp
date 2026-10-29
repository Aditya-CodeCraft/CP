// Rat in a Maze >gfg (rat starts at (0,0) of an n*m grid of 0/1, can move D L R U through 1-cells only, reach (n-1,m-1); find all paths) - ideal case: returns both direction strings AND each path's visited grid to main using a 3D vector (vector of 2D visit grids). Not needed for gfg, just for the syntax

//ideal case

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int a, int b, int n, int m, int **maze,
            const vector<vector<int>> &visit);

// a = row, b = col
void rat_in_a_maze(int a, int b, int n, int m, int **maze,
                   vector<vector<int>> &visit, string output,
                   vector<string> &ans_gfg,
                   vector<vector<vector<int>>> &paths)
{
    // Base case: reached the destination
    if (a == n - 1 && b == m - 1) {
        visit[n - 1][m - 1] = 1;
        ans_gfg.push_back(output);
        paths.push_back(visit);      // store a copy of this path's grid
        visit[n - 1][m - 1] = 0;     // undo, since visit is shared by reference
        return;
    }

    // Down (D)
    if (isSafe(a + 1, b, n, m, maze, visit)) {
        visit[a][b] = 1;
        rat_in_a_maze(a + 1, b, n, m, maze, visit, output + 'D', ans_gfg, paths);
        visit[a][b] = 0;
    }

    // Left (L)
    if (isSafe(a, b - 1, n, m, maze, visit)) {
        visit[a][b] = 1;
        rat_in_a_maze(a, b - 1, n, m, maze, visit, output + 'L', ans_gfg, paths);
        visit[a][b] = 0;
    }

    // Right (R)
    if (isSafe(a, b + 1, n, m, maze, visit)) {
        visit[a][b] = 1;
        rat_in_a_maze(a, b + 1, n, m, maze, visit, output + 'R', ans_gfg, paths);
        visit[a][b] = 0;
    }

    // Up (U)
    if (isSafe(a - 1, b, n, m, maze, visit)) {
        visit[a][b] = 1;
        rat_in_a_maze(a - 1, b, n, m, maze, visit, output + 'U', ans_gfg, paths);
        visit[a][b] = 0;
    }

    //string output: This could be a reference too, using output.push_back('D') before the call and output.pop_back() after it. That avoids creating a new string at every step. Passing it by value is simpler, though, and it's fine for small mazes.
    //as string has push_back and pop_back() feature

}

bool isSafe(int a, int b, int n, int m, int **maze,
            const vector<vector<int>> &visit)
{
    return !(a >= n || a < 0 || b >= m || b < 0 ||
             maze[a][b] == 0 || visit[a][b] == 1);
}

int main()
{
    int n, m;
    cin >> n >> m;

    int **maze = new int *[n];
    for (int i = 0; i < n; i++)
        maze[i] = new int[m]();      // columns = m (was n before)

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    vector<string> ans_gfg;                        // directions for each path
    vector<vector<vector<int>>> paths;             // one 2D visited grid per path
    vector<vector<int>> visit(n, vector<int>(m, 0));

    rat_in_a_maze(0, 0, n, m, maze, visit, "", ans_gfg, paths);

    // Print results
    for (size_t k = 0; k < ans_gfg.size(); k++) {
        cout << ans_gfg[k] << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << paths[k][i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }

    // Free memory
    for (int i = 0; i < n; i++)
        delete[] maze[i];
    delete[] maze;

    return 0;
}
//ideal case where u also included 3d vector where u sent 2d vector in a vector back to main
