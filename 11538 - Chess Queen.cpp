#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int n,m;

main()
{
    while(cin>>n>>m&&n||m)
    {
        if(n>m) swap(n,m);
        cout<<n*m*(n+m-2)+2*n*(n-1)*(3*m-n-1)/3<<endl;
    }
    return 0;
}


/*
2 2
100 223
2300 1000
0 0

*/
