#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool visited[100] = {false};

int parent[100] = {-1};
bool cycle = false;

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (visited[child] && parent[par] != child)
            {
                cycle = true;
            }
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parent[child] = par;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }
    if (cycle)
        cout << "Cycle";
    else
        cout << "No Cycle";
}