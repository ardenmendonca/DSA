#include <bits/stdc++.h>

/*
Pick a pivot and place it in its correct place in the sorted array.
Shift smaller elements(i.e. Smaller than the pivot) on the left of the pivot and larger ones to the right.
To summarize, the main intention of this process is to place the pivot, after each recursion call, at its final position, where the pivot should be in the final sorted array.*/

int pivot(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i]<= pivot && i < high){
            i++;
        }
        while (arr[j]> pivot && j >low){
            j--;
        }

        if(i< j){
            swap(arr[i], arr[j]);
        }

    }
    swap(arr[low], arr[j]);
    return j;
}
void quicksort(vector <int> &arr, int low, int high){
    if(low < high){
        int pindex = pivot(arr, low, high);
        quicksort(arr, low, pindex-1);
        quicksort(arr, pindex +1, high); 
    }
}

vector<int> quickSort(vector<int> arr)
{
    quicksort(arr, 0, arr.size()-1);
    return arr;
}

//Time Complexity for the best and average case: O(N*logN)
//Worst Case Time complexity: O(n2) 
