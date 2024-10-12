/*
Problem statement
You are given an array 'a' of 'n' integers.
A majority element in the array ‘a’ is an element that appears more than 'n' / 2 times.

Find the majority element of the array.

It is guaranteed that the array 'a' always has a majority element.

Example:
Input: ‘n’ = 9, ‘a’ = [2, 2, 1, 3, 1, 1, 3, 1, 1]

Output: 1

Explanation: The frequency of ‘1’ is 5, which is greater than 9 / 2.
Hence ‘1’ is the majority element.

reference - https://www.naukri.com/code360/problems/majority-element_6783241
*/

//We will use Moore's Voting Algorithm--works srtictly only if majority element present which is true in our case.

int majorityElement(vector<int> v) {
	int count = 0; int element;
	for(int i =0;i< v.size();i++){
		if(count == 0){
			element = v[i]; // set the variable as assumed answer 
			count=1;
		}
		else if(v[i]== element){ // if set variable is found again then increment
			count++;
		}
		else{
			count--; // if present element is not same as set element then decrement
		}
	}
	return element; // will return the majority element
}