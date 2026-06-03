#include <bits/stdc++.h>
using namespace std;

const int maxn=10005;
pair<int,int> range[maxn];

int main()
{
    int l,n;
    while(cin>>l>>n,l)
    {
        for(int i=0;i<n;i++)
        {
            int x,r;
            cin>>x>>r;
            range[i]=make_pair(x-r,x+r);
        }
        sort(range,range+n);
        int left=0,needed=0,i=0;
        bool possible=true;
        while(left<l)
        {
            int max_right=left;
            while(i<n&&range[i].first<=left)
            {
                if(range[i].second>max_right) max_right=range[i].second;
                i++;
            }
            if(max_right==left)
            {
                possible=false;
                break;
            }
            left=max_right;
            needed++;
        }
        if(!possible||left<l) cout<<"-1\n";
        else cout<<n-needed<<"\n";
    }
    return 0;
}
