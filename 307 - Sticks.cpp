#include <bits/stdc++.h>
#define maxn 1005
using namespace std;

int n,stick[maxn];
int sum,len;
bool used[maxn];

bool dfs(int i,int L,int remain)
{
    if(L==len)
    {
        remain-=len;
        L=i=0;
    }
    if(remain==0) return true;
    for(int j=i;j<n;j++)
    {
        if(used[j]) continue;
        if(stick[j]==stick[j-1]&&!used[j-1]) continue;
        if(stick[j]+L>len) continue;
        used[j]=true;
        if(dfs(j+1,L+stick[j],remain)) return true;
        used[j]=false;
        if(L==0) return false;
    }
    return false;
}

int main()
{
    while(scanf("%d",&n)&&n)
    {
        sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&stick[i]);
            sum+=stick[i];
        }
        sort(stick,stick+n,greater<int>());
        for(len=stick[0];len<=sum/2;len++)
        {
            memset(used,0,sizeof(used));
            if((sum%len)!=0) continue;
            if(dfs(0,len,sum))
            {
                printf("%d\n",len);
                break;
            }
        }
        if(len>sum/2) printf("%d\n",sum);
    }
    return 0;
}
/*
9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
0

*/
