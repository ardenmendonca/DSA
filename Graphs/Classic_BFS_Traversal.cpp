/*
FORMAL QUESTION (GFG - BFS traversal of graph):
Given a connected undirected graph. Perform a Breadth First Traversal (starting from vertex 0).
Return a vector containing the BFS traversal of the graph.

------------------------------------------------------------

What is this problem REALLY?
- This is basically asking to print nodes in "level order" from a starting node (0).

What does it look like?
- We are given an adjacency list, so each node already has its neighbors.

What options do we have?
- BFS or DFS.
- BFS is the one that naturally goes level by level.

Why BFS?
- Because BFS explores all neighbors first, then neighbors of neighbors, etc.

Core idea:
- Use a queue.
- Start from node 0.
- Pop a node, add it to answer.
- Push unvisited neighbors.
- IMPORTANT: mark a neighbor visited at the moment you push it,
  so it doesn’t get pushed multiple times by different parents.

Time:  O(V + E)
Space: O(V) for visited + queue
*/

class Solution
{
public:
  vector<int> bfs(vector<vector<int>> &adj)
  {
    int n = adj.size();

    vector<int> vis(n, 0);
    queue<int> q;
    vector<int> ans;

    // Start BFS from node 0
    vis[0] = 1;
    q.push(0);

    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      ans.push_back(node);

      // Push all unvisited neighbors
      for (int nei : adj[node])
      {
        if (vis[nei] == 0)
        {
          vis[nei] = 1; // mark when pushing
          q.push(nei);
        }
      }
    }

    return ans;
  }
};
