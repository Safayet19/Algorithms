#include <bits/stdc++.h> // Include all standard libraries
using namespace std;
char grid[105][105]; // Grid to store the input
bool vis[105][105]; // Visited array to keep track of visited cells
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Directions for moving up, down, left, right
int n, m; // Dimensions of the grid

// Function to check if a cell is within grid bounds
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

// Depth-First Search (DFS) function
void dfs(int si, int sj)
{
    cout << si << " " << sj << endl; // Print the current cell
    vis[si][sj] = true; // Mark the current cell as visited
    for (int i = 0; i < 4; i++) // Loop through all 4 possible directions
    {
        int ci = si + d[i].first; // Calculate the new row
        int cj = sj + d[i].second; // Calculate the new column
        if (valid(ci, cj) && !vis[ci][cj]) // Check if the new cell is valid and not visited
            dfs(ci, cj); // Recursively call DFS for the new cell
    }
}

int main()
{
    cin >> n >> m; // Read the dimensions of the grid
    for (int i = 0; i < n; i++) // Loop through all rows
    {
        for (int j = 0; j < m; j++) // Loop through all columns
        {
            cin >> grid[i][j]; // Read each cell value
        }
    }

    int si, sj; // Starting cell coordinates
    cin >> si >> sj; // Read the starting cell coordinates
    memset(vis, false, sizeof(vis)); // Initialize the visited array to false
    dfs(si, sj); // Start DFS from the starting cell
    return 0; // Return 0 to indicate successful execution
}
