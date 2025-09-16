#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;

vector<bool> isp(maxn+1,1);

void p()
{
    isp[0]=isp[1]=0;
    for(int i=2;i*i<maxn;i++)
        if(isp[i])
            for(int j=i*i;j<maxn;j+=i)
                isp[j]=0;
}

int n;

int main()
{
    p();
    while(cin>>n,n)
    {
        int f=0;
        for(int i=3;i<=n/2;i+=2)
        {
            if(isp[i]&&isp[n-i])
            {
                cout<<n<<" = "<<i<<" + "<<n-i<<endl;
                f=1;
                break;
            }
        }
        if(!f) cout<<"Goldbach's conjecture is wrong.\n";
    }
    return 0;
}
