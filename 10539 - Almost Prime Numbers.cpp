#include <bits/stdc++.h>
#define int long long
#define maxn 1000005
#define mmaxn 1e12
using namespace std;

int n,a,b;
vector<int> arr;
vector<bool> isp(maxn+1,1);

void p()
{
    isp[0]=isp[1]=0;
    for(int i=2;i*i<maxn;i++)
        if(isp[i])
            for(int j=i*i;j<maxn;j+=i)
                isp[j]=0;
}

main()
{
    p();
    for(int i=2;i<maxn;i++)
        if(isp[i])
        {
            int x=i*i;
            while(x<mmaxn)
            {
                arr.push_back(x);
                x*=i;
            }
        }
    sort(arr.begin(),arr.end());
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        cout<<upper_bound(arr.begin(),arr.end(),b)-lower_bound(arr.begin(),arr.end(),a)<<endl;
    }
    return 0;
}
