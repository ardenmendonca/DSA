/*
Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)
reference - https://www.naukri.com/code360/problems/631055

We will use Dutch National Flag algorithm - most optimal solution for this problem.
*/

#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    int low = 0; int mid = 0; int high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            mid++;
            low++;

        }
        else if(arr[mid]==1){
            mid++;

        }
        else{
            swap(arr[high], arr[mid]);
            high--;

        }
    }
    
}
