#include<bits/stdc++.h>
#define maxn 310
#define int long long
using namespace std;

char s[maxn];
long long d[maxn][maxn];
long long dp(int i,int j){
    if(d[i][j]!=-1) return d[i][j];
    if(i==j) return 1;
    if(s[i]!=s[j]) return 0;
    int& ans=d[i][j];
    ans=0;
    for(int k=i+2;k<=j;k++)
        ans=(ans+dp(i+1,k-1)*dp(k,j))%1000000000;
    return ans;
}

main(){
    while(cin>>s){
        memset(d,-1,sizeof(d));
        cout<<dp(0,strlen(s)-1)<<endl;
    }
    return 0;
}
