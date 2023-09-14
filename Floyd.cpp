#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7;

int main()
{
    int n, e;
    cin >> n >> e;
    int dist[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
            if (i == j)
                dist[i][j] = 0;
        }
    }

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "UPDATED" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else if (i == j)
            {
                if (dist[i][j] != 0)
                {
                    cout << "Negative cycle detected!"
                         << " ";
                    cout << dist[i][j] << " ";
                }
                cout << dist[i][j] << " ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}