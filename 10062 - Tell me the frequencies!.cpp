#include<bits/stdc++.h>
using namespace std;

struct data{
    int name;
    int num;
    bool operator<(const data &rhs)const{
        return num==rhs.num&&name>rhs.name||num<rhs.num;
    }
};

int main(){
    string s;
    int blank=0;
    while(getline(cin,s)){
        if(blank) cout<<endl;
        data arr[500]={};
        for(int i=0;i<s.size();i++){
            arr[(int)s[i]].num++;
            arr[(int)s[i]].name=(int)s[i];
        }
        sort(arr,arr+500);
        for(int i=0;i<500;i++){
            if(arr[i].num)
                cout<<(int)(arr[i].name)<<" "<<arr[i].num<<endl;
        }
        blank++;
    }
    return 0;
}


/*
AAABBC
122333

*/
