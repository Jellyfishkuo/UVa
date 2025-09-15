#include <bits/stdc++.h>
#define int long long
#define maxn 205
using namespace std;

int n,b,c,ans1,ans2,cntb,cntc;
int a[maxn][maxn];

main()
{
    while(cin>>n,n)
    {
        cntb=0,cntc=0,ans1=-1,ans2=-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                b+=a[i][j];
                c+=a[j][i];
            }
            if(b%2) ans1=i,cntb++;
            if(c%2) ans2=i,cntc++;
            b=0,c=0;
        }
        if(ans1==-1&&ans2==-1) cout<<"OK\n";
        else if(cntb>1||cntc>1) cout<<"Corrupt\n";
        else cout<<"Change bit ("<<ans1+1<<","<<ans2+1<<")"<<endl;
    }
    return 0;
}
