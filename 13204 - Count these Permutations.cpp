#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define maxn 1000005
using namespace std;

int n;
vector<int> f(maxn+1, 1);

main(){
    for(int i=1;i<maxn;i++)
        f[i]=(f[i-1]*i)%MOD;
    while(cin>>n)
    {
        int res=(f[n/2]*f[n/2])%MOD;
        if(n%2) res=(res*n)%MOD;
        cout<<res<<endl;
    }
    return 0;
}

/*
當 n 為偶數時，符合條件的排列數 = (n/2!)^2
當 n 為奇數時，符合條件的排列數 = (n/2!)^2*n
*/
