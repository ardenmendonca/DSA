#include <bits/stdc++.h>
using namespace std;

/*
Q. remove duplicate in array

Explanation:
Given a sorted array, remove duplicates in-place such that each element appears only once. 
Return the new length of the array after duplicates have been removed.
*/

int removeDuplicates(vector<int> &arr) {
    int n = arr.size();
    if(n == 0) return 0;

    int i = 0; 
    for (int j = 1; j < n; j++) {
        // If the current element differs from the last unique element found,
        // move it forward.
        if (arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }
    // The length of the array without duplicates is (i+1).
    return i + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int newLength = removeDuplicates(arr);

    // Print the unique elements
    for(int i = 0; i < newLength; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
