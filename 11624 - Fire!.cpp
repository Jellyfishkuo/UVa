#include <bits/stdc++.h>
#define maxn 1000+10
using namespace std;

char maze[maxn][maxn];
int F[maxn][maxn],J[maxn][maxn];
int n,m,dir[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};

struct position
{
    int x,y;
};

position pfire,pjoe;
queue<position>Q;

void solve()
{
    while(!Q.empty()) Q.pop();
    position tn,tx;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(maze[i][j]=='F')
            {
                pfire.x=i;
                pfire.y=j;
                Q.push(pfire);
                F[pfire.x][pfire.y]=1;
            }
    while(!Q.empty())
    {
        tn=Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            tx.x=tn.x+dir[i][0];
            tx.y=tn.y+dir[i][1];
            if(tx.x<0||tx.x>=n||tx.y<0||tx.y>=m) continue;
            if(maze[tx.x][tx.y]=='#') continue;
            if(F[tx.x][tx.y]==0)
            {
                F[tx.x][tx.y]=F[tn.x][tn.y]+1;
                Q.push(tx);
            }
        }
    }
    Q.push(pjoe);
    J[pjoe.x][pjoe.y]=1;
    while(!Q.empty())
    {
        tn=Q.front();
        Q.pop();
        if(tn.x==0||tn.y==0||tn.x==n-1||tn.y==m-1)
        {
            cout<<J[tn.x][tn.y]<<endl;
            return;
        }
        for(int i=0; i<4; i++)
        {
            tx.x=tn.x+dir[i][0];
            tx.y=tn.y+dir[i][1];
            if(tx.x<0||tx.x>=n||tx.y<0||tx.y>=m) continue;
            if(maze[tx.x][tx.y]=='#') continue;
            if(J[tx.x][tx.y]==0&&(J[tn.x][tn.y]+1<F[tx.x][tx.y]||F[tx.x][tx.y]==0))
            {
                J[tx.x][tx.y]=J[tn.x][tn.y]+1;
                Q.push(tx);
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            cin>>maze[i];
            for(int j=0; j<m; j++)
            {
                if(maze[i][j]=='J')
                {
                    pjoe.x=i;
                    pjoe.y=j;
                }
                F[i][j]=0;
                J[i][j]=0;
            }
        }
        solve();
    }
    return 0;
}
