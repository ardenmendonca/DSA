#include <bits/stdc++.h>
using namespace std;

/*
Spiral Traversal of Matrix

Q: Print the matrix in spiral order.

Explanation:
Traverse the matrix in a spiral manner:
1. Left to Right across the top row.
2. Top to Bottom along the right column.
3. Right to Left across the bottom row.
4. Bottom to Top along the left column.
Adjust the boundaries after each traversal and repeat until all elements are printed.
*/

vector<int> spiralMatrix(vector<vector<int>> &M) {
    int n = M.size();
    int m = M[0].size();
    int top = 0, left = 0, bottom = n - 1, right = m - 1;
    vector<int> ans;
    
    while (left <= right && top <= bottom) {
        // Traverse from left to right.
        for (int j = left; j <= right; j++)
            ans.push_back(M[top][j]);
        top++;
        
        // Traverse from top to bottom.
        for (int i = top; i <= bottom; i++)
            ans.push_back(M[i][right]);
        right--;
        
        // Traverse from right to left if there is a remaining row.
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                ans.push_back(M[bottom][j]);
            bottom--;
        }
        
        // Traverse from bottom to top if there is a remaining column.
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans.push_back(M[i][left]);
            left++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    
    vector<int> result = spiralMatrix(matrix);
    for (int x : result)
        cout << x << " ";
    return 0;
}
