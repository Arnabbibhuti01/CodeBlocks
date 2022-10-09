# Cycle Detection in Graphs


<ins>**Cycle Detection in Undirected Graphs:**</ins> 
Keep on traversing the graph. If you found an edge pointing to an already visited node(except the
parent node), a cycle is found.

In other words, if there is a Back-Edge in a DFS Spanning tree, then we have a cycle in the graph.

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<int> &vis, int parent)
{
    vis[src] = 1;
    for (auto i : adj[src])
    {
        if (i != parent)
        {
            if (vis[i])
            {
                return true;
            }
            if (!vis[i] && isCycle(i, adj, vis, src))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle = false;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && isCycle(i, adj, vis, -1))
        {
            cycle = true;
        }
    }

    if (cycle)
    {
        cout << "Cycle is Present" << endl;
    }
    else
    {
        cout << "Cycle is Absent" << endl;
    }

    return 0;
}

```

<ins>**Cycle Detection in Directed Graphs:**</ins> 
1. Mark Current node as visited and also mark the index in recursion stack.
1. Find all the vertices which are not visited and are adjacent to the current node.
1. If the adjacent vertices are already marked in the recursion stack then a cycle is found.

```cpp

#include <iostream>
#include <vector>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<int> &vis, vector<int> &stack)
{
    stack[src] = 1;
    if (!vis[src])
    {
        vis[src] = true;
        for (auto i : adj[src])
        {
            if (stack[i])
            {
                return true;
            }
            if (!vis[i] && isCycle(i, adj, vis, stack))
            {
                return true;
            }
        }
    }
    stack[src] = false;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }
    bool cycle = false;

    vector<int> stack(n, 0);
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && isCycle(i, adj, vis, stack))
        {
            cycle = true;
        }
    }

    if (cycle)
    {
        cout << "Cycle is Present" << endl;
    }
    else
    {
        cout << "Cycle is Absent" << endl;
    }

    return 0;
}

```