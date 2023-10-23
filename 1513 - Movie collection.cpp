#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define maxn 100005
using namespace std;

int bit[2*maxn],pos[maxn];
int n,m;

void add(int p,int v){
    while(p<2*maxn){
        bit[p]+=v;
        p+=lowbit(p);
    }
}

int sum(int p){
    int ret=0;
    while(p>0){
        ret+=bit[p];
        p-=lowbit(p);
    }
    return ret;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        memset(bit,0,sizeof(bit));
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            pos[i]=n-i+1;
            add(pos[i],1);
        }
        int req_num;
        int N=n;
        for(int i=1;i<=m;i++){
            cin>>req_num;
            cout<<n-sum(pos[req_num])<<(i==m?"\n":" ");
            add(pos[req_num],-1);
            pos[req_num]=++N;
            add(pos[req_num],1);
        }
    }
    return 0;
}
