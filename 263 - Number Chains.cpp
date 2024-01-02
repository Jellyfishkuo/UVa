#include<bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(char a,char b){
    return a>b;
}

main(){
    string s;
    while(cin>>s){
        if(s=="0") break;
        set<int> visited;
        cout<<"Original number was "<<s<<endl;
        while(1){
            sort(s.begin(),s.end(),cmp);
            int a=stoll(s);
            sort(s.begin(),s.end());
            int b=stoll(s);
            cout<<a<<" - "<<b<<" = "<<a-b<<endl;
            if(visited.find(a-b)!=visited.end()) break;
            visited.insert(a-b);
            s=to_string(a-b);
        }
        cout<<"Chain length "<<visited.size()+1<<endl<<endl;
    }
    return 0;
}
