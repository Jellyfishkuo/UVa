#include <bits/stdc++.h>
#define int long long
using namespace std;

int l,h,r,R=INT_MIN;
int arr[500000];

main(){
    while(cin>>l>>h>>r){
        R=max(r,R);
        for(int i=l;i<r;i++) arr[i]=max(arr[i],h);
    }
    for(int i=0;i<R;i++)
        if(arr[i]!=arr[i-1]) cout<<i<<" "<<arr[i]<<" ";
    cout<<R<<" 0\n";
    return 0;
}
