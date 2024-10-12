//Find subarray with sum k only positive element involved
/*
Here we will use pointer approach 
First, we will take two pointers: left and right, initially pointing to the index 0.
The sum is set to a[0] i.e. the first element
Now we will run a while loop until the right pointer crosses the last index i.e. n-1.
Inside the loop, we will do the following operation:
We will use another while loop and it will run until the sum is lesser or equal to k.
Inside this second loop, from the sum, we will subtract the element that is pointed by the left pointer and increase the left pointer by 1.
After this loop gets completed, we will check if the sum is equal to k. If it is, we will compare the length of the current subarray i.e. (right-left+1) with the existing one and consider the maximum one.
Then we will move forward the right pointer by 1. If the right pointer is pointing to a valid index(< n) after the increment, we will add the element i.e. a[right] to the sum.
and then we will return the maximum length.*/

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0;
    int right = 0;
    int n = a.size();
    long long sum = a[0];
    int length = 0;

    for (int i = 0; i< n;i++){
        while(right < n){//right less than boundary
            while(sum > k && left <= right){ // if sum exceeds given value then minus the added element i.e subtract from left
                sum -= a[left];
                left++; // move towards next element

            }
            if (sum ==k){ // find the length of elements resulting in sum k using pointers
                length = max(length, right - left+1);
            }
            right++; // is not big or equal then add i.e small
            sum += a[right];

        }

    }
    return length;
}