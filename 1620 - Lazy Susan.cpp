#include <bits/stdc++.h>
#define maxn 505
using namespace std;

int n,t;
int a[maxn];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        int cnt=0;
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(a[i]>a[j]) cnt++;
        if(cnt%2&&n%2) cout<<"impossible\n";
        else cout<<"possible\n";
    }
    return 0;
}


/*
2
9
1 9 8 3 7 6 5 4 2
11
1 3 2 4 5 6 7 8 9 10 11

*/
