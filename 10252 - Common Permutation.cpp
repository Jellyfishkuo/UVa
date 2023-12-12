#include<bits/stdc++.h>
using namespace std;

int arr[500],brr[500];

int main(){
    string a,b;
    while(getline(cin,a)){
        getline(cin,b);
        memset(arr,0,sizeof(arr));
        memset(brr,0,sizeof(brr));
        for(int i=0;i<a.size();i++) arr[(int)a[i]]++;
        for(int i=0;i<b.size();i++) brr[(int)b[i]]++;
        for(int i=0;i<500;i++){
            if(arr[i]&&brr[i]){
                int minn=min(arr[i],brr[i]);
                for(int j=0;j<minn;j++)
                    cout<<(char)i;
            }
        }
        cout<<endl;
    }
    return 0;
}
