#include <bits/stdc++.h>
using namespace std;

int cas,n,w,h,y[105],len;

struct point{
    int x,y;
};

bool cmp(point a,point b) {
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

point p[105];

void solve(){
    sort(p,p+n,cmp);
    sort(y,y+n+2);
    len=unique(y,y+n+2)-y;
    int ansx,ansy,ans=-1,hh,ww;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            hh=y[j]-y[i];
            int nowx=0;
            for(int k=0;k<n;k++){
                if(p[k].y<=y[i]||p[k].y>=y[j]) continue;
                ww=p[k].x-nowx;
                ww=min(ww,hh);
                if(ans<ww){
                    ansx=nowx;
                    ansy=y[i];
                    ans=ww;
                }
                nowx=p[k].x;
            }
            ww=w-nowx;
            ww=min(ww,hh);
            if(ans<ww){
                ansx=nowx;
                ansy=y[i];
                ans=ww;
            }
        }
    }
    cout<<ansx<<" "<<ansy<<" "<<ans<<"\n";
    if(cas) cout<<endl;
}

int main(){
    cin>>cas;
    while(cas--){
        cin>>n>>w>>h;
        for(int i=0;i<n;i++){
            cin>>p[i].x>>p[i].y;
            y[i]=p[i].y;
        }
        y[n]=0;
        y[n+1]=h;
        solve();
    }
    return 0;
}
