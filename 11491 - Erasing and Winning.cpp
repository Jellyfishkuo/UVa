#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;


int n,d;
char c;
int vis[maxn];

int main()
{
    while(cin>>n>>d,n||d)
    {
        int cnt=0;
        int k=n-d;
        for(int i=0;i<n;i++)
        {
            cin>>c;
            int num=c-'0';
            while(cnt&&cnt+n-i>k&&num>vis[cnt-1])
                --cnt;
            if(k>cnt) vis[cnt++]=num;

        }
        for(int i=0;i<k;i++)
            cout<<vis[i];
        cout<<endl;
    }
    return 0;
}
