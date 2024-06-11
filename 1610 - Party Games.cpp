#include <bits/stdc++.h>
#define maxn 1000+5
using namespace std;

int n;
string a[maxn];

string solve(int n){
    string x=a[(n-2)/2];
    string y=a[n/2];
    string ans="A";
    for(int i=0;i<x.size();i++){
        while(ans[i]<='Z'&&ans<x) ++ans[i];
        if(ans[i]<='Z'&&ans>=x&&ans<y) return ans;
        if(x[i]!=ans[i]) --ans[i];
        ans+='A';
    }
}

int main(){
    while(cin>>n,n){
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        cout<<solve(n)<<endl;
    }
    return 0;
}
