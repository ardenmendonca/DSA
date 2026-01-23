/*
FORMAL QUESTION (LC 547 - Number of Provinces):
There are n cities. Some of them are connected, while some are not.
If city a is connected directly with city b, and city b is connected directly with city c,
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities, and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the i-th city and the j-th city are
directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

------------------------------------------------------------

What is this problem REALLY?
- This is basically asking how many connected components are there.

What does it look like?
- Input is a matrix, but we can treat it like a graph.

What options do we have?
- BFS or DFS.

Why DFS?
- DFS is simple: it explores one full connected group in one go.

Core idea:
- Loop over all cities.
- When we find an unvisited city, that's a new province.
- Start DFS and mark the whole connected group.
- Each DFS start = 1 province.

Time:  O(n^2)
Space: O(n) for visited + recursion stack (adj list also takes space)
*/

class Solution
{
private:
  void dfs(int node, vector<int> &vis, vector<vector<int>> &adj)
  {
    vis[node] = 1;

    // Visit all connected cities
    for (int nei : adj[node])
    {
      if (!vis[nei])
      {
        dfs(nei, vis, adj);
      }
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size();

    vector<vector<int>> adj(n);

    // Build adjacency list from matrix (avoid duplicates by using j = i+1)
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (isConnected[i][j] == 1)
        {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    vector<int> vis(n, 0);
    int provinces = 0;

    for (int i = 0; i < n; i++)
    {
      // If this city is unvisited, it starts a new province
      if (vis[i] == 0)
      {
        provinces++;
        dfs(i, vis, adj);
      }
    }

    return provinces;
  }
};
