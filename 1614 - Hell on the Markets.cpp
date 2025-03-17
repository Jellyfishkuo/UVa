#include <bits/stdc++.h>
#define int long long
#define maxn 100100
using namespace std;

int n,arr[maxn],sum[maxn],tmp,ans[maxn];

main()
{
    sum[0]=0;
    while(cin>>n&&n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            sum[i]=arr[i]+sum[i-1];
        }
        if(sum[n]&1||n==1)
        {
            cout<<"No\n";
            continue;
        }
        tmp=sum[n]>>1;
        for(int i=n-1;i>=0;--i)
        {
            if(sum[i]<tmp&&tmp<=sum[i+1])
            {
                tmp-=arr[i+1];
                ans[i+1]=1;
            }
            else ans[i+1]=-1;
        }
        if(tmp) ans[1]*=-1;
        cout<<"Yes\n";
        for(int i=1;i<n;i++) cout<<ans[i]<<" ";
        cout<<ans[n]<<endl;
    }
    return 0;
}

/*
4
1 2 3 3
4
1 2 3 4

*/
