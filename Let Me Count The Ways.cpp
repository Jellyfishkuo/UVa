#include<bits/stdc++.h>
#define int long long
#define maxn 30005
using namespace std;

int n;
vector<int> dp(maxn+1,0);
int coins[5]={1,5,10,25,50};

main()
{
    dp[0]=1;
    for(int i=0;i<5;i++)
        for(int j=coins[i];j<maxn;j++)
            dp[j]+=dp[j-coins[i]];
    while(cin>>n)
    {
        if(dp[n]==1)
            cout<<"There is only 1 way to produce "<<n<<" cents change."<<"\n";
        else
            cout<<"There are "<<dp[n]<<" ways to produce "<<n<<" cents change."<<"\n";
    }
}
