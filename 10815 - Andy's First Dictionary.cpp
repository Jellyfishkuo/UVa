#include <bits/stdc++.h>
using namespace std;

int main(){
    set<string> st;
    string s;
    char ch;
    while(cin.get(ch))
    {
        if(isalpha(ch)) s+=tolower(ch);
        else
        {
            if(!s.empty())
            {
                st.insert(s);
                s.clear();
            }
        }
    }
    if(!s.empty()) st.insert(s);
    for(auto& w:st) cout<<w<<endl;
    return 0;
}
