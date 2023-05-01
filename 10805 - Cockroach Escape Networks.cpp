#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define maxn 600+5
using namespace std;

int G[maxn][maxn];

int main(){
    int Case;
    cin>>Case;
    for(int id=1;id<=Case;id++){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<maxn;i++)
            for(int j=0;j<maxn;j++){
                G[i][j]=INF;
                if(i==j) G[i][j]=0;
            }
        int c=n;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            G[u][c]=G[c][u]=1;
            G[v][c]=G[c][v]=1;
            c++;
        }
        for(int k=0;k<c;k++)
            for(int i=0;i<c;i++)
                for(int j=0;j<c;j++)
                    G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
        int ans=INF;
        for(int i=0;i<c;i++){
            sort(G[i],G[i]+n);
            ans=min(ans,G[i][n-1]+G[i][n-2]);
        }
        cout<<"Case #"<<id<<":\n";
        cout<<ans/2<<endl<<endl;
    }
    return 0;
}
