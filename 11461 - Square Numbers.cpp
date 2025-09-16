#include<bits/stdc++.h>
using namespace std;

int a,b;

int main()
{
    while(cin>>a>>b&&(a||b))
    {
        int aa=ceil(sqrt(a)),bb=floor(sqrt(b));
        cout<<bb-aa+1<<endl;
    }
}
