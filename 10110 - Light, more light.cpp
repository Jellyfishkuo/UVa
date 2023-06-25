#include<bits/stdc++.h>
#define int long long
using namespace std;

main(){
    int n;
    while(cin>>n,n){
        if((int)sqrt(n)*(int)sqrt(n)==n) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
