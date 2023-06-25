#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    while(cin>>n){
        int arr[n],t,now=INT_MAX,ansi,ansj;
        for(int i=0;i<n;i++) cin>>arr[i];
        cin>>t;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(arr[i]+arr[j]==t&&abs(arr[i]-arr[j])<now){
                    ansi=arr[i];
                    ansj=arr[j];
                    now=abs(arr[i]-arr[j]);
                }
        cout<<"Peter should buy books whose prices are "<<min(ansi,ansj)<<" and "<<max(ansi,ansj)<<".\n\n";
    }
}
