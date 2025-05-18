#include <bits/stdc++.h>
using namespace std;

int n;
string s,t;

int main()
{
    cin>>n;
    for(int cas=1;cas<=n;cas++)
    {
        cin>>s>>t;
        int ans1=0,ans2=0,s1=0,t1=0,cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1'&&t[i]=='0') ans1++;
            if(s[i]=='0'&&t[i]=='1') ans2++;
            if(s[i]=='1') s1++;
            if(t[i]=='1') t1++;
            if(s[i]=='?') cnt++;

        }
        if(s1>t1) cout<<"Case "<<cas<<": -1\n";
        else cout<<"Case "<<cas<<": "<<max(ans1,ans2)+cnt<<endl;
    }
    return 0;
}


/*
3
01??00
001010
01
10
110001
000000

*/
