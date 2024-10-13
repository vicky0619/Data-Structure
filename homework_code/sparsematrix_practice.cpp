#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    int m,n;
    cin >> m >> n;
    int sum=1;
    int arr[m];
    for(int i=0;i<m;i++){
        arr[m]=0;
    }
    while(k--){
        int r,c;
        cin >> r >> c;
        arr[r-1]++;
    }
    for(int i=0;i<m;i++){
        cout << sum << " ";
        sum+=arr[i];
    }
    return 0;
}