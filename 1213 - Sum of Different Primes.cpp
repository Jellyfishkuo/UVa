#include <bits/stdc++.h>
#define maxn 1120+10
using namespace std;

int visited[maxn]={false};
int prime[maxn];
int dp[maxn][15]={0};

int main(){
    int prime_cnt=0;
    for(int i=2;i<=maxn;i++)
        if(!visited[i]){
            prime[prime_cnt++]=i;
            for(int j=i*i;j<=maxn;j+=i)
                visited[j]=true;
        }
    dp[0][0]=1;
    for(int i=0;i<prime_cnt;i++)
        for(int n=maxn;n>=prime[i];n--)
            for(int k=1;k<=14;k++)
                dp[n][k]+=dp[n-prime[i]][k-1];
    int n,k;
    while(cin>>n>>k,n)cout<<dp[n][k]<<endl;
    return 0;
}
