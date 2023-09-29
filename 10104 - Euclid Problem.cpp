#include<bits/stdc++.h>
using namespace std;

int x,y;
int gcd(int a,int b){
	if(b==0){
		x=1,y=0;
		return a;
	} 
	else{
		int ans=gcd(b,a%b);
		int tmp=y;
		y=x-a/b*y;
		x=tmp;
		return ans;
	}
}

int main(){
	int a,b;
	while(cin>>a>>b){
		int d=gcd(a,b);
		cout<<x<<" "<<y<<" "<<d<<endl;
	}
	return 0;
}
