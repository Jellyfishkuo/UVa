#include<bits/stdc++.h>
#define int long long
using namespace std;

main(){
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n],cnt=0;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    arr[j]^=arr[j+1]^=arr[j]^=arr[j+1];
                    cnt++;
                }
            }
        }
        cout<<"Optimal train swapping takes "<<cnt<<" swaps.\n";
    }
    return 0;
}
