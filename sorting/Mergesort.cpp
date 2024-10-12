// Problem:  Given an array of size n, sort the array using Merge Sort.
/* Example 1:
Input: N=5, arr[]={4,2,1,6,7}
Output: 1,2,4,6,7,


Example 2:
Input: N=7,arr[]={3,2,8,5,1,4,23}
Output: 1,2,3,4,5,8,23 */

/* Merge Sort is a divide-and-conquer algorithm that splits the input array into equal halves and then combines the two sorted halves. In this code it relies on two key functions:

1. merge(): This function merges two sorted halves of the array. It assumes that both parts are already sorted and combines them into a single sorted array.

2. mergeSort(): This function recursively divides the array into two sections: one from the start (low) to the midpoint (mid), and the other from the midpoint plus one (mid+1) to the end (high), where:
   low is the leftmost index of the array,
   high is the rightmost index of the array,
   mid` is the middle index of the array.
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
      }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

//Time complexity is O(nlogn) 
// Space complexity is O(n)  