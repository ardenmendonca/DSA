#include <bits/stdc++.h>
using namespace std;

/*
Set Matrix Row and Column to Zero

Q: Set the entire row and column to zero if an element in the matrix is zero.

Explanation:
1. Check the first row and column to determine if they contain any zeros.
2. Use the first row and column as markers for the rest of the matrix.
3. Update the remaining matrix based on these markers.
4. Finally, update the first row and column if needed.
*/

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    bool firstRowZero = false, firstColZero = false;
    
    // Check the first row for zeros.
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }
    // Check the first column for zeros.
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    
    // Use the rest of the matrix to mark zeros.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // Zero out rows based on markers.
    for (int i = 1; i < n; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < m; j++)
                matrix[i][j] = 0;
        }
    }
    
    // Zero out columns based on markers.
    for (int j = 1; j < m; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 0; i < n; i++)
                matrix[i][j] = 0;
        }
    }
    
    // Zero the first row if needed.
    if (firstRowZero) {
        for (int j = 0; j < m; j++)
            matrix[0][j] = 0;
    }
    // Zero the first column if needed.
    if (firstColZero) {
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }
    
    return matrix;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    
    auto ans = zeroMatrix(mat);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
