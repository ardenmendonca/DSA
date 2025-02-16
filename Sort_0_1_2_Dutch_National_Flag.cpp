#include <bits/stdc++.h>
using namespace std;

/*
Next_Greater_Permutation

Q. to give permutation of number just greater than no.

Explanation:
Generates the next lexicographically greater permutation of the given array of numbers.
If no greater permutation is possible (e.g., the array is in descending order), 
it returns the lowest permutation (ascending order).

Algorithm Steps:
1. Find the "break point" from the right (call it 'index') where arr[index] < arr[index + 1].
   - If no such index is found, the entire array is in descending order, so reverse it.
2. Otherwise, from the right end, find the first element that is greater than arr[index], swap them.
3. Finally, reverse the part of the array after 'index' to get the next permutation.
*/

vector<int> nextGreaterPermutation(vector<int> &a) {
    int n = a.size();
    int index = -1;
    
    // 1) Find break point (index) from the right
    for(int i = n - 2; i >= 0; i--){
        if(a[i] < a[i + 1]){
            index = i;
            break;
        }
    }

    // If index == -1, then array is in descending order
    if(index == -1){
        reverse(a.begin(), a.end());
        return a;
    }

    // 2) Find the first element from the right that is greater than a[index]
    for(int i = n - 1; i > index; i--){
        if(a[i] > a[index]){
            swap(a[i], a[index]);
            break;
        }
    }

    // 3) Reverse everything after 'index'
    reverse(a.begin() + index + 1, a.end());
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    arr = nextGreaterPermutation(arr);

    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}
