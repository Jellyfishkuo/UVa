#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cout<<"PERFECTION OUTPUT\n";
    while(cin>>n,n)
    {
        int sum=0;
        for(int i=1;i<n;i++)
            if(n%i==0) sum+=i;
        printf("%5d  ",n);
        if(sum<n) cout<<"DEFICIENT"<<endl;
        if(sum>n) cout<<"ABUNDANT"<<endl;
        if(sum==n) cout<<"PERFECT"<<endl;
    }
    cout<<"END OF OUTPUT\n";
}
