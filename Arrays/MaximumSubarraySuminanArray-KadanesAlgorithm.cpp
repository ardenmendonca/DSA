/* 
Problem statement - Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and returns its sum and prints the subarray.

Initution - 
-We will solve it using Kadane's Algorithm
-Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.
-If at any point the sum becomes negative we will set the sum to 0 and start the adding process again.
*/

long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum = 0; long maxi= LONG_MIN;int end;
    for(int i =0; i<n; i++){
        
        sum += arr[i]; //adding process

        if(sum > maxi){ // if current sum is greater than maxi than update max as current sum
            maxi = sum; 

        }

        if(sum<0){
            sum =0; // if sum is negative at any point of iteration process then reset it to 0 as we do not consider 0 or negative

        }

        if(maxi <0){
            maxi = 0; // if maxi is also less than 0 than set it to 0
        }
        
    }
    return maxi;
}


