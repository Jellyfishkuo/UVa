#include<bits/stdc++.h>
using namespace std;

int cmp(string s1,string s2){
    int cnt=0;
    for(int i=0;i<3;i++)
        if(s1[i]==s2[i]) cnt++;
    return (cnt>=2);
}

int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s.size()==5) cout<<3<<endl;
        else {
            if(cmp(s,"one")) cout<<1<<endl;
            if(cmp(s,"two")) cout<<2<<endl;
        }
    }
}
