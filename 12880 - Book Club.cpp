#include<bits/stdc++.h>
#define maxn 10005
using namespace std;

int n,m;
vector<int> G[maxn];
int L[maxn];
bool S[maxn],T[maxn];

bool match(int u){
    S[u]=true;
    for(int j=0;j<G[u].size();j++){
        int v=G[u][j];
        if(!T[v]){
            T[v]=true;
            if(L[v]==-1||match(L[v])){
                L[v]=u;
                return true;
            }
        }
    }
    return false;
}

int KM(){
    int ret=0;
    memset(L,-1,sizeof(L));
    for(int i=0;i<n;i++){
        if(match(i)) ret++;
	    memset(S,false,sizeof(S));
	    memset(T,false,sizeof(T));
	}
    return ret;
}

int main(){
    while(cin>>n>>m){
        for(int i=0;i<n;i++) G[i].clear();
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            G[a].push_back(b);
        }
        int ans=KM();
        if(ans==n) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
