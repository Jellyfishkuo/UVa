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
    for(int k=0;k<n;k++)
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
        int m=unique(xx,xx+n*2)-xx;
        if(cas++) cout<<endl;
        cout<<"For map #"<<cas<<", the visible buildings are numbered as follows:\n"<<b[0].id;
        for(int i=1;i<n;i++){
            bool vis=false;
            for(int j=0;j<m-1;j++)
                if(visible(i,(xx[j]+xx[j+1])/2)){
                    vis=true;
                    break;
                }
            if(vis) cout<<" "<<b[i].id;
        }
        cout<<endl;
    }
    return 0;
}
