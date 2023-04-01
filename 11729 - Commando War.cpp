#include <bits/stdc++.h>
#define maxn 10000+5
using namespace std;

struct job{
    int b;
    int j;
    bool operator<(const job&a)const{
        return j>a.j;
    }
};

int main(){
    int n,cnt=0;
    while(cin>>n,n){
        job arr[maxn];
        int ans=0,btime=0;
        for(int i=0;i<n;i++) cin>>arr[i].b>>arr[i].j;
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            btime+=arr[i].b;
            ans=max(ans,btime+arr[i].j);
        }
        cout<<"Case "<<++cnt<<": "<<ans<<endl;
    }
    return 0;
}
