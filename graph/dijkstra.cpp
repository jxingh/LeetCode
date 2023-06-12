#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f;

// 邻接矩阵
void Dijkstra(vector<vector<int>> &graph, int source, vector<int> &dist, vector<int> &pre)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        dist[i] = graph[source][i];
        if (dist[i] < INF)
        {
            pre[i] = source;
        }
        else
        {
            pre[i] = -1;
        }
    }
    dist[source] = 0;
    visited[source] = true;
    for (int i = 0; i < n - 1; i++)
    {
        int u = source, minDist = INF;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];
                u = v;
            }
        }
        visited[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                pre[v] = u;
            }
        }
    }
}

void printpath(vector<int> &pre, int source, int target)
{
    int temp = target;
    vector<int> path;
    while (temp != source)
    {
        path.push_back(temp);
        temp = pre[temp];
    }
    cout << source << "->";
    for (int i = path.size() - 1; i > 0; i--)
    {
        cout << path[i] << "->";
    }
    cout << path[0] << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++)
    {
        int u, v, len;
        cin >> u >> v >> len;
        graph[u][v] = len;
    }
    vector<int> dist(n), pre(n);
    Dijkstra(graph, 0, dist, pre);
    for (int i = 1; i < n; i++)
    {
        printpath(pre, 0, i);
        cout << dist[i] << endl;
    }

    return 0;
}
/*
输入：
7 12
0 1 4
0 2 6
0 3 6
1 2 1
1 4 7
2 4 6
2 5 4
3 2 2
3 5 5
4 6 6
5 4 1
5 6 8
*/