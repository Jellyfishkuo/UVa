#include <bits/stdc++.h>
using namespace std;

int cas,n,w,h,line[105],len;

struct point{
    int x,y;
};
bool cmp(point a,point b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

point p[105];

void solve(){
    sort(p,p+n,cmp);
    sort(line,line+n+2);
    len=unique(line,line+n+2)-line;
    int ansx,ansy,ans=-1,hh,ww;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            hh=line[j]-line[i];
            int nowx=0;
            for(int k=0;k<n;k++){
                if(p[k].y<=line[i]||p[k].y>=line[j]) continue;
                ww=p[k].x-nowx;  // ww: 目前小區域矩形的寬度
                ww=min(ww,hh);   // ww: 設定為小區域內最大正方形的邊長
                if(ans<ww){      // 如果目前的正方形邊長(ww)最大
                    ansx=nowx;
                    ansy=line[i];
                    ans=ww;      // 則更新正方形位置(ansx,ansy)與邊長ans
                }
                nowx=p[k].x;     // 設定下一條垂直掃描線為x=p[k].x
            }
            ww=w-nowx;
            ww=min(ww,hh);       // 處理掃描區間x=nowx至x=w
            if(ans<ww){
                ansx=nowx;
                ansy=line[i];
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
            line[i]=p[i].y;
        }
        line[n]=0;
        line[n+1]=h;
        solve();
    }
    return 0;
}
