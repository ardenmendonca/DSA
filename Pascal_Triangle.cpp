#include <bits/stdc++.h>
using namespace std;

/*
Pascal Triangle

Q: Generate the first N rows of Pascal's Triangle.

Explanation:
For each row (using 1-based indexing), generate the row using the formula:
  value = previous_value * (row - col) / col
The first element of each row is always 1.
*/

vector<int> generateRow(int row) {
    long long val = 1;
    vector<int> ans;
    ans.push_back(1);
    for (int col = 1; col < row; col++) {
        val = val * (row - col);
        val = val / col;
        ans.push_back((int)val);
    }
    return ans;
}

vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> result;
    for (int i = 1; i <= N; i++) {
        result.push_back(generateRow(i));
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    auto triangle = pascalTriangle(N);
    for (auto &row : triangle) {
        for (auto &val : row)
            cout << val << " ";
        cout << "\n";
    }
    return 0;
}
