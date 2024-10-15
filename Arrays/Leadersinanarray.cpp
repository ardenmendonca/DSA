/*
Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

reference - https://www.naukri.com/code360/problems/superior-elements_6783446
*/


//Brute force approach



#include<bits/stdc++.h>
using namespace std;

vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);

  }
  
  return ans;
}

// optimal approach

#include<bits/stdc++.h>
vector<int> superiorElements(vector<int>&arr) {
    int n = arr.size();
    int maxi = INT_MIN;
    vector<int> leader;

    for(int i = n-1;i>=0;i--){
      //Start checking from the end whether a number is greater, if so add it in the array 
      if (arr[i] > maxi) {
        maxi = arr[i];
        leader.push_back(arr[i]);
      }
      

    }
    return leader;
}
