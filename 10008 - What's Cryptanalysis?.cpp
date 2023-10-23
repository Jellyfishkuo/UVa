#include<bits/stdc++.h>
using namespace std;

struct data{
    char index;
    int num;
    bool operator<(const data &rhs)const{
        if(num==rhs.num) return index<rhs.index;
        return num>rhs.num;
    }
};

int main(){
    int n;
    data arr[50];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<26;i++) arr[i].index=i+'A';
    cin>>n>>ws;
    while(n--){
        string s;
        getline(cin,s);
        transform(s.begin(),s.end(),s.begin(),::toupper);
        for(int i=0;i<s.size();i++)
            if(s[i]>='A'&&s[i]<='Z') arr[s[i]-'A'].num++;
    }
    sort(arr,arr+26);
    for(int i=0;i<26;i++)
        if(arr[i].num) cout<<arr[i].index<<" "<<arr[i].num<<endl;

    return 0;
}
