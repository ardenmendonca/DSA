#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long maxSubarraySum(vector<int> &arr) {
    long long currentSum=0, maxSum=LLONG_MIN;
    for(int x : arr){
        currentSum += x;
        if(currentSum > maxSum) maxSum = currentSum;
        if(currentSum < 0) currentSum=0;
    }
    return maxSum;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << maxSubarraySum(arr) << endl;
    return 0;
}
