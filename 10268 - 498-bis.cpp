#include<bits/stdc++.h>
#define int long long
using namespace std;

main()
{
    int x,v;
    string s;
    while(cin>>x>>ws)
    {
        getline(cin,s);
        istringstream sin(s);
        vector<int> a;
        while(sin>>v) a.insert(a.begin(),v); //把讀到的係數插到開頭
        for(int k=0;k<a.size();k++)
            a[k]*=k;
        a.erase(a.begin()); //刪掉常數
        int u=1,ans=0;
        for(auto &v:a)
        {
            ans+=u*v;
            u*=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}
