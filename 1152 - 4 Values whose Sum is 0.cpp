#include <bits/stdc++.h>
#define maxn 4005
#define int long long
using namespace std;

int A[maxn],B[maxn],C[maxn],D[maxn];
int sums[maxn*maxn];
int t,n,c,cnt;

main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>A[i]>>B[i]>>C[i]>>D[i];
        c=0,cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                sums[c++]=A[i]+B[j];
        sort(sums,sums+c);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cnt+=upper_bound(sums,sums+c,-C[i]-D[j])-lower_bound(sums,sums+c,-C[i]-D[j]);
        cout<<cnt<<endl;
        if(t) cout<<endl;
    }
    return 0;
}
