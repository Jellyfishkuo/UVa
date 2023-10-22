#include<bits/stdc++.h>
using namespace std;

int c,n,t,s;
struct data{
    double price;
    int index;
    bool operator<(const data&rhs)const{
        return price>rhs.price;
    }
};

int main(){
    cin>>c;
    while(c--){
        cin>>n;
        data arr[n];
        for(int i=0;i<n;i++){
            cin>>t>>s;
            arr[i].price=1.0*s/t;
            arr[i].index=i+1;
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            cout<<arr[i].index;
            if(i<n-1) cout<<" ";
            else cout<<endl;
        }
        if(c) cout<<endl;
    }
    return 0;
}
