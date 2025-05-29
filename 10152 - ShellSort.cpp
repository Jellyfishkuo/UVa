#include <bits/stdc++.h>
using namespace std;

int t,n;
string s;
    
int main() 
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        getline(cin,s);
        string target[n],source[n];
        for(int i=0;i<n;i++) getline(cin,source[i]);
        for(int i=0;i<n;i++) getline(cin,target[i]);
        int pt=n-1,ps=n-1;
        while(ps>=0)
        {
            if (source[ps]==target[pt]) pt--;
            ps--;
        }
        while(pt>=0) cout<<target[pt--]<<"\n";
        cout<<"\n";
    }
    return 0;
}

/*
2
3
Yertle
Duke of Earl
Sir Lancelot
Duke of Earl
Yertle
Sir Lancelot
9
Yertle
Duke of Earl
Sir Lancelot
Elizabeth Windsor
Michael Eisner
Richard M. Nixon
Mr. Rogers
Ford Perfect
Mack
Yertle
Richard M. Nixon
Sir Lancelot
Duke of Earl
Elizabeth Windsor
Michael Eisner
Mr. Rogers
Ford Perfect
Mack


*/
