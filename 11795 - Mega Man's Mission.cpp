#include <bits/stdc++.h>
#define int long long
#define maxn 1<<16
using namespace std;

int t,n;
int dp[maxn],state[maxn];
string str;

main()
{
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        int robot[17]={0};
        cin>>n;
        memset(state,0,sizeof(state));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
        {
            cin>>str;
            int rb=1;
            for(int j=0;j<n;j++)
            {
                if(str[j]=='1') robot[i]|=rb;
                rb<<=1;
            }
        }
        state[0]=robot[0];
        dp[0]=1;
        int total=1<<n;
        for(int i=0;i<total;i++)
        {
            int todo=(~i)&state[i];
            int rb=1;
            for(int j=1;j<=n;j++)
            {
                if(todo&rb)
                {
                    dp[rb|i]+=dp[i];
                    state[rb|i]=state[i]|robot[j];
                }
                rb<<=1;
            }
        }
        cout<<"Case "<<cas<<": "<<dp[total-1]<<endl;
    }
    return 0;
}

/*
3
1
1
1
2
11
01
10
3
110
011
100
000

*/
