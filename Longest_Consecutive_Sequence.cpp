#include <bits/stdc++.h>
using namespace std;

/*
Longest Consecutive Sequence

Q: Find the length of the longest consecutive sequence in an unsorted array.

Explanation:
1. Insert all elements into an unordered_set for O(1) lookups.
2. For each element, if (element - 1) is not in the set, it could be the start of a sequence.
3. Count consecutive numbers starting from that element.
4. Keep track of the maximum count found.
*/

int longestSuccessiveElements(vector<int> &a) {
    unordered_set<int> st(a.begin(), a.end());
    int longest = 0;
    
    for (int x : st) {
        // If x-1 is not present, then x might be the start of a sequence.
        if (!st.count(x - 1)) {
            int current = x;
            int count = 1;
            while (st.count(current + 1)) {
                current++;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << longestSuccessiveElements(arr) << "\n";
    return 0;
}
