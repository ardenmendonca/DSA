//Find subarray with sum k (positive and negative)
//we will use reverse engeneering and pointer method

int getLongestSubarray(vector<int>& nums, int k){
    map<long long , int> checker;
    long long  sum = 0 ;
    int length = 0;

    int n = nums.size();
    for(int i = 0 ; i< n; i++){//iterate
        sum += nums[i];//sum
        if(sum == k){
            length = max(length, i+1);//length of subarray this for first

        }
        long long rem = sum - k;// reverse engineering ....remaining position  
        if(checker.find(rem) != checker.end()){
            int newlength = i - checker[rem];//calculate lenght new sub array
            length = max(newlength, length);
        }

        if(checker.find(sum) == checker.end()){// check if 0 is next ele then skip
            checker[sum] = i;      //initialize pointer to top altest      
        }

    }
    return length;
}
