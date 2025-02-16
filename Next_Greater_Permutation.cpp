#include <bits/stdc++.h>
using namespace std;

/*
Next Greater Permutation

Q: To give permutation of number just greater than the given number.

Explanation:
Generate the next lexicographically greater permutation of the given array of numbers.
If no greater permutation is possible (i.e., the array is in descending order), return the lowest permutation (ascending order).

Algorithm:
1. Traverse the array from right to left to find the first index 'index' such that a[index] < a[index+1].
   - If no such index exists, the array is in descending order, so reverse it.
2. Otherwise, traverse from the right to find the first element greater than a[index] and swap them.
3. Finally, reverse the subarray after index to obtain the next permutation.
*/

vector<int> nextGreaterPermutation(vector<int> &a) {
    int n = a.size();
    int index = -1;
    
    // Find the break point from right where a[i] < a[i+1]
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            index = i;
            break;
        }
    }
    
    // If no break point is found, the array is in descending order.
    if (index == -1) {
        reverse(a.begin(), a.end());
        return a;
    }
    
    // Find the first element from the right that is greater than a[index] and swap them.
    for (int i = n - 1; i > index; i--) {
        if (a[i] > a[index]) {
            swap(a[i], a[index]);
            break;
        }
    }
    
    // Reverse the subarray after index.
    reverse(a.begin() + index + 1, a.end());
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    arr = nextGreaterPermutation(arr);
    
    for (int x : arr)
        cout << x << " ";
    return 0;
}
