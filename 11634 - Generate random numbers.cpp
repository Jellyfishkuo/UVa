#include <bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;

int n;
bool vis[maxn];

main()
{
    while(cin>>n,n)
    {
        int cnt=0;
        memset(vis,0,sizeof(vis));
        while(!vis[n])
        {
            cnt++;
            vis[n]=1;
            n=(n*n)/100%10000;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
