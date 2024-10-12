/* Variety 1 ---
Problem Statement - We are given an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

Note: We have to start the array with positive elements.
Example :

Input:
arr[] = {1,2,-4,-5}, N = 4
Output:
1 -4 2 -5
reference - https://www.naukri.com/code360/problems/alternate-numbers_6783445

*/


  vector<int> RearrangebySign(vector<int>A){
    
  int n = A.size();
  
  // Define array for storing the ans separately.
  vector<int> ans(n,0);
  
  // positive elements start from 0 and negative from 1.
  int posIndex = 0, negIndex = 1;
  for(int i = 0;i<n;i++){
      
      // Fill negative elements in odd indices and inc by 2.
      if(A[i]<0){
          ans[negIndex] = A[i];
          negIndex+=2;
      }
      
      // Fill positive elements in even indices and inc by 2.
      else{
          ans[posIndex] = A[i];
          posIndex+=2;
      }
  }
  
  return ans;
    
}

/*
Variety 2---
There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.

Note: Start the array with positive elements.
 
Example:

Input:
arr[] = {1,2,-4,-5,3,4}, N = 6
Output:
1 -4 2 -5 3 4

*/

vector<int> alternateNumbers(vector<int>&a) {
    // Define 2 vectors, one for storing positive 
    // and other for negative elements of the array.
    vector<int> pos;
    vector<int> neg;
    int n = a.size();
    for(int i = 0; i<n;i++){
        //if positive fill in "pos" named array
        if(a[i]>0) {
            pos.push_back(a[i]);
        }
        // if negative fill in "neg" named array
        else{
            neg.push_back(a[i]);
        }  
        
        }
        //once this process is done we will get two seperate arrays filled with positive and negative element respectively

        //if positive element is more than negative element
        if(pos.size()> neg.size()){ 
            for(int i =0;i< neg.size();i++){
                // First, fill array alternatively till the point 
                // where positives and negatives ar equal in number.
                a[i*2] = pos[i];
                a[i*2+1] = neg[i];
            }
            //fill the remaining element at the end of array (here for positive)
            int index = neg.size()*2;
            for (int i = neg.size(); i < pos.size(); i++) {
                a[index] = pos[i];
                index++;
            }
        }

        else {
            //similar process if negative element are more than positive element
            for(int i =0;i< pos.size();i++){
                a[i*2] = pos[i];
                a[i*2+1] = neg[i];
            }
            //fill negative elements at the end of array
            int index = pos.size()*2;
            for (int i = pos.size(); i < neg.size(); i++) {
                a[index] = neg[i];
                index++;
            }
        }
        return a;
}
