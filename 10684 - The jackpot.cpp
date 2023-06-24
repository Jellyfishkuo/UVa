#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n,n){
        int x,sum=0,ans=0;
        for(int i=0;i<n;i++){
            cin>>x;
            if(sum<0) sum=x;
            else sum+=x;
            ans=max(ans,sum);
        }
        if(ans>0) cout<<"The maximum winning streak is "<<ans<<"."<<endl;
        else cout<<"Losing streak.\n";
    }
}
