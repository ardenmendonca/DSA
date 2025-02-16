#include <bits/stdc++.h>
using namespace std;

/*
All Subarrays with Given Sum

Q: Find all subarrays with sum equal to k and count them.

Explanation:
We use a prefix-sum and hashmap approach:
- Maintain a running sum.
- For each element, check if (current_sum - k) exists in the map.
- If it does, add its frequency to the count because that many subarrays ending at the current index have sum k.
*/

int findAllSubarraysWithGivenSum(vector<int> &arr, int k) {
    map<long long, int> freq;
    long long sum = 0;
    int count = 0;
    
    // Initialize frequency for sum = 0.
    freq[0] = 1;
    
    for (int x : arr) {
        sum += x;
        long long rem = sum - k;
        if (freq.find(rem) != freq.end()) {
            count += freq[rem];
        }
        freq[sum]++;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, kVal;
    cin >> n >> kVal;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cout << findAllSubarraysWithGivenSum(arr, kVal) << "\n";
    return 0;
}
