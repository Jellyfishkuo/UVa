#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, word;
    stringstream ss;
    bool space;
    while(getline(cin,s)){
        ss.clear();
        ss.str(s);
        space=false;
        while(ss>>word){
            if(space) cout<<" ";
            space=true;
            for(int i=word.size()-1;i>=0;i--)
                cout<<word[i];
        }
        cout<<endl;
    }
    return 0;
}
