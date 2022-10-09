# Finding Connected Components

A connected component is a subgraph in which any two vertices are connected to each other 
by paths, and which is connected to no additional vertices in the supergraph. 

So here, 
1. Visit the nodes in a depth-first fashion
1. If the node is not visited, visit that node and its neighbour recursively.

Each time a unvisited node is found, a new component will be found.

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> vis;
int n, m;
vector<vector<int>> adj;
vector<int> components;

int get_comp(int idx)
{
    if (vis[idx])
    {
        return 0;
    }
    vis[idx] = true;
    int ans = 1;

    for (auto i : adj[idx])
    {
        if (!vis[i])
        {
            ans += get_comp(i);
            vis[i] = 1;
        }
    }
    return ans;
}

int main()
{

    cin >> n >> m;

    adj = vector<vector<int>>(n);
    vis = vector<int>(n);

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
            components.push_back(get_comp(i));
        }
    }

    for (auto i : components)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}

```