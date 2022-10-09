# Graph Traversal

It is important to note two terms:
1. *Visiting a node:* Landing on a node for the first time
1. *Exploring a node:* Exploring all the immediate neighbours of a visited node

<ins>**Breadth First Search:**</ins> So here we start from any node on a graph, then explore all it's 
                        immediate neighbours, and then pick one by one its neighbours and 
                        then explore them and so on.

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    const int N = 1e5;
    int vis[N];

    vector<int> vi(m + 1, 0);
    vector<vector<int>> adj(n + 1, vi);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
    }
    vector<int> ans;
    queue<int> q;
    q.push(1);
    ans.push_back(1);
    int j = 1;
    vis[j] = 1;
    j++;
    while (!q.empty())
    {
        for (int i = 0; i < adj[q.front()].size(); i++)
        {
            if (adj[q.front()][i] && !vis[i])
            {
                ans.push_back(i);
                vis[j] = 1;
                j++;
                q.push(i);
            }
        }
        q.pop();
    }

    cout << "BFS: ";
    vector<int>::iterator it;

    for (it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}

```

<ins>**Depth First Search:**</ins> So here we start from any node on a graph, explore any one of it's 
                        neighbour and then explore any one of it's neighbour and so on. After 
                        that backtrack to previous parent and explore it's other neighbour.

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> ans;

vector<int> dfs(int src, vector<int> adj[], int vis[], int n)
{

    vis[src] = 1;
    // ans.push_back(src);       //preorder printing

    for (int i = 0; i < adj[src].size(); i++)
    {
        int node = adj[src][i];
        if (!vis[node])
        {
            dfs(node, adj, vis, n);
        }
    }

    ans.push_back(src); // postorder printing

    return ans;
}

int main()
{
    const int N = 1e5;
    int vis[N];

    for (int i = 0; i < N; i++)
    {
        vis[i] = 0;
    }

    int n, m;
    cin >> n >> m;

    vector<int> adj[N];

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, adj, vis, n);

    cout << "DFS: ";
    vector<int>::iterator it;

    for (it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
    return 0;
}

```