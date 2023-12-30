#include <bits/stdc++.h>
#define int long long
#define maxn 1500+5
using namespace std;

main(){
    int num[maxn]={1};
    int n2=0,n3=0,n5=0;
    for(int i=1;i<maxn;i++){
        for(;n2<i;n2++)
            if(num[n2]*2>num[i-1]) break;
        for(;n3<i;n3++)
            if(num[n3]*3>num[i-1]) break;
        for(;n5<i;n5++)
            if(num[n5]*5>num[i-1]) break;
        num[i]=min({num[n2]*2,num[n3]*3,num[n5]*5});
    }
    cout<<"The 1500'th ugly number is "<<num[1499]<<".\n";
    return 0;
}
