#include <bits/stdc++.h>
#define maxn 10000+5
using namespace std;

struct ant{
    int id;
    int p;
    int d;
    bool operator<(const ant&a)const{
        return p<a.p;
    }
}before[maxn],after[maxn];

const char dirname[][10]={"L","Turning","R"};

int order[maxn];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<":\n";
        int L,T,n;
        cin>>L>>T>>n;
        for(int j=0;j<n;j++){
            int p;
            char c;
            cin>>p>>c;
            int d=(c=='L'?-1:1);
            before[j]=(ant){j,p,d};
            after[j]=(ant){0,p+T*d,d};
        }
        sort(before,before+n);
        for(int j=0;j<n;j++) order[before[j].id]=j;
        sort(after,after+n);
        for(int j=0;j<n-1;j++)
            if(after[j].p==after[j+1].p) after[j].d=after[j+1].d=0;
        for(int j=0;j<n;j++){
            int x=order[j];
            if(after[x].p<0||after[x].p>L) cout<<"Fell off\n";
            else cout<<after[x].p<<" "<<dirname[after[x].d+1]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
