#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedUnion(vector<int> &a, vector<int> &b) {
    int i=0, j=0;
    vector<int> ans;
    while(i < (int)a.size() && j < (int)b.size()){
        if(a[i] < b[j]){
            if(ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
            i++;
        }
        else if(a[i] > b[j]){
            if(ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
            j++;
        }
        else {
            if(ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
            i++; j++;
        }
    }
    while(i < (int)a.size()){
        if(ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
        i++;
    }
    while(j < (int)b.size()){
        if(ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
        j++;
    }
    return ans;
}

int main(){
    int n,m; cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for(int i=0; i<n; i++) cin >> arr1[i];
    for(int j=0; j<m; j++) cin >> arr2[j];
    vector<int> uni = sortedUnion(arr1, arr2);
    for(int x : uni) cout << x << " ";
    return 0;
}
