#include <iostream>
#include <vector>
using namespace std;

vector<int> alternateNumbers(vector<int> &a) {
    vector<int> pos, neg;
    for(int x : a){
        if(x >= 0) pos.push_back(x);
        else neg.push_back(x);
    }
    int i=0, p=0, n=0;
    while(p<(int)pos.size() && n<(int)neg.size()){
        a[i++] = pos[p++];
        a[i++] = neg[n++];
    }
    // Fill remaining positives
    while(p<(int)pos.size()){
        a[i++] = pos[p++];
    }
    // Fill remaining negatives
    while(n<(int)neg.size()){
        a[i++] = neg[n++];
    }
    return a;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    arr = alternateNumbers(arr);
    for(int x : arr) cout << x << " ";
    return 0;
}
