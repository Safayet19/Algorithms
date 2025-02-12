#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj_List[100];

int dis[100] = {INT_MAX};
void dijkstra(int source)
{
    queue<pair<int,int>>q;//make pair with weight
    q.push({source, 0});//node and weight
    dis[source] = 0;
    

    while(!q.empty())
    {
        //step1: ber kore ana
        auto parent = q.front();
        q.pop();

        //step2: oi node k niye kaj kora
        int parent_node = parent.first;
        int parent_dist = parent.second;

        //step3: childen push kora
        for(auto child : adj_List[parent_node])
        {
            int child_node = child.first;
            int child_dist = child.second;

            //step4: path relaxation before children push
            if(parent_dist + child_dist<dis[child_node])
            {
                dis[child_node] = parent_dist +child_dist;
                q.push({child_node, dis[child_node]});

            }
        }
    }
}
int main()
{
  int n , e;
  cin>>n>>e;

  while(e--)
  {
    int a , b , w;
    cin>>a>>b>>w;

    adj_List[a].push_back({b,w});
    adj_List[b].push_back({a,w});
  }
  fill(dis,dis+100,INT_MAX);//all makes infinite ditance
  
  dijkstra(0);
  for(int i = 0; i<n; i++)
  {
    cout<<dis[i]<<" ";
  }

  
}
//Example:
// 5 8 
// 0 1 10
// 1 2 1
// 0 2 7
// 0 3 4
// 2 3 1
// 3 4 5
// 1 4 3
// 2 4 5
// Output : 