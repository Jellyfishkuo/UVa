#include <bits/stdc++.h>
#define maxn 1000050
using namespace std;

int t,n;
int p[maxn],s[maxn],h[maxn];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>p[i];
        for(int i=0;i<n;i++) cin>>s[i];
        int ans=0,l=s[0];
        for(int i=0;i<n;i++)
        {
            if(p[i]>l) l=p[i];
            if(s[i]<l) l=s[i];
            h[i]=l;
        }
        l=s[n-1];
        for(int i=n-1;i>=0;i--)
        {
            if(p[i]>l) l=p[i];
            if(s[i]<l) l=s[i];
            ans+=min(h[i],l)-p[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
1
15
6 6 7 5 5 5 5 5 5 1 1 3 3 2 2
10 10 10 11 6 8 7 10 10 7 6 4 7 11 11

*/
