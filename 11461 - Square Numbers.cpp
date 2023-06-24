#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b,a+b){
        int cnt=0,x=sqrt(a);
        for(int i=a;i<=b;i++){
            if(x*x>=a)
                if(x*x<=b) cnt++;
                else break;
            x++;
        }
        cout<<cnt<<endl;
    }
}
