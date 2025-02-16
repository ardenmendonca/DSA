#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateArray(vector<int> arr, int d) {
    int n = arr.size();
    d = d % n;
    vector<int> temp(arr.begin(), arr.begin() + d);
    for(int i = d; i < n; i++){
        arr[i - d] = arr[i];
    }
    for(int i = 0; i < d; i++){
        arr[n - d + i] = temp[i];
    }
    return arr;
}

int main(){
    int n,d; cin >> n >> d;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> rotated = rotateArray(arr,d);
    for(int x : rotated) cout << x << " ";
    return 0;
}
