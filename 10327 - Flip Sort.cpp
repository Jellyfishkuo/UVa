#include<bits/stdc++.h>
#define maxn 1005
using namespace std;

int n;
int a[maxn];

int main()
{
    while(cin>>n)
    {
        int ans=0;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                if(a[i]>a[j]) ans++;
        cout<<"Minimum exchange operations : "<<ans<<endl;
    }
}
