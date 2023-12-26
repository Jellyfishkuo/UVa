#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define maxn 2000+10
using namespace std;

int maxTree[maxn][maxn],minTree[maxn][maxn],n;
int xo,xleaf,x1,y1,x2,y2,x,y,v,vmax,vmin;

void query_Y(int o,int l,int r){
    if(y1<=l&&r<=y2){
        vmax=max(vmax,maxTree[xo][o]);
        vmin=min(vmin,minTree[xo][o]);
    }
    else{
        int mid=(l+r)/2;
        if(y1<=mid) query_Y(o*2,l,mid);
        if(mid<y2) query_Y(o*2+1,mid+1,r);
    }
}


void query_X(int o,int l,int r){
    if(x1<=l&&r<=x2){
        xo=o;
        query_Y(1,1,n);
    }
    else{
        int mid=(l+r)/2;
        if(x1<=mid) query_X(o*2,l,mid);
        if(mid<x2) query_X(o*2+1,mid+1,r);
    }
}

void modify_Y(int o,int l,int r){
    if(l==r){
        if(xleaf){
            maxTree[xo][o]=minTree[xo][o]=v;
            return;
        }
        maxTree[xo][o]=max(maxTree[xo*2][o],maxTree[xo*2+1][o]);
        minTree[xo][o]=min(minTree[xo*2][o],minTree[xo*2+1][o]);
    }
    else{
        int mid=(l+r)/2;
        if(y<=mid) modify_Y(o*2,l,mid);
        else modify_Y(o*2+1,mid+1,r);
        maxTree[xo][o]=max(maxTree[xo][o*2],maxTree[xo][o*2+1]);
        minTree[xo][o]=min(minTree[xo][o*2],minTree[xo][o*2+1]);
    }
}

void modify_X(int o,int l,int r){
    if(l==r){
        xo=o;
        xleaf=1;
        modify_Y(1,1,n);
    }
    else{
        int mid=(l+r)/2;
        if(x<=mid) modify_X(o*2,l,mid);
        else modify_X(o*2+1,mid+1,r);
        xo=o;
        xleaf=0;
        modify_Y(1,1,n);
    }
}

int main(){
    while(cin>>n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>v;
                x=i;
                y=j;
                modify_X(1,1,n);
            }
        }
        int Q;
        string op;
        cin>>Q;
        while(Q--){
            cin>>op;
            if(op[0]=='q'){
                cin>>x1>>y1>>x2>>y2;
                vmax=-INF;
                vmin=INF;
                query_X(1,1,n);
                cout<<vmax<<" "<<vmin<<endl;
            }
            else{
                cin>>x>>y>>v;
                modify_X(1,1,n);
            }
        }
    }
    return 0;
}
