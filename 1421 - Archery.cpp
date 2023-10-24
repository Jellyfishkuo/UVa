#include<bits/stdc++.h>
using namespace std;

const int N=5005;
const double esp=1e-6;

int n,t;
double w;

struct Seg{
    double d,l,r;
    bool operator<(const Seg &rhs)const{
        return d<rhs.d;
    }
}s[N];

int judge(double x) {
	double L=atan2(s[0].d,s[0].r-x);
	double R=atan2(s[0].d,s[0].l-x);
	for(int i=1;i<n;i++) {
		double l=atan2(s[i].d,s[i].r-x);
		double r=atan2(s[i].d,s[i].l-x);
		if(L-r>esp) return -1;
		if(l-R>esp) return 1;
		L=max(L,l);
		R=min(R,r);
	}
	return 0;
}

bool solve(){
    sort(s,s+n);
    double l=0,r=w;
    while(r-l>esp){
        double mid=(l+r)/2;
        int k=judge(mid);
        if(k==0) return true;
        else if(k==-1) r=mid;
        else l=mid;
    }
    return false;
}


int main(){
    cin>>t;
    while(t--){
        cin>>w>>n;
        for(int i=0;i<n;i++) cin>>s[i].d>>s[i].l>>s[i].r;
        cout<<(solve()?"YES\n":"NO\n");
    }
    return 0;
}
