#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int n;

int f(vector<int> &v){
    int vs=v.size();
    for(int s=v.size()-1;s>=0;s--)
        for(int i=0;i<vs;i++)
            for(int j=i+1;j<vs;j++)
                for(int k=j+1;k<vs;k++)
                    if(v[i]+v[j]+v[k]==v[s]&&i!=s&&j!=s&&k!=s)
                        return v[s];
    return INT_MAX;
}
int main(){
    ios::sync_with_stdio();
    cin.tie(0),cout.tie(0);
    while(cin>>n,n){
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        int ans=f(arr);
        if(ans==INT_MAX) cout<<"no solution\n";
        else cout<<ans<<endl;
    }
    return 0;
}
