#include<bits/stdc++.h>
#define maxn 1000+10
using namespace std;

struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
    bool operator<(const Point &rhs)const{
        return x<rhs.x||(x==rhs.x&&y<rhs.y);
    }
};

int main(){
    Point p[maxn];
    int t,n;
    set<Point> s;
    cin>>t;
    while(t--){
        int mx=INT_MIN,mn=INT_MAX,m;
        s.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>p[i].x>>p[i].y;
            p[i].x*=2;
            mn=min(mn,p[i].x);
            mx=max(mx,p[i].x);
            s.insert(p[i]);
        }
        m=(mn+mx)/2;
        bool ok=true;
        for(int i=0;i<n;i++){
            Point t(2*m-p[i].x,p[i].y);
            if(!s.count(t)){
                ok=false;
                break;
            }
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}
