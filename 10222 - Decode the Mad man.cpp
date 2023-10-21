#include<bits/stdc++.h>
using namespace std;

int main(){
    string keyboard="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    string s;
    int index;
    getline(cin,s);
    transform(s.begin(),s.end(),s.begin(),::tolower);
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            cout<<" ";
            continue;
        }
        index=keyboard.find(s[i])-2;
        cout<<keyboard[index];
    }
    cout<<endl;
    return 0;
}
