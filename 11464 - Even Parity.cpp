#include <bits/stdc++.h>
#define maxn 20
#define INF 1000000000
using namespace std;

int n,a[maxn][maxn],b[maxn][maxn];

int check(int s){
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++)
        if(s&(1<<i)) b[0][i]=1;
        else if(a[0][i]==1) return INF;
    for(int r=1;r<n;r++)
        for(int c=0;c<n;c++){
            int sum=0;
            if(r>1) sum+=b[r-2][c];
            if(c>0) sum+=b[r-1][c-1];
            if(c<n-1) sum+=b[r-1][c+1];
            b[r][c]=sum%2;
            if(a[r][c]==1&&b[r][c]==0) return INF;
        }
    int cnt=0;
    for(int r=0;r<n;r++)
        for(int c=0;c<n;c++)
            if(a[r][c]!=b[r][c]) cnt++;
    return cnt;
}

int main(){
    int t;
    cin>>t;
    for(int Case=1;Case<=t;Case++){
        cin>>n;
        for(int r=0;r<n;r++)
            for(int c=0;c<n;c++)
                cin>>a[r][c];
        int ans=INF;
        for(int s=0;s<(1<<n);s++)
            ans=min(ans,check(s));
        if(ans==INF) ans=-1;
        cout<<"Case "<<Case<<": "<<ans<<endl;
    }
    return 0;
}
