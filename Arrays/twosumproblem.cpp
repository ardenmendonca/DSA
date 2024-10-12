/*
Two Sum : Check if a pair with given sum exists in Array


443

13
Problem Statement: Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

reference - https://www.naukri.com/code360/problems/reading_6845742 */

/*approach one - we will use the HashMap to check if the other element i.e. target-(selected element) exists. 
And for the second variant, we will store the element along will its index in the HashMap. Thus we can easily retrieve the index of the other element i.e. target-(selected element) without iterating the array.

//The steps are as follows:

We will select the element of the array one by one using a loop(say i).
Then we will check if the other required element(i.e. target-arr[i]) exists in the hashMap.
If that element exists, then we will return “YES” for the first variant or we will return the current index i.e. i, and the index of the element found using map i.e. mp[target-arr[i]].
If that element does not exist, then we will just store the current element in the hashMap along with its index. Because in the future, the current element might be a part of our answer.
Finally, if we are out of the loop, that means there is no such pair whose sum is equal to the target. In this case, we will return either 
“NO” or {-1, -1} as per the variant of the question.*/

// code for variant 1
string read(int n, vector<int> book, int target) {
    map<int, int> mpp; // To store elements and their indices.
    
    for (int i = 0; i < n; i++) { // Loop through the array
        int element = book[i]; // Current element
        int remaining = target - element; // Calculate remaining value to reach the target
        
        // Check if the remaining value exists in the map
        if (mpp.find(remaining) != mpp.end()) {
            return "YES"; // If it exists, return "YES" (1st variant)
        }

        // If not, store the current element in the map with its index
        mpp[element] = i;
    }
    
    return "NO"; // If no pair is found, return "NO"
}
// more optimal approach for variant one using pointer approach 

string read(int n, vector<int> book, int sum)
{
    int left=0; int right = n-1;
    sort(book.begin(), book.end());//sort array
    for(int i = 0; i<n ; i++){
        int result = book[left] + book[right];//simple rules if big decrement left pointer
        if (result == sum) return "YES";

        else if (result  > sum) right--;
        else left++;// if small increment 

    }
    return "NO";
}

// code for variant 2
 //optimal approach using map data structure

 vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp; // declare map
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num; // required element
        if (mpp.find(moreNeeded) != mpp.end()) { 
            return {mpp[moreNeeded], i}; // if found return index of both element(moreneeded and i)
        }
        mpp[num] = i; // store the current element in the map for futher iterations
    }
    return { -1, -1};
}

