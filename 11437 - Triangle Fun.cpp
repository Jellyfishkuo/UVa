#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	double ax,ay,bx,by,cx,cy,ans,u,v;
	while(n--){
		cin>>ax>>ay>>bx>>by>>cx>>cy;
		u=(bx-ax)*(cy-ay),v=(by-ay)*(cx-ax);
		ans=fabs(u-v)/2;
		cout<<fixed<<setprecision(0)<<ans/7<<endl;
	}
}
