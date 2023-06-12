#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[25][25];
vector<int> path;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int x, int y)
{
    if (x == n - 1 && y == m - 1)
    {
        for (auto it : path)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && graph[nx][ny] == '.')
        {
            graph[nx][ny] = '#';
            path.push_back(nx * m + ny);
            dfs(nx, ny);
            path.pop_back();
            graph[nx][ny] = '.';
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    path.push_back(0);
    graph[0][0] = '#';
    dfs(0, 0);
    return 0;
}