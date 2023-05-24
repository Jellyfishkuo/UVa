#include<bits/stdc++.h>
using namespace std;

int m,n,a[400+5],num[400+5],c[400+5];
bool check(int x){
    memset(c,0,sizeof(c));
    int tmp=0;
    for(int i=m;i>=1;--i){
        tmp+=a[i]*x;
        int v=tmp%n;
        if(++c[v]>num[v]) return false;
        tmp/=n;
    }
    return tmp==0;
}

bool solve(){
    for(int i=1;i<=(n-1);++i){
        memset(num,0,sizeof(num));
        for(int j=1;j<=m;++j){
            a[j]=i*j%n;
            num[a[j]]++;
        }
        swap(a[1],a[m]);
        sort(a+1,a+m);
        do{
            if(a[1]==0) continue;
            bool ok=true;
            for(int i=2;i<=m;i++){
                if(check(i)) continue;
                ok=false;
                break;
            }
            if(ok) return true;
        }while(next_permutation(a+1,a+m));
    }
    return false;
}

int main(){
    while(cin>>m>>n,m+n){
        if(solve())
            for(int i=1;i<=m;i++)
                cout<<(i==1?"":" ")<<a[i];
        else cout<<"Not found.";
        cout<<endl;
    }
    return 0;
}
