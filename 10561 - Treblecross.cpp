#include <bits/stdc++.h>
using namespace std;

const int N=205;
int cnt,n,len,sg[N],ans[N];
bool vis[N];
char s[N];

void SG(int n)
{
    sg[0]=0;
    sg[1]=sg[2]=sg[3]=1;
    for(int i=4;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=i;j++)
        {
            int left=max(0,j-3);
            int right=max(0,i-j-2);
            vis[sg[left]^sg[right]]=1;
        }
        for(int j=0;j<=i;j++)
        {
            if(!vis[j])
            {
                sg[i]=j;
                break;
            }
        }
    }
}

bool cur(int x)
{
    if(x>2&&s[x-2]=='X'&&s[x-1]=='X'&&s[x]=='X') return true;
    if(x>1&&x+1<=len&&s[x-1]=='X'&&s[x]=='X'&&s[x+1]=='X') return true;
    if(x+2<=len&&s[x]=='X'&&s[x+1]=='X'&&s[x+2]=='X') return true;
    return false;
}

bool rest()
{
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='.')
        {
            s[i]='X';
            if(cur(i))
            {
                s[i]='.';
                return false;
            }
            s[i]='.';
        }
    }
    int res=0,num=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='X'||(i>1&&s[i-1]=='X')||(i>2&&s[i-2]=='X')||(i<len&&s[i+1]=='X')||(i+2<=len&&s[i+2]=='X'))
        {
            if(num>0)
            {
                res^=sg[num];
                num=0;
            }
        }
        else num++;
    }
    if(num>0) res^=sg[num];
    return (!res);
}

void solve()
{
    cin>>(s+1);
    len=strlen(s+1);
    cnt=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='.')
        {
            s[i]='X';
            if(cur(i)) ans[++cnt]=i;
            else if(rest()) ans[++cnt]=i;
            s[i]='.';
        }
    }
    if(!cnt) cout<<"LOSING\n\n";
    else
    {
        cout<<"WINNING\n";
        for(int i=1;i<=cnt;i++) cout<<(i==1?"":" ")<<ans[i];
        cout<<endl;
    }
}

int main()
{
    int cas;
    SG(200);
    cin>>cas;
    while(cas--) solve();
    return 0;
}
