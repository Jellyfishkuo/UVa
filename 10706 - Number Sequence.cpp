#include <bits/stdc++.h>
#define int long long
using namespace std;

main(){
    int n;
    cin>>n;
    while(n--){
        string s="";
        int x,i=1;
        cin>>x;
        while(s.size()<x){
            x-=s.size();
            s+=to_string(i++);
        }
        cout<<s[x-1]<<endl;
    }
    return 0;
}
