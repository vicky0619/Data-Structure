#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);

int main(){
    IOS
    int k,m,n,index=0;
    cin >> k;
    cin >> m >> n;
    int arr[m];
    for(int i=0; i<m;i++){
        arr[i]=0;
    }
    while(k--){
        int ri, ci;
        cin >> ri >>ci;
        arr[ri-1]+=1;
    }
    for(int i=0; i<m;i++){
        cout << index+1 << " ";
        index+=arr[i];
    }
    return 0;
}
