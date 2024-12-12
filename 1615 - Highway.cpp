#include<bits/stdc++.h>
#define int long long
using namespace std;

int L,D,N;

struct Village{
    int x,y;  //村莊座標
    int l,r;  //村莊對應的區間
    Village(){};
    Village(int a,int b):x(a),y(b){
        int t=sqrt(D*D-y*y);
        l=max((int)0,(int)ceil(x-t));
        r=min((int)L,(int)floor(x+t));
    }
    bool operator<(const Village &v)const{
        return r<v.r;
    }
};

main()
{
    while(cin>>L>>D>>N)
    {
        vector<Village> v;
        int a,b;
        for(int i=0;i<N;i++)
        {
            cin>>a>>b;
            v.push_back(Village(a,b));
        }
        sort(v.begin(),v.end());
        int prev=v[0].r,ans=1;
        for(int i=0;i<N;i++)
        {
            if(v[i].l>prev)
            {
                ans++;
                prev=v[i].r;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
100
50
3
2 4
50 10
70 30

*/


