#include <iostream>
#include <vector>
using namespace std;

vector<int> moveZeros(vector<int> &arr) {
    int n = arr.size();
    // Find first zero
    int j=-1;
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    if(j==-1) return arr; // no zero found

    for(int i=j+1; i<n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return arr;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> ans = moveZeros(arr);
    for(int x : ans) cout << x << " ";
    return 0;
}
