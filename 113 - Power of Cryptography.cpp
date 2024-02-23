#include <bits/stdc++.h>
#define int long long
using namespace std;

double n,p;

main(){
    while(cin>>n>>p)
        cout<<fixed<<setprecision(0)<<pow(p,1.0/n)<<endl;
    return 0;
}
