#include<bits/stdc++.h>
#define maxn 1025
using namespace std;

int t,n,d;
int g[maxn+5][maxn+5];
int x,y,s;
int lx,ly,rx,ry;

int main(){
    cin>>t;
    while(t--){
        cin>>d>>n;
        memset(g,0,sizeof(g));
        while(n--){
            cin>>x>>y>>s;
            lx=max(0,x-d);
            ly=max(0,y-d);
            rx=min(maxn,x+d);
            ry=min(maxn,y+d);
            for(int i=lx;i<=rx;i++)
                for(int j=ly;j<=ry;j++)
                    g[i][j]+=s;
        }
        int ans=-1,ansx,ansy;
        for(int i=0;i<maxn;i++)
            for(int j=0;j<maxn;j++)
            if(g[i][j]>ans)
                ans=g[i][j],ansx=i,ansy=j;
        cout<<ansx<<" "<<ansy<<" "<<ans<<endl;
    }
    return 0;
}
