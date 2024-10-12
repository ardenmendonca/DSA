#include<bits/stc++.h>

void bubblesort(int arr[], int n){
    for( int i = n-1; i>=1; i--){
        int min =0;
        int didswap= 0;
        for(int j =0; j< i; j++){
            if (arr[j] > arr[j+1]){
            min = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = min;
            didswap = 1;
            }
            
        }
        if (didswap = 0)
            { break;}
            
    }
}

//the best time complexity is O(n)
