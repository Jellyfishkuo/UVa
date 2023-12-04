#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxm=500+5;
int m,k,p[maxm];

int solve(int maxp){
    int done=0;
    int ans=1;
    for(int i=0;i<m;i++){
        if(done+p[i]<=maxp) done+=p[i];
        else{
            ans++;
            done=p[i];
        }
    }
    return ans;
}

int last[maxm];

void print(int ans){
    int done=0;
    memset(last,0,sizeof(last));
    int remain=k;
    for(int i=m-1;i>=0;i--){
        if(done+p[i]>ans||i+1<remain){
            last[i]=1;
            remain--;
            done=p[i];
        }
        else done+=p[i];
    }
    for(int i=0;i<m-1;i++){
        cout<<p[i]<<" ";
        if(last[i]) cout<<"/ ";
    }
    cout<<p[m-1]<<endl;
}

main(){
    int cas;
    cin>>cas;
    while(cas--){
        cin>>m>>k;
        int total=0;
        int maxp=-1;
        for(int i=0;i<m;i++){
            cin>>p[i];
            total+=p[i];
            maxp=max(maxp,p[i]);
        }
        int left=maxp,right=total;
        while(left<right){
            int mid=left+(right-left)/2;
            if(solve(mid)<=k) right=mid;
            else left=mid+1;
        }
        print(left);
    }
    return 0;
}
