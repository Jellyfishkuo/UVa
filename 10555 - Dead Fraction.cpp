#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define int long long
using namespace std;

string s,s1,s2;
int n1,n2,n3;

main()
{
    while(cin>>s)
    {
        if(s=="0") break;
        int ans1=0,ans2=INF;
        s1=s.substr(2,s.size()-5);
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            s2=s1.substr(0,i);
            string s_repeat = s1;
            n1=stoll(s_repeat);
            n2=s2.empty()?0:stoll(s2);
            n3=stoll(string(n-i,'9')+string(i,'0'));
            int g=__gcd(n1-n2,n3);
            if(n3/g<ans2)
            {
                ans1=(n1-n2)/g;
                ans2=n3/g;
            }
        }
        cout<<ans1<<"/"<<ans2<<endl;
    }
    return 0;
}
