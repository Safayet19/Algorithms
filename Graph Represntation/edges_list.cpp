#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    vector<pair<int, int>>edge_list;

    while(edges--)
    {
        int a , b;
        cin>>a>>b;
        edge_list.push_back({a, b});
    }
    for(auto i : edge_list)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
// Example: 
// 5 5
// 0 1
// 0 2
// 3 0 
// 1 3
// 3 4
}