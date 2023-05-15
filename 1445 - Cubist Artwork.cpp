#include<bits/stdc++.h>
using namespace std;

int main(){
    int w,d;
    while(cin>>w>>d,w){
        int h,F[25]={0},S[25]={0},ans=0;
        for(int i=0;i<w;i++) cin>>h,F[h]++;
        for(int i=0;i<d;i++) cin>>h,S[h]++;
        for(int i=1;i<=20;i++) ans+=max(F[i],S[i])*i;
        cout<<ans<<endl;
    }
    return 0;
}
