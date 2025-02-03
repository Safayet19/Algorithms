#include <bits/stdc++.h>
using namespace std;
vector<int> adj_List[1000];

void bfs(int source)
{
    bool visited[1000] = {false};
    queue<int> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        cout << parent << " ";

        for (int child : adj_List[parent])
        {
            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
            }
        }
    }
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

    bfs(0); // source 0
}
// Example:
// 7 7
// 0 1
// 1 3
// 1 4
// 3 2
// 4 6
// 3 5
// 4 5
// output: 0 1 3 4 2 5 6