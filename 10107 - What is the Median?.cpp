#include <bits/stdc++.h>
#define maxn 10005
#define int long long
using namespace std;

int x,cnt;
int a[maxn];

main()
{
    while(cin>>a[cnt++])
    {
        sort(a,a+cnt);
        if(cnt%2) cout<<a[cnt/2]<<endl;
        else cout<<(a[cnt/2]+a[cnt/2-1])/2<<endl;
    }
    return 0;
}
