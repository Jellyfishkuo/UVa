#include<bits/stdc++.h>
#define maxn 200000+5
using namespace std;

int a[maxn];
int l[maxn],r[maxn];

map<int,int> m;
int n;

bool judge(int left,int right){
    if(left>=right) return true;
    for(int i=0;i<=(right-left)/2;i++){
        if(l[left+i]<left && r[left+i]>right)
            return judge(left,left+i-1) && judge(left+i+1,right);
        if(l[right-i]<left && r[right-i]>right)
            return judge(left,right-i-1) && judge(right-i+1,right);
    }
    return false;
}

main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++) cin>>a[i];
        m.clear();
        for(int i=0;i<n;i++){
            if(m.count(a[i])) l[i]=m[a[i]];
            else l[i]=-1;
            m[a[i]]=i;
        }
        m.clear();
        for(int i=n-1;i>=0;i--){
            if(m.count(a[i])) r[i]=m[a[i]];
            else r[i]=n;
            m[a[i]]=i;
        }
        if(judge(0,n-1)) cout<<"non-boring"<<endl;
        else cout<<"boring"<<endl;
    }
    return 0;
}
