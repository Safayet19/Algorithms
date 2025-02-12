#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[100];
int dist[100];

void dijkstra(int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, source}); // 1st push distance
    dist[source] = 0;

    while (!pq.empty())
    {
        auto parent = pq.top();
        pq.pop();

        int parent_dist = parent.first;
        int parent_node = parent.second;

        for (auto child : adj_list[parent_node])
        {
            int child_node = child.first;
            int child_dist = child.second;

            if (parent_dist + child_dist < dist[child_node])
            {
                dist[child_node] = parent_dist + child_dist;
                pq.push({dist[child_node], child_node});
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
        int a, b, w;
        cin >> a >> b >> w;
        adj_list[a].push_back({b, w});
        adj_list[b].push_back({a, w});
    }
    fill(dist, dist + 100, INT_MAX);
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
   
}
// Time Complexity :
//                 O(V + E) //If we use Normal queue.
//                 O(VlogV + VlogE)//since priority queue
//                 O(logV(V+E)) or O((V+E)logV);

// or we can also  O((E+E)logV)//because E is larger than V
//                 O(ElogV)
