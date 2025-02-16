#include <bits/stdc++.h>
using namespace std;

/*
Superior Elements in Array

Q: Check for a superior element—an element is considered superior (or a "leader") if every element to its right is smaller.

Explanation:
Traverse the array from right to left. Keep track of the maximum value encountered so far.
If the current element is greater than this maximum, it is a superior element.
Collect such elements into the result.
*/

vector<int> superiorElements(vector<int> &arr) {
    int n = arr.size();
    int maxi = INT_MIN;
    vector<int> leaders;
    
    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > maxi) {
            leaders.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    
    // (Optional) Reverse to maintain left-to-right order:
    // reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> ans = superiorElements(arr);
    
    for (int x : ans)
        cout << x << " ";
    return 0;
}
