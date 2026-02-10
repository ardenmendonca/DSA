/*
FORMAL QUESTION (LC 207 - Course Schedule):
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you
must take course bi first if you want to take course ai.

Return true if you can finish all courses. Otherwise, return false.

------------------------------------------------------------

What is this problem REALLY?
- This is basically asking: does this directed graph have a cycle?
- If there is a cycle, you can’t finish all courses.

What does it look like?
- Each course is a node.
- A prerequisite [a, b] means: b -> a (b must happen before a).

What options do we have?
- DFS cycle detection (pathVisited)
- Kahn’s Algorithm (BFS Topological Sort using indegree)

Why Kahn’s?
- Because it’s clean: keep taking courses with indegree 0.
- If we can take all courses, no cycle exists.

Core idea:
- Build graph edges b -> a.
- Compute indegree for each node.
- Push all nodes with indegree 0 into queue.
- Pop nodes, reduce indegree of neighbors.
- Count how many nodes we processed.
- If processed == numCourses => possible, else cycle exists.

Time:  O(V + E)
Space: O(V + E)
*/

class Solution
{
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    int n = numCourses;

    vector<vector<int>> adj(n);
    for (int i = 0; i < prerequisites.size(); i++)
    {
      int pre = prerequisites[i][1];    // bi
      int course = prerequisites[i][0]; // ai
      adj[pre].push_back(course);       // bi -> ai
    }

    vector<int> indegree(n, 0);
    for (int k = 0; k < n; k++)
    {
      for (int nxt : adj[k])
      {
        indegree[nxt]++;
      }
    }

    queue<int> q;
    for (int j = 0; j < n; j++)
    {
      if (indegree[j] == 0)
      {
        q.push(j);
      }
    }

    int processed = 0;

    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      processed++;

      for (int nxt : adj[node])
      {
        indegree[nxt]--;
        if (indegree[nxt] == 0)
        {
          q.push(nxt);
        }
      }
    }

    return processed == numCourses;
  }
};
