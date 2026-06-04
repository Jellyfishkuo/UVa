#include <bits/stdc++.h>
#define maxn 25
using namespace std;

double t,u[maxn],v[maxn];
int n;

double cal(double rd)
{
    double cd=t-rd;
    double ans=1e8;
    double tc=rd/u[n-1]+cd/v[n-1];
    for(int i=0;i<n-1;i++)
    {
        double tmp=rd/u[i]+cd/v[i];
        ans=min(ans,tmp-tc);
    }
    return ans;
}

int main()
{
    while(cin>>t)
    {
        cin>>n;
        for(int i=0;i<n;i++) cin>>u[i]>>v[i];
        double l=0,r=t;
        for(int i=0;i<100;i++)
        {
            double lm=l+(r-l)/3;
            double rm=r-(r-l)/3;
            if(cal(lm)>cal(rm)) r=rm;
            else l=lm;
        }
        if(cal(l)<=1e-9) cout<<"The cheater cannot win.\n";
        else
        {
            cout<<fixed<<setprecision(0)<<"The cheater can win by "<<cal(l)*3600<<" seconds with r = ";
            cout<<fixed<<setprecision(2)<<r<<"km and k = "<<t-l<<"km."<<endl;
        }
    }
    return 0;
}
