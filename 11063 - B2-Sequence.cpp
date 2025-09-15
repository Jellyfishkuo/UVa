#include <bits/stdc++.h>
#define int long long
#define maxn 20005
using namespace std;

int n,cnt,f;
int a[maxn],b[maxn];

main()
{
    while(cin>>n)
    {
        f=0;
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n-1;i++)
        {
            if(a[i]<1) f=1;
            if(a[i]>=a[i+1]) f=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(b[a[i]+a[j]])
                {
                    f=1;
                    break;
                }
                else
                {
                    b[a[i]+a[j]]=1;
                }
            }

        }
        cout<<"Case #"<<++cnt<<": ";
        if(f) cout<<"It is not a B2-Sequence.\n\n";
        else cout<<"It is a B2-Sequence.\n\n";
    }
    return 0;
}
