#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int n , vector<int> &v){
    int min_idx;

    for(int i = 0 ; i < n - 1 ; i++){
        min_idx = i;
        for(int j = i + 1 ; j < n ; j++){
            if(v[j] < v[min_idx]){
                min_idx = j;
            }
        }
        swap(v[min_idx] , v[i]);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ;  i++) cin >> v[i];
    SelectionSort(n , v);
    for(int i = 0 ; i < n ; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}