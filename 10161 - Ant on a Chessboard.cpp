#include<bits/stdc++.h>
#define int long long
using namespace std;

main(){
    int n;
    while(cin>>n,n){
        int s=sqrt(n);
        int c=s*s+s+1;
        if(s*s==c) cout<<s<<" "<<s;
        else if(s*s==n){
            if(s%2) cout<<"1 "<<s;
            else cout<<s<<" 1";
        }
        else if(s%2){
            if(n<c) cout<<s-abs(c-n)+1<<" "<<s+1;
            else cout<<s+1<<" "<<s-abs(c-n)+1;
        }
        else{
            if(n<c) cout<<s+1<<" "<<s-abs(c-n)+1;
            else cout<<s-abs(c-n)+1<<" "<<s+1;

        }
        cout<<endl;
    }
    return 0;
}
