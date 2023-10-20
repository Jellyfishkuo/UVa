#include<bits/stdc++.h>
#define int long long
using namespace std;

main(){
    string s;
    while(cin>>s){
        int cnt=0;
        if(s=="0") break;
        else{
            for(int i=0;i<s.size();i++){
                if(i%2) cnt+=s[i]-'0';
                else cnt-=s[i]-'0';
            }
        }
        if(abs(cnt)%11) cout<<s<<" is not a multiple of 11.\n";
        else cout<<s<<" is a multiple of 11.\n";
    }
}
