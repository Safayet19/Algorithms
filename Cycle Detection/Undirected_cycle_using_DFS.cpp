#include <bits/stdc++.h>
using namespace std;

vector<int> adj_List[100];
bool visited[100] = {false};
bool path_visit[100] = {false};
bool cycle = false;

void dfs(int source, int parent)
{
    visited[source] = true;
    path_visit[source] = true;

    for (int child : adj_List[source])
    {
        if (visited[child] && child != parent) // Ensure it's not the parent node
        {
            cycle = true;
        }
        if (!visited[child])
        {
            dfs(child, source);
        }
    }
    path_visit[source] = false;
}

int main()
{
    int v, e;
    cin >> v >> e;

    while (e--)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj_List[v1].push_back(v2);
        adj_List[v2].push_back(v1);
    }

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1);
        }
    }

    if (cycle)
        cout << "Cycle";
    else
        cout << "No Cycle";

    return 0;
}
