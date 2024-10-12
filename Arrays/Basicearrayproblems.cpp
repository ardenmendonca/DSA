// 1. find the largest element in an array

//brute force approach - using recursive approach
#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    int largest = 0;
    for(int i =0;i<n; i++){
        if(arr[i]> largest) largest = arr[i];
    }
    return largest;
    
}

// approach using sort function and returning the last element

int sortArr(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}

// Q.2 Find the second smallest, smallest, second largest and second largest element in an array

/*
Approach:
We have used four variables: small,second_small, large, and second_large.
Variable small and second_small are initialized to INT_MAX while large and second_large are initialized to INT_MIN.

Second Smallest Algo:

1.If the current element is smaller than ‘small’, then we update second_small and small variables
2.Else if the current element is smaller than ‘second_small’ then we update the variable ‘second_small’
3.Once we traverse the entire array, we would find the second smallest element in the variable second_small.
and vice versa for second largest and largest element*/


int secondSmallest(int arr[],int n)
{
    if(n<2)
        return -1;
    int small = INT_MAX;
    int second_small = INT_MAX;
    int i;
    for(i = 0; i < n; i++) 
    {
       if(arr[i] < small)
       {
          second_small = small;
          small = arr[i];
       }
       else if(arr[i] < second_small && arr[i] != small)
       {
          second_small = arr[i];
       }
    }
   return second_small;     
}
int secondLargest(int arr[],int n)
{
	if(n<2)
	return -1;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for (i = 0; i < n; i++) 
    {
        if (arr[i] > large) 
        {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) 
        {
            second_large = arr[i];
        }
    }
    return second_large;                


//Q.3 Check if array is sorted

int isSorted(int n, vector<int> a) {
    
    for(int i=1; i<n;i++){
      if (a[i] < a[i-1]) {
        return false;
          
      }
       
    }return true;
}

// Remove duplicates
/* Take i as 0;
Use a for loop using ‘j’ from 1 to length of the array i.e n.
If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
After completion of the loop return i+1, i.e size of the array (unique elements)*/ 

int removeDuplicates(vector<int> &arr, int n) {
	int i =0;
	for(int j=1; j<n ;j++){
		if (arr[i] != arr[j]){
			i++;
			arr[i] = arr[j];
			

		}
	}
	return (i+1);
}



