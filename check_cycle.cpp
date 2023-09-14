#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, w;

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    int dist[n + 1];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[1] = 0;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge e = v[j];
            int u = e.u;
            int v = e.v;
            int w = e.w;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool cycle = false;
    for (int j = 0; j < v.size(); j++)
    {
        Edge e = v[j];
        int u = e.u;
        int v = e.v;
        int w = e.w;

        if (dist[u] + w < dist[v])
        {
            cycle = true;
            break;
            dist[v] = dist[u] + w;
        }
    }

    if (cycle)
    {
        cout << "Cycle Exist" << endl;
    }
    else
    {

        for (int i = 1; i <= n; i++)
        {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}