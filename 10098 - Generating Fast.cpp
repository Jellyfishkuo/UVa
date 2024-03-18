#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        sort(s.begin(),s.end());
        cout<<s<<endl;
        while(next_permutation(s.begin(),s.end()))
            cout<<s<<endl;
        cout<<endl;
    }
    return 0;
}
