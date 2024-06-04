#include <bits/stdc++.h>
#define maxn 1024+5
using namespace std;

int n,r;
int w[maxn],p[maxn],t[maxn],c[maxn];
bool existed[maxn];
int x,y;

int main(){
    while(cin>>n>>r,n+r){
        for(int i=1;i<=n;i++){
            cin>>c[i];
            w[i]=c[i];
            t[i]=1;
            existed[i]=true;
        }
        for(int i=1;i<n;i++){
            cin>>x>>y;
            p[y]=x;
        }
        for(int i=1;i<n;i++){
            int k=1;
            double maxW=-1;
            for(int j=1;j<=n;j++){
                if(existed[j]&&maxW<(double)w[j]/t[j]&&j!=r){
                    k=j;
                    maxW=(double)w[j]/t[j];
                }
            }
            for(int j=1;j<=n;j++)
                if(p[j]==k) p[j]=p[k];
            w[p[k]]+=w[k];
            c[p[k]]+=t[p[k]]*w[k]+c[k];
            t[p[k]]+=t[k];
            existed[k]=false;
        }
        int ret=c[r];
        cout<<ret<<endl;
    }
    return 0;
}
