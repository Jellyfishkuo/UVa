#include <bits/stdc++.h>
#define int long long
using namespace std;

// 計算第 i 小時的紅球數：3^i
int c(int i){
    return i==0?1:c(i-1)*3;
}

// 計算第 k 小時從 row 1 至 row i 的紅球數：f(k,i)

// f(k,i) = 0                             if i==0
// f(k,i) = 1                             if i!=0 && k==0
// f(k,i) = 2*f(k-1,i)                    if i≦2^(k-1)
// f(k,i) = f(k-1,i-2^(k-1)) + 2*3^(k-1)  if i>2^(k-1)

int f(int k,int i){
    if(i==0) return 0;
    if(k==0) return 1;
    int k2=1<<(k-1);   // k2 = 2^(k-1)
    if(i>k2) return f(k-1,i-k2)+2*c(k-1);
    else return 2*f(k-1,i);
}

int t,k,a,b;

main(){
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cin>>k>>a>>b;
        cout<<"Case "<<cas<<": "<<f(k,b)-f(k,a-1)<<endl;
    }
    return 0;
}

/*

3
0 1 1
3 1 8
3 3 7

*/
