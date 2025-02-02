#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    int adj_mat[nodes][nodes];
    memset(adj_mat, 0 , sizeof(adj_mat));

    //set initial memory all 0

    for(int i = 0; i<nodes; i++)
    {
        for(int k = 0; k<nodes; k++)
        {
        if(i == k)
            adj_mat[i][k] = 1;//main diagonal all 1
        }
    
    }
    for(int i = 0; i<edges; i++)
    {
        int a , b;
        cin>>a>>b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;//for undireted graph
    }
    for(int i = 0; i<nodes; i++)
    {
        for(int k = 0; k<nodes; k++)
        {
            cout<<adj_mat[i][k]<<" ";
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