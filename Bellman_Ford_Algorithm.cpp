#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int v1, v2, cost;
    Edge(int v1, int v2, int cost)
    {
        this->v1 = v1;
        this->v2 = v2;
        this->cost = cost;
    }
};

int n, e;
vector<Edge> edge_list;
int dist[1000];

void bellman_ford()
{
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto i : edge_list)
        {
            int v1 = i.v1;
            int v2 = i.v2;
            int cost = i.cost;

            if (dist[v1] != INT_MAX && dist[v1] + cost < dist[v2])
            {
                dist[v2] = dist[v1] + cost;
            }
        }
    }

    // Negative Cycle Detection
    for (auto i : edge_list)
    {
        int v1 = i.v1;
        int v2 = i.v2;
        int cost = i.cost;

        if (dist[v1] != INT_MAX && dist[v1] + cost < dist[v2])
        {
            cout << "Negative Weighted Cycle Detected" << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << dist[i] << " " << endl;
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        edge_list.push_back(Edge(v1, v2, cost));
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    bellman_ford();
}

// Example no negative cycle:
// 4 4
// 0 2 5
// 0 3 12
// 2 1 2
// 1 3 3

// output:
// 0->0
// 1->7
// 2->5
// 3->10

// Example negative cycle:
// 4 4
// 0 1 5
// 1 2 3
// 2 3 2
// 3 1 -6
