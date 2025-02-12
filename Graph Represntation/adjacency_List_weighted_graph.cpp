#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    vector<pair<int, int>> adj_List[nodes];
    while(edges--)
    {
        int v1, v2, w;
        cin>>v1>>v2>>w;

        adj_List[v1].push_back({v2,w});
        adj_List[v2].push_back({v1,w});

    }
    
    for(int i = 0; i<nodes; i++)
    {
        cout<<i<<"-->";
        for(auto j : adj_List[i])
        {
            cout<<j.first<<" "<<j.second<<",";
        }
        cout<<endl;
    }
}