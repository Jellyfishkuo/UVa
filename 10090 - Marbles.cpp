#include<bits/stdc++.h>
#define int long long
using namespace std;

int extend_gcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    int g = extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return g;
}

int n,c1,c2,n1,n2;

main(){
    while(cin>>n,n){
        cin>>c1>>n1>>c2>>n2;
        int x,y;
        int g=extend_gcd(n1,n2,x,y);
        int downk=ceil(1.0*(-n)*x/n2);
        int upk=floor(1.0*n*y/n1);
        if(downk>upk||n%g){
            cout<<"failed\n";
            continue;
        }
        if(c1*n2<c2*n1){
            x=n*x/g+n2/g*upk;
            y=n*y/g-n1/g*upk;
        }
        else{
            x=n*x/g+n2/g*downk;
            y=n*y/g-n1/g*downk;
        }
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}
