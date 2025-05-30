#include <bits/stdc++.h>
#define maxn 900009
using namespace std;

int n,cnt;
int a[maxn];
int dp[maxn];

int main()
{
    while(cin>>n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        int f=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]<=a[i-1])
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            memset(dp,0,sizeof(dp));
            dp[0]=1;
            for(int i=0;i<n;i++)
            {
                if(dp[a[i]])
                {
                    f=0;
                    break;
                }
                if(f)
                {
                    for(int j=sum;j>=a[i];--j)
                        if(dp[j-a[i]])
                            dp[j]=1;
                }
            }
        }
        cout<<"Case #"<<++cnt<<":";
        for(int i=0;i<n;i++) cout<<" "<<a[i];
        if(f) cout<<"\nThis is an A-sequence.\n";
        else cout<<"\nThis is not an A-sequence.\n";
    }
    return 0;
}


/*
2 1 2
3 1 2 3
10 1 3 16 19 25 70 100 243 245 306

*/
