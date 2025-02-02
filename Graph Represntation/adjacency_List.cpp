#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

   vector<int> adj_list[nodes];

   while(edges--)
   {
    int a , b;
    cin>>a>>b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
   }
   for(int i = 0; i<nodes; i++)
   {
    cout<<i<<"->";
    for(auto k : adj_list[i])
    {
        cout<<k<<" ";
    }
    cout<<endl;
   }
// Example: 
// 5 5
// 0 1
// 0 2
// 3 0 
// 1 3
// 3 4
}