#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &v) {
    int count=0, element=0;
    for(int x : v){
        if(count==0){
            element = x;
            count=1;
        }
        else if(x == element){
            count++;
        }
        else {
            count--;
        }
    }
    return element;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << majorityElement(arr) << endl;
    return 0;
}
