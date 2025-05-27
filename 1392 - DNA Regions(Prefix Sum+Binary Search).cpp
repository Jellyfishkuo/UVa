#include <bits/stdc++.h>
#define maxn 150005
using namespace std;

char s[2][maxn];
int cnt[maxn],f[maxn],nmax[maxn];
int n,p;

int judge(int len)
{
    for(int i=len;i<=n;i++)
        if(f[i]<=nmax[i-len])
            return true;
    return false;
}

int main()
{
    while(cin>>n>>p&&n)
    {
        cin>>(s[0]+1)>>(s[1]+1);
        memset(cnt,0,sizeof(cnt));
        memset(f,0,sizeof(f));
        memset(nmax,0,sizeof(nmax));
        for(int i=1;i<=n;i++)
            cnt[i]=cnt[i-1]+(s[0][i]!=s[1][i]);
        for(int i=1;i<=n;i++)
            f[i]=(100*cnt[i]-p*i);
        for(int i=1;i<=n;i++)
            nmax[i]=max(nmax[i-1],f[i]);
        int l=0,r=n;
        while(true)
        {
            int mid=(l+r)/2;
            if(l==r) break;
            if(l+1==r)
            {
                if(judge(r)) l++;
                break;
            }
            if(judge(mid)) l=mid;
            else r=mid;
        }
        if(l) cout<<l<<endl;
        else cout<<"No solution.\n";
    }
    return 0;
}


/*
14 25
ACCGGTAACGTGAA
ACTGGATACGTAAA
14 24
ACCGGTAACGTGAA
ACTGGATACGTAAA
8 1
AAAAAAAA
CCCCCCCC
8 33
AAACAAAA
CCCCCCCC
0 0

*/
