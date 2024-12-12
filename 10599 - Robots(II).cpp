#include<bits/stdc++.h>
#define int long long
#define maxn 107
using namespace std;

int G[maxn][maxn];
int A[maxn*maxn],LIS[maxn*maxn],num[maxn*maxn],path[maxn*maxn];
int row,col,n;

void show_path(int c)
{
    if(path[c]!=-1) show_path(path[c]);
    if((c!=n-1)||G[row][col]) cout<<" "<<A[c];
}

main()
{
    int cas=1;
    while(cin>>row>>col)
    {
        if(row==-1&&col==-1) break;
        memset(G,0,sizeof(G));
        memset(A,0,sizeof(A));
        int x,y;
        while(cin>>x>>y)
        {
            if(x==0&&y==0) break;
            G[x][y]=1;
        }
        n=0;
        for(int i=1; i<=row; i++)
        {
            for(int j=1; j<=col; j++)
            {
                if(G[i][j]) A[n++]=(i-1)*col+j;
            }
        }
        if(!G[row][col]) A[n++]=row*col;
        for(int i=0; i<=n; i++)
        {
            LIS[i]=1,num[i]=1,path[i]=-1;
            for(int j=0; j<i; j++)
            {
                if(((A[j]-1)%col)<=((A[i]-1)%col))
                {
                    if(LIS[i]==LIS[j]+1) num[i]+=num[j];
                    else if(LIS[i]<LIS[j]+1)
                    {
                        LIS[i]=LIS[j]+1;
                        num[i]=num[j];
                        path[i]=j;
                    }
                }
            }

        }
        if(!G[row][col]) LIS[n-1]--;
        cout<<"CASE#"<<cas++<<": "<<LIS[n-1]<<" "<<num[n-1];
        show_path(n-1);
        cout<<endl;
    }
    return 0;
}


/*
6 7
1 2
1 4
2 4
2 6
4 4
4 7
6 6
0 0
4 4
1 1
2 2
3 3
4 4
0 0
-1 -1

*/
