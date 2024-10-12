// Find the number that appears once, and the other numbers twice
/*
Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.
 Solution 1 - Hashing using the map data structure: 
Approach will be the same as the array hashing. The only difference here is we will use the map data structure for hashing instead of using another array for hashing.

Approach 1:

First, we will declare a map.
Now, using a loop we will store the elements of the array along with their frequency in the map data structure.
Using another loop we will iterate over the map, and try to find the element for which the frequency is 1, and finally, we will return that particular element.
*/

int getSingleElement(vector<int> &arr){
    int n = arr.size();
    map<int, int>mpp; // declare hash map 
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second == 1){ //
            return it.first;
        }
    }
}

/*
Approachc 2.(Using XOR): Most optimal
Intuition:
Two important properties of XOR are :

1.XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
2.XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2*/

int getSingleElement(vector<int> &arr){
    int n = arr.size();
    int x1 = 0;
    for(int i =0; i<n ; i++){
        x1 = x1^ arr[i]; // XOR all the elements:
    }
    return x1;
}
// Time Complexity: O(N), where N = size of the array. Best coz iterating only once through the array 
