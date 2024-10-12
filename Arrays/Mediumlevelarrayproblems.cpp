//Q. Rotate array by d places // brute force simple is use reverse.

Q. Rotate array by d places // brute force simple is use reverse.

vector<int> rotateArray(vector<int>arr, int d) {
    
    int n = arr.size();
    d = d % n;// if rotated by size of array then same
    int temp[d];

    for (int i = 0; i<d; i++){// to extract the initial d element
        temp[i] = arr[i]; 

    }

    for(int i = d; i<n;i++){// shift the element after d to start i.e left 
        arr[i -d] = arr[i];
    }

    for (int i = n-d; i<n; i++){// put extracted element after the shifted
        arr[i] = temp[i - (n-d)];
    }
    return arr;
}

// Time complexity is O(2*n), where n = size of the array


//Q.2 Move zeros to the end of array

vector<int> moveZeros(int n, vector<int> a) {
    int j =-1;
    for(int i =0; i<n;i++){
      if (a[i] == 0) {
        j = i;// find zero ka position
        break;
      }
    }

    if( j == -1) return a;

    for(int i = j+1; i<n; i++){
        if (a[i] != 0){// if the next element is not zero then swap that element with zero and continue this iterative process
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;


}

//Q.3 We have given two sorted arrays, ‘a’ and ‘b’, of size ‘n’ and ‘m’, respectively, return the union of the arrays.


//solution 1 using set -(as it does not hold duplicate elements)

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  set < int > s;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    s.insert(arr1[i]);
  for (int i = 0; i < m; i++)
    s.insert(arr2[i]);
  for (auto & it: s)
    Union.push_back(it);
  return Union;
}

//solution 2 - using two pointer approach. The above solution works for unordered arrays but since our given are sorted we can use this to property to reduce the time complexity from  O((m+n)log(m+n))  TO  O(m+n) as two For loops are used in solution 1 and in this solution only one iteration is done using while

// 1.Here ther's two pointer i,j pointing to the 0th index of arr1 and arr2
// 2.Create an empty vector for storing the union of arr1 and arr2.
/* 3. There would be three cases, 1) where element in both array are equal then enter one from either of array and increment both the pointers
case 2 - arr1[ i ] < arr2[ j ] so we need to insert arr1[ i ] in union.IF last element in  union vector is not equal to arr1[ i ],then insert in union else don’t insert. After checking Increment i.
case 3 arr1[ i ] > arr2[ j ] so we need to insert arr2[ j ] in union. IF the last element in the union vector is not equal to arr2[ j ], then insert in the union, else don’t insert. After checking Increment j.*/
//4. After traversing if any elements are left in arr1 or arr2 check for condition and insert in the union.

vector < int > sortedArray(vector < int > a, vector < int > b) {
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;int j =0;// pointers

    vector<int> result; // union vector

    while(i <n1 && j < n2){
        if(a[i] <= b[j]){ //case 1 and 2
          if ( result.size() == 0 || result.back() != a[i] ) {
            result.push_back(a[i]);
          }
          i++;
        } else { //case 3
          if ( result.size() == 0  || result.back() != b[j]) {
            result.push_back(b[j]);
          }
          j++;
        }
        }

        while(i< n1){ //If any element left in arr1
            if(result.size() == 0 || result.back() != a[i]){
                result.push_back(a[i]);
                
        }i++;

    }
        while(j< n2){ // If any element left in arr2
        if (result.size() == 0  || result.back() != b[j]) {
                result.push_back(b[j]);
        }
        j++;
        }

    return result;
}

//Q.3 Q. intersection of two array


vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int i = 0;
    int j =0;
    vector <int> result;
    while(i < n && j <m){
        if(arr1[i] < arr2[j]){ // if other element is greater then ++ kyuki niche agar bada hai matlab badte rahega age chota nhi milega
            i++;
        }

        else if (arr2[j]< arr1[i]){
            j++;
        }

        else{
            if( arr1[i] == arr2[j]) // agar same toh include aur dono bado
            result.push_back(arr1[i]);
            i++;
            j++;

        }
        
    }
    return result;
}


//Q. find intersetion of two sorted arrays. ps - intersection in this case means common elements in these array

/* Now we can use brute force aproach  i.e we run a for loop to check if each element in array 1 is present in array 2 by comparing the elements but this would result in high time complexity
- Solution  A better approach would be to use pointers, which would be optimal approach i.e give good time complexity.
working - We initiate 2 pointers i and j. i=0 and will iterate over Array A, j=0 and will iterate over Array B. */


vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int i = 0;
    int j =0;
    vector <int> result;
    while(i < n && j <m){
        if(arr1[i] < arr2[j]){ // if other element is greater then ++ kyuki niche agar bada hai matlab badte rahega age chota nhi milega
            i++;
        }

        else if (arr2[j]< arr1[i]){
            j++;
        }

        else{
            if( arr1[i] == arr2[j]) // agar same toh include aur dono bado
            result.push_back(arr1[i]);
            i++;
            j++;

        }
        
    }
    return result;
}

/*
Time Complexity: O(n).Since the elements are compared within the single pass for both the arrays this approach would take a linear time.

Space Complexity: O(1) There is no extra space used in this approach*/

Q.