#include<bits/stdc++.h>
using namespace std;

const double eps=1e-6;

int main()
{
    double L,C,n;
    while(cin>>L>>C>>n)
    {
        if(L<0&&n<0&&C<0) break;
        if(n<eps||C<eps)
        {
            cout<<"0.000\n";
            continue;
        }
        double a=L/2,b=(1+n*C)*L/2;
        double l=1e-9,r=10e9;
        while(r-l>eps)
        {
            double m=(l+r)/2;
            if(m*sin(b/m)>a) r=m;
            else l=m;
        }
        cout<<fixed<<setprecision(3)<<l-l*cos(b/l)<<endl;
    }
    return 0;
}

/*
1000 100 0.0001
15000 10 0.00006
10 0 0.001
-1 -1 -1
*/
