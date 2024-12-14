#include<bits/stdc++.h>
#define maxn 1010
using namespace std;

string s;
int dp[maxn];

bool isP(int l,int r)
{
    while(l<=r)
    {
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int cas,n;

int main()
{
    cin>>cas;
    while(cas--)
    {
        cin>>s;
        n=s.size();
        for(int i=0;i<n;i++)
        {
            dp[i]=i+1;
            for(int j=0;j<=i;j++)
                if(isP(j,i)) dp[i]=min(dp[i],dp[j-1]+1);
        }
        cout<<dp[n-1]<<endl;
    }
    return 0;
}

/*
3
racecar
fastcar
aaadbccb

*/
