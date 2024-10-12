#include<bits/stdc++.h>

void insertionsort(int arr[], int n){
    for(int i=0 ; i<= n-1; i++){
        int j =i;
        while( j >0 && arr[j] < arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
            
        }
    }
}

int
main ()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
	{
	  cin >> arr[i];
	}

  insertionsort(arr, n);
  for (int i = 0; i < n; i++)
	{cout << arr[i]<< " ";}
	
}

// Best case for time complexity is O(n)  worst case is O(n^2)