# Bipartite Graph

- Its vertices can be divided into two disjoint and independent sets U and V such that every 
edge connects a vertex in U to one in V.

    OR

- The graph does not contain any odd length cycles

    OR

- The graph is two-colorable (i.e. traverse the graph, and if current node is red coloured then paint
it's neighbours as blue. If graph is successfully coloured in blue and red, then it is two-colorable)

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;
vector<int> col;

bool isBipartite;

void color(int u, int curr)
{
    if (col[u] != -1 && col[u] != curr)
    {
        isBipartite = false;
        return;
    }

    col[u] = curr;
    if (vis[u])
    {
        return;
    }
    vis[u] = true;

    for (auto i : adj[u])
    {
        color(i, curr ^ 1);
    }
}

int main()
{

    isBipartite = true;

    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n);
    vis = vector<int>(n, 0);
    col = vector<int>(n, -1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            color(i, 0);
        }
    }

    if (isBipartite)
    {
        cout << "Graph is Bipartite" << endl;
    }
    else
    {
        cout << "Graph is not Bipartite" << endl;
    }

    return 0;
}

```