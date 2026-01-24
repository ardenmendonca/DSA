/*
FORMAL QUESTION (LC 200 - Number of Islands):
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

------------------------------------------------------------

What is this problem REALLY?
- This is basically asking: how many connected components of '1's exist in the grid.

What does it look like?
- It’s a grid, but we can think of it as a graph:
  each land cell is a node, and it connects to its 4-direction neighbors.

What options do we have?
- DFS or BFS.

Why DFS?
- DFS is simple here because it lets us fully explore one island in one go.

Core idea:
- Loop through every cell.
- When we see a land cell ('1') that is not visited, that means we found a new island.
- Start DFS from it and mark the whole island visited using a visited array.
- Each DFS start = 1 island.

Time:  O(R * C)
Space: O(R * C) for visited + recursion stack in worst case
*/

class Solution
{
  int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

private:
  void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<int>> &vis)
  {
    vis[r][c] = 1;

    // Explore 4 directions (down, up, right, left)
    for (int i = 0; i < 4; i++)
    {
      int nr = r + direction[i][0];
      int nc = c + direction[i][1];

      // If inside grid, is land, and not visited -> continue DFS
      if (nr >= 0 && nc >= 0 &&
          nr < grid.size() && nc < grid[0].size() &&
          grid[nr][nc] == '1' && vis[nr][nc] == 0)
      {

        dfs(nr, nc, grid, vis);
      }
    }
  }

public:
  int numIslands(vector<vector<char>> &grid)
  {
    int R = grid.size();
    int C = grid[0].size();

    vector<vector<int>> vis(R, vector<int>(C, 0));
    int count = 0;

    for (int i = 0; i < R; i++)
    {
      for (int j = 0; j < C; j++)
      {
        // If this cell is land and not visited, it's a new island
        if (grid[i][j] == '1' && vis[i][j] == 0)
        {
          dfs(i, j, grid, vis);
          count++;
        }
      }
    }

    return count;
  }
};
