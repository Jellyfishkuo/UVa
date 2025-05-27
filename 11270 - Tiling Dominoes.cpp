#include <bits/stdc++.h>
#define int long long
#define maxn 11
using namespace std;

int n,m;
int cur;
int dp[2][1<<maxn];

void update(int a,int b)                  // a：m 位的舊狀態，b：m+1 位的新狀態
{
    if(b&(1<<m))
        dp[cur][b^(1<<m)]+=dp[1-cur][a];  // 判斷新狀態第 m 位是否為 1
}                                         // 如果是，就把該位設回 0（b^(1<<m)），並將前一個狀態的解加到目前狀態

main()
{
    while(cin>>n>>m)
    {
        if(n<m) swap(n,m);
        memset(dp,0,sizeof(dp));
        dp[0][(1<<m)-1]=1;
        cur=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cur^=1;                   // 在 0 和 1 間切換，用來更新目前的 DP 陣列
                memset(dp[cur],0,sizeof(dp[cur]));
                for(int k=0;k<(1<<m);k++)
                {
                    update(k,k<<1);                                    // 不放，直接將二進制左移一位形成新狀態
                    if(i && !(k&(1<<m-1))) update(k,(k<<1)^(1<<m)^1);  // 上放，要求輪廓線首為 0 且為非首行
                    if(j && !(k&1)) update(k,(k<<1)^3);                // 左放，要求輪廓線首為 1，尾為 0，且為非首列
                }
            }
        }
        cout<<dp[cur][(1<<m)-1]<<endl;
    }
    return 0;
}



/*
2 10
4 10
8 8

*/
