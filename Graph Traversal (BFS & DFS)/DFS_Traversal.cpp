#include<bits/stdc++.h>
using namespace std;
vector<int>adj_List[1005];
bool visited[1005] = {false};

void dfs(int source)
{
    cout<<source<<" ";
    visited[source] = true;

    for(int child : adj_List[source])
    {
        if(visited[child] == false)
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin>>n>>e;
    while(e--)
    {
        int a , b;
        cin>>a>>b;
        adj_List[a].push_back(b);
        adj_List[b].push_back(a);
    }
    dfs(0);//source 0;
}
//7 7
// 0 2
// 2 4
// 0 1
// 1 5
// 1 3
// 0 3 
// 3 6
// output: 0 2 4 1 5 3 6 
