#include <bits/stdc++.h>
#define maxn 150000+5
using namespace std;

struct state{
    int sum,id,key;
}s[maxn],c[maxn];

int n,p,ans,cnt;
char a[maxn],b[maxn];

int find(int key){
    int l=0,r=cnt-1;
    while(l<r){
        int mid=(l+r)/2;
        if(c[mid].key<=key) r=mid;
        else l=mid+1;

    }
    return c[l].id;
}

bool solve(){
    ans=0;
    cnt=1;
    s[0].sum=s[0].id=0;
    s[0].key=0;
    c[0]=s[0];
    for(int i=1;i<=n;i++){
        s[i].sum=s[i-1].sum+(a[i-1]!= b[i-1]);
        s[i].id=i;
        s[i].key=i*p-100*s[i].sum;
        if(s[i].key<c[cnt-1].key) c[cnt++]=s[i];
        else{
            int t=find(s[i].key);
            ans=max(ans,s[i].id-t);
        }
    }
    if(ans) return true;
    return false;
}

int main(){
    while(cin>>n>>p,n+p){
        cin>>a>>b;
        if(solve()) cout<<ans<<endl;
        else cout<<"No solution.\n";
    }
    return 0;
}
