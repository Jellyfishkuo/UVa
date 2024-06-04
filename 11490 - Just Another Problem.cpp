#include <bits/stdc++.h>
#define MOD 100000007
#define int long long
using namespace std;

int s;

main(){
    while(cin>>s,s){
        bool flag=false;
        int x=sqrt(s/6+0.1);
        for(int b=1;b<x;b++){
            int a=s-b*b*6;
            if(a%(7*b)==0){
                int ans=a/(7*b)%MOD;
                cout<<"Possible Missing Soldiers = "<<ans*ans*2%MOD<<endl;
                flag=true;
            }
        }
        if(!flag) cout<<"No Solution Possible\n";
        cout<<endl;
    }
    return 0;
}
