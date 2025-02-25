#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;

    int mat[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                mat[i][j] = 0;
            else
                mat[i][j] = INT_MAX;
        }
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        mat[a][b] = c;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX && mat[i][k] + mat[k][j] < mat[i][j])
                {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// input :
// 4 5
// 0 1 3
// 0 2 6
// 1 2 2
// 1 3 5
// 2 3 4

// output:
// 0 3 5 8 
// INF 0 2 5 
// INF INF 0 4 
// INF INF INF 0 
