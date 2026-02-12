/*
FORMAL QUESTION (LC 210 - Course Schedule II):
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take
course bi first if you want to take course ai.

Return the ordering of courses you should take to finish all courses.
If there are many valid answers, return any of them.
If it is impossible to finish all courses, return an empty array.

------------------------------------------------------------

What is this problem REALLY?
- This is basically asking for a valid ordering of tasks with dependencies.
- If there’s a cycle, no ordering is possible.

What does it look like?
- Each prerequisite is a directed edge: b -> a.
- That makes it a directed graph.

What options do we have?
- Topological sort (DFS or Kahn’s BFS).

Why DFS topo here?
- DFS is simple: finish all children first, then push the node into a stack.
- The stack order gives a topological ordering.

Core idea:
- Build adjacency list from prerequisites.
- Run DFS from every unvisited node.
- After exploring neighbors, push the node into a stack.
- Pop stack to get the final order.

IMPORTANT NOTE:
- This DFS version MUST also detect cycles (using pathVisited),
  otherwise it can return a wrong order even when a cycle exists.
- We use vis[] + pathVis[] to detect back-edges.

Time:  O(V + E)
Space: O(V + E)
*/

class Solution
{
private:
  bool dfs(int node, vector<int> &vis, vector<int> &pathVis,
           stack<int> &st, vector<vector<int>> &adj)
  {

    vis[node] = 1;
    pathVis[node] = 1;

    for (auto nei : adj[node])
    {
      if (!vis[nei])
      {
        if (dfs(nei, vis, pathVis, st, adj))
          return true; // cycle
      }
      else if (pathVis[nei] == 1)
      {
        return true; // cycle found
      }
    }

    pathVis[node] = 0;
    st.push(node);
    return false;
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    int n = numCourses;

    vector<vector<int>> adj(n);

    // prerequisite [a, b] means: b -> a
    for (int i = 0; i < prerequisites.size(); i++)
    {
      int a = prerequisites[i][0];
      int b = prerequisites[i][1];
      adj[b].push_back(a);
    }

    vector<int> vis(n, 0), pathVis(n, 0);
    stack<int> st;

    // Run DFS topo from every node (graph may be disconnected)
    for (int i = 0; i < n; i++)
    {
      if (vis[i] == 0)
      {
        if (dfs(i, vis, pathVis, st, adj))
        {
          return {}; // cycle -> impossible
        }
      }
    }

    vector<int> ans;
    while (!st.empty())
    {
      ans.push_back(st.top());
      st.pop();
    }

    return ans;
  }
};
