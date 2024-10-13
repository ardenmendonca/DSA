/*
Problem statement
You are given an array ‘a’ of ‘n’ integers.



You have to return the lexicographically next to greater permutation.

Note:

If such a sequence is impossible, it must be rearranged in the lowest possible order.


Example:

Input: 'a' = [1, 3, 2]

Output: 2 1 3

references - https://www.naukri.com/code360/problems/next-greater-permutation_6929564

*/

/*

*/

vector<int> nextGreaterPermutation(vector<int> &a) {
    int n = a.size();
    int index = -1;

    for(int i = n-2;i>=1;i--){// iterate from n-2 to start to find big element on lhs and that is break point
      if (a[i] < a[i + 1]) {
        index = i;
        break;
      }
    }
    if (index == -1){//if there is no greater element then elements are sorted, so no permutation and reverse
        reverse(a.begin(), a.end());
        return a;
    }

    for(int i=n-1;i> index;i-- ){//swap smallest element from index i.e just gretaer than index ele coz we need just big permuted no
        if (a[i] > a[index]) {
        swap(a[i], a[index]);
        break;
        }
    }
    reverse(a.begin() + index +1, a.end());//now after swapping smallest number after the index- arrange the element after index a in sorted manner  give just gretter no
    return a;    
    
}