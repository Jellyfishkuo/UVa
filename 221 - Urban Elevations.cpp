#include <bits/stdc++.h>
#define maxn 105
using namespace std;

struct building{
    int id;
    double x,y,w,d,h;
    bool operator<(const building &rhs)const{
        return x<rhs.x||(x==rhs.x&&y<rhs.y);
    }
};


int n;
double xx[maxn*2];
building b[maxn];

bool cover(int i,double mx){
    return b[i].x<=mx&&mx<=b[i].x+b[i].w;
}

bool visible(int i,double mx){
    if(!cover(i,mx)) return false;
    for(int k=0;k<n;k++)                   // 檢查所有的建築物在 mx 處是否遮住建築物 b[i]
        if(b[k].y<b[i].y&&b[k].h>=b[i].h&&cover(k,mx)) return false;
    return true;
}

int main(){
    int cas=0;
    while(cin>>n,n){
        for(int i=0;i<n;i++) {
            cin>>b[i].x>>b[i].y>>b[i].w>>b[i].d>>b[i].h;
            xx[i*2]=b[i].x;
            xx[i*2+1]=b[i].x+b[i].w;
            b[i].id=i+1;
        }
        sort(b,b+n);
        sort(xx,xx+n*2);
        int m=unique(xx,xx+n*2)-xx;         // x 座標排序後去掉重複的，得到 m 個不同的 x 座標
        if(cas++) cout<<endl;
        cout<<"For map #"<<cas<<", the visible buildings are numbered as follows:\n"<<b[0].id;
        for(int i=1;i<n;i++){
            bool vis=false;
            for(int j=0;j<m-1;j++){         // m 個不同的 x 座標存於陣列 xx，檢驗 m-1 個相鄰 2 個 x 值中點處，看看建築物 b[i] 是否看的見
                if(visible(i,(xx[j]+xx[j+1])/2)){
                    vis=true;
                    break;                  // 只要有一處看的見就停止檢驗建築物 b[i]
                }
            }
            if(vis) cout<<" "<<b[i].id;     // 看到了建築物 b[i]，輸出建築物編號 b[i].id
        }
        cout<<endl;
    }
    return 0;
}
