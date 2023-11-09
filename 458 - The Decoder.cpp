#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        for(int i=0;i<s.size();i++)
            cout<<(char)(s[i]-('1'-'*'));
        cout<<endl;
    }
	return 0;
}
