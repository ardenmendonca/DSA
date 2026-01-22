/*
===========================================================
Problem: Number of Islands
LeetCode Link: https://leetcode.com/problems/number-of-islands/

Approach: DFS (Depth First Search)
Time Complexity: O(N * M)
Space Complexity: O(N * M)  (Recursion stack in worst case)

===========================================================

PROBLEM STATEMENT:
You are given a 2D grid where:
- '1' represents land
- '0' represents water

An island is formed by connecting adjacent lands horizontally or vertically.
You need to count how many islands are present in the grid.

===========================================================

INTUITION (IN SIMPLE WORDS):

We can think of the grid as a graph:
- Each cell is a node
- Each land cell ('1') is connected to its neighboring land cells (up, down, left, right)

Now the problem becomes:
"How many connected components of land are there?"

-----------------------------------------------------------
Which approach should we use? DFS or BFS?

Both DFS and BFS are VALID here.

But:
- DFS is simpler to write using recursion
- DFS naturally explores one island completely before moving to the next

So the idea is:
1. Traverse the grid
2. Whenever you find an unvisited land cell ('1'):
   - This means we found a NEW island
   - Increase the island count
   - Run DFS from this cell to mark the entire island as visited

Why not count every '1' directly?
Because multiple '1's can belong to the SAME island.

So we must:
- Count only when we START exploring a new island
- And mark the entire island as visited so we don’t count it again

-----------------------------------------------------------
Why DFS works well here?

DFS:
- Goes deep and explores the full connected region (entire island)
- Marks all connected land cells as visited
- Ensures each island is counted only once

===========================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int n, m;

  // Direction arrays for moving up, down, left, right
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};

  // DFS to visit the entire island starting from (r, c)
  void dfs(int r, int c, vector<vector<char>> &grid)
  {
    // Mark current cell as visited by changing it to '0'
    grid[r][c] = '0';

    // Explore all 4 directions
    for (int k = 0; k < 4; k++)
    {
      int nr = r + dr[k];
      int nc = c + dc[k];

      // Check boundaries and if it's unvisited land
      if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == '1')
      {
        dfs(nr, nc, grid);
      }
    }
  }

  int numIslands(vector<vector<char>> &grid)
  {
    n = grid.size();
    m = grid[0].size();

    int islands = 0;

    // Traverse the entire grid
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {

        // If we find an unvisited land cell, it's a new island
        if (grid[i][j] == '1')
        {
          islands++;       // Count new island
          dfs(i, j, grid); // Visit and mark the entire island
        }
      }
    }

    return islands;
  }
};

/*
===========================================================
EXAMPLE:

Input:
grid =
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1

Output:
3

Explanation:
- First island at top-left
- Second island in the middle
- Third island at bottom-right

===========================================================
SUMMARY:

- We treat the grid as a graph
- Each DFS call explores one full island
- We count how many times we START a DFS
- That number = number of islands

===========================================================
*/
