#include <bits/stdc++.h>
#define maxn 1000+5
using namespace std;
struct Point{
    int x,y;
    double rad;
    bool operator<(const Point &rhs)const{
        return rad<rhs.rad;
    }
}op[maxn],p[maxn];

int n,color[maxn];

bool Left(Point A,Point B){
    return A.x*B.y-A.y*B.x>=0;
}

int solve(){
    if(n<=2) return 2;
    int ans=0;
    for(int i=0;i<n;i++){
        int k=0;
        for(int j=0;j<n;j++)
            if(j!=i){
                p[k].x=op[j].x-op[i].x;
                p[k].y=op[j].y-op[i].y;
                if(color[j]){
                    p[k].x=-p[k].x;
                    p[k].y=-p[k].y;
                }
                p[k].rad=atan2(p[k].y,p[k].x);
                k++;
            }
        sort(p,p+k);
        int L=0,R=0,cnt=2;
        while(L<k){
            if(R==L){
                R=(R+1)%k;
                cnt++;
            }
            while(R!=L&&Left(p[L],p[R])){
                R=(R+1)%k;
                cnt++;
            }
            cnt--;
            L++;
            ans=max(ans,cnt);
        }
    }
    return ans;
}


int main() {
    while(cin>>n,n){
        for(int i=0;i<n;i++) cin>>op[i].x>>op[i].y>>color[i];
        cout<<solve()<<endl;
    }
    return 0;
}
