#include <bits/stdc++.h>
#define int long long
#define maxn 100010
using namespace std;

int A[maxn],B[maxn];

main()
{
    int n,s;
    while(cin>>n>>s&&n)
    {
        for(int i=1;i<=n;i++) cin>>A[i];
        B[0]=0;
        for(int i=1;i<=n;i++) B[i]=B[i-1]+A[i];
        int ans=n+1;
        int cnt=1;
        for(int i=1;i<=n;i++)
        {
            if(B[cnt-1]>B[i]-s) continue;
            while(B[cnt]<=B[i]-s) cnt++;
            ans=min(ans,i-cnt+1);
        }
        cout<<(ans==n+1?0:ans)<<endl;
    }
    return 0;
}


/*
10 15
5 1 3 5 10 7 4 9 2 8
5 11
1 2 3 4 5

*/
