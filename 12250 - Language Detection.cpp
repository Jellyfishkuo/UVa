#include<bits/stdc++.h>
using namespace std;

int cnt;
string s;

int main()
{
    while(cin>>s)
    {
        if(s=="#") break;
        cout<<"Case "<<++cnt<<": ";
        if(s=="HELLO") cout<<"ENGLISH\n";
        else if(s=="HOLA") cout<<"SPANISH\n";
        else if(s=="HALLO") cout<<"GERMAN\n";
        else if(s=="BONJOUR") cout<<"FRENCH\n";
        else if(s=="CIAO") cout<<"ITALIAN\n";
        else if(s=="ZDRAVSTVUJTE") cout<<"RUSSIAN\n";
        else cout<<"UNKNOWN\n";
    }
}
