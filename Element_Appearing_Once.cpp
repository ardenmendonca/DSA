#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach 1: Map
int getSingleElementMap(const vector<int> &arr) {
    unordered_map<int,int> freq;
    for(int x : arr) freq[x]++;
    for(auto &p : freq){
        if(p.second == 1) return p.first;
    }
    return -1;
}

// Approach 2: XOR
int getSingleElementXOR(const vector<int> &arr) {
    int x1=0;
    for(int x : arr) x1 ^= x;
    return x1;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Using Map: " << getSingleElementMap(arr) << "\n";
    cout << "Using XOR: " << getSingleElementXOR(arr) << "\n";
    return 0;
}
