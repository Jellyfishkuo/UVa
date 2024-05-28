#include <bits/stdc++.h>
#define maxn 1025
using namespace std;

int g[maxn+5][maxn+5];
int x,y,s;
int xl,xr,yl,yr;

int main(){
    int t,n,d;
    cin>>t;
    while(t--){
        cin>>d>>n;
        memset(g,0,sizeof(g));
        while(n--){
            cin>>x>>y>>s;
            xl=max(0,x-d);
            yl=max(0,y-d);
            xr=min(x+d,maxn);
            yr=min(y+d,maxn);
            for(int i=xl;i<=xr;i++)
                for(int j=yl;j<=yr;j++)
                    g[i][j]+=s;
        }
        int mx=-1,rx,ry;
        for(int i=0;i<maxn;i++)
            for(int j=0;j<maxn;j++)
                if(g[i][j]>mx)
                    mx=g[i][j],rx=i,ry=j;
        cout<<rx<<" "<<ry<<" "<<mx<<endl;
    }
    return 0;
}
