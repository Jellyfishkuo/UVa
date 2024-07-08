#include<bits/stdc++.h>
#define maxn 30
using namespace std;

int p[maxn],t;
string s;

int Find(int x){
    return x==p[x]?x:p[x]=Find(p[x]);
}

int main(){
    cin>>t;
    cin.ignore();
    cin.ignore();
    while(t--){
        getline(cin,s);
        int cnt=s[0]-'A'+1;
        for(int i=0;i<cnt;i++) p[i]=i;
        while(getline(cin,s)){
            if(s[0]=='\0') break;
            int a=s[0]-'A',b=s[1]-'A';
            int pa=Find(a),pb=Find(b);
            if(pa!=pb){
                p[pb]=pa;
                cnt--;
            }
        }
        cout<<cnt<<endl;
        if(t) cout<<endl;
    }
    return 0;
}




/*

2

E
AB
CE
DB
EC

E
AB
CE
DB
EC

*/
