#include <bits/stdc++.h>
#define int long long
#define maxn 1005
using namespace std;

int n;
string s[maxn];
int a[maxn];

main()
{
    cin>>n;
    for(int cas=1;cas<=n;cas++)
    {
        int mx=-1;
        for(int i=0;i<10;i++)
        {
            cin>>s[i]>>a[i];
            mx=max(mx,a[i]);
        }
        cout<<"Case #"<<cas<<":\n";
        for(int i=0;i<10;i++)
            if(a[i]==mx) cout<<s[i]<<endl;
    }
    return 0;
}
