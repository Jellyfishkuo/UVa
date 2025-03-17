#include <bits/stdc++.h>
using namespace std;

int k,pow10[10];

int mod(int n){
    return (n%k+k)%k;
}

int m[11][90][90];

int f(int d,int m1,int m2){
    if(d==0) return m1==0&&m2==0?1:0;
    int& ans=m[d][m1][m2];
    if(ans>=0) return ans;
    ans=0;
    for(int x=0;x<=9;x++)
        ans+=f(d-1,mod(m1-x),mod(m2-x*pow10[d-1]));
    m[d][m1][m2]=ans;
    return ans;
}

int sumf(int n){
    char digits[11];
    sprintf(digits,"%d",n);
    int nd=strlen(digits);
    int base=0,sumd=0,ans=0;
    for(int i=0;i<nd;i++){
        int na=nd-1-i;
        for(int d=0;d<digits[i]-'0';d++){
            int cnt=f(na,mod(-sumd-d),mod(-base-d*pow10[na]));
            ans+=cnt;
        }
        base+=(digits[i]-'0')*pow10[na];
        sumd+=(digits[i]-'0');
    }
    return ans;
}

int main()
{
    pow10[0]=1;
    for(int i=1;i<=9;i++)
        pow10[i]=pow10[i-1]*10;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d%d",&a,&b,&k);
        memset(m,-1,sizeof(m));
        if(k>85) printf("0\n");
        else printf("%d\n",sumf(b+1)-sumf(a));
    }
    return 0;
}


/*
30
1 20 1
1 20 2
1 1000 4

*/
