#include<bits/stdc++.h>
#define int long long
#define maxn 1000005
using namespace std;

int n,d;
int vis[maxn];
char ch;

main()
{
    while(cin>>n>>d,n||d)
    {
        int k=n-d; //最後結果數字的位數
        int cnt=0; //暫存目前蒐集到的結果的位數
        for(int i=0;i<n;i++)
        {
            cin>>ch;
            int num=ch-'0';
            //檢查是否可以向左壓縮
            //cnt!=0
            //cnt + 總位數 - 檢查的第i個字 > 所需位數
            //當前數字 > 已蒐集的最後一個數字
            while(cnt&&cnt+n-i>k&&num>vis[cnt-1]) --cnt;
            //把kk放進蒐集結果的vis[cnt]中
            if(cnt<k) vis[cnt++]=num;
        }
        for(int i=0;i<k;i++) cout<<vis[i];
        cout<<endl;
    }
    return 0;
}


/*
4 2
3759
6 3
123123
7 4
1000000
0 0

*/
