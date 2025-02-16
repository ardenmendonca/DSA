#include <iostream>
#include <vector>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, vector<int> &arr2) {
    int i=0, j=0;
    vector<int> ans;
    while(i<(int)arr1.size() && j<(int)arr2.size()){
        if(arr1[i] < arr2[j]) i++;
        else if(arr1[i] > arr2[j]) j++;
        else {
            ans.push_back(arr1[i]);
            i++; j++;
        }
    }
    return ans;
}

int main(){
    int n,m; cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for(int i=0; i<n; i++) cin >> arr1[i];
    for(int j=0; j<m; j++) cin >> arr2[j];
    vector<int> inter = findArrayIntersection(arr1, arr2);
    for(int x : inter) cout << x << " ";
    return 0;
}
