#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m){
        double ans=0.0,pos;
        for(int i=1;i<n;i++){
            pos=(double)i/n*(n+m);
            ans+=fabs(pos-floor(0.5+pos));
        }
        cout<<fixed<<setprecision(4)<<10000*ans/(n+m)<<endl;
    }
}
