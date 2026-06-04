#include <bits/stdc++.h>
using namespace std;

const int maxn=10010;
int n;
int arr[maxn];

bool judge(int* a)
{
    for(int i=0;i<n;i++)
        for(int j=1;i+2*j<n;j++)
            if(a[i]<a[i+j]&&a[i+j]<a[i+2*j]||a[i]>a[i+j]&&a[i+j]>a[i+2*j]) return false;
    return true;
}

int main()
{
    int x;
    char c;
    while(cin>>n,n)
    {
        cin>>c;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            arr[x]=i;
        }
        if(judge(arr)) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
