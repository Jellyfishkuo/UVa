#include <bits/stdc++.h>
#define maxn 1000+5
using namespace std;

int cnt;
map<string,int> id;
int ID(string s){
    if(!id.count(s)) id[s]=cnt++;
    return id[s];
}
struct Component{
    int price;
    int quality;
};
int n,b;
vector<Component> comp[maxn];
bool Test(int q){
    int sum=0;
    for(int i=0;i<cnt;i++){
        int cheapest=b+1,m=comp[i].size();
        for(int j=0;j<m;j++)
            if(comp[i][j].quality>=q)
                cheapest=min(cheapest,comp[i][j].price);
        if(cheapest==b+1) return false;
        sum+=cheapest;
        if(sum>b) return false;
    }
    return true;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>b;
        cnt=0;
        for(int i=0;i<n;i++) comp[i].clear();
        id.clear();
        int maxq=0;
        for(int i=0;i<n;i++){
            char type[30],name[30];
            int p,q;
            cin>>type>>name>>p>>q;
            maxq=max(maxq,q);
            comp[ID(type)].push_back((Component){p,q});
        }
        int L=0,R=maxq;
        while(L<R){
            int M=L+(R-L+1)/2;
            if(Test(M)) L=M;
            else R=M-1;
        }
        cout<<L<<endl;
    }
    return 0;
}
