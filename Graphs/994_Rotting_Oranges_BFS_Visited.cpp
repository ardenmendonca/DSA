/*
FORMAL QUESTION (LC 994 - Rotting Oranges):
You are given an m x n grid where:
- 0 represents an empty cell,
- 1 represents a fresh orange,
- 2 represents a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1.

------------------------------------------------------------

What is this problem REALLY?
- This is basically a shortest-time / level-order spread problem.
- Rotten oranges spread like a wave, one “layer” per minute.

What does it look like?
- It’s a grid, but we can think of it like a graph:
  each cell connects to its 4 neighbors.

What options do we have?
- BFS is best because BFS naturally moves level by level (minute by minute).

Why BFS?
- Because each BFS level represents 1 minute of rotting.

Core idea:
- Count all fresh oranges.
- Push all initially rotten oranges into the queue.
- Run BFS in levels:
  each level = 1 minute.
- When a rotten orange reaches a fresh one, we mark it as "now rotted/queued" using a visited array.
- Decrease fresh count each time we rot one.
- If fresh becomes 0, we return time. Otherwise return -1.

IMPORTANT DETAIL:
- We mark a cell visited at the moment we push it into the queue,
  so it doesn’t get pushed multiple times.

Time:  O(R * C)
Space: O(R * C) for visited + queue
*/

class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int fresh = 0;

    // Count fresh + push initial rotten oranges
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1)
          fresh++;

        if (grid[i][j] == 2)
        {
          q.push({i, j});
          vis[i][j] = 1; // already rotten / already in queue
        }
      }
    }

    int time = 0;

    // BFS level by level (each level = 1 minute)
    while (fresh > 0 && !q.empty())
    {
      int sz = q.size();

      while (sz--)
      {
        auto cur = q.front();
        q.pop();

        int r = cur.first;
        int c = cur.second;

        for (int d = 0; d < 4; d++)
        {
          int nr = r + direction[d][0];
          int nc = c + direction[d][1];

          // Fresh orange + not already processed
          if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
              grid[nr][nc] == 1 && vis[nr][nc] == 0)
          {

            vis[nr][nc] = 1; // mark as now rotten/queued
            q.push({nr, nc});
            fresh--;
          }
        }
      }

      time++; // finished one full minute of spreading
    }

    return (fresh == 0) ? time : -1;
  }
};
