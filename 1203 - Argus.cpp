#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Item{
    int id,p,pp;
    bool operator<(const Item &rhs)const{
        return pp>rhs.pp||(pp==rhs.pp&&id>rhs.id);
    }
};

priority_queue<Item> a;

string s;
int id,p,n;

main(){
    while(cin>>s){
        if(s=="#") break;
        cin>>id>>p;
        a.push({id,p,p});
    }
    cin>>n;
    for(int i=0;i<n;i++){
        Item t=a.top();
        a.pop();
        cout<<t.id<<endl;
        t.pp+=t.p;
        a.push(t);
    }
    return 0;
}
