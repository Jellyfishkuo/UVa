#include<bits/stdc++.h>
using namespace std;

int w,n;
int dp[5000][50],v[50];

void print(int a[],int i,int j){
    if(i==0||j==0) return;
    if(dp[i][j]==dp[i][j-1]) print(a,i,j-1);
    else{
        print(a,i-a[j],j-1);
        cout<<a[j]<<" ";
    }
}

int main(){
    while(cin>>w){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>v[i];
        for(int i=1;i<=w;i++){
            for(int j=1;j<=n;j++){
                if(v[j]<=i) dp[i][j]=max(dp[i-v[j]][j-1]+v[j],dp[i][j-1]);
                else dp[i][j]=dp[i][j-1];
            }
        }
        print(v,w,n);
        cout<<"sum:"<<dp[w][n]<<endl;
    }
}
