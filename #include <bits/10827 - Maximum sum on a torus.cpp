#include <bits/stdc++.h>
#define maxn 150+10
using namespace std;

int n;
int arr[maxn][maxn],sum[maxn][maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>arr[i][j];
                arr[i+n][j]=arr[i][j+n]=arr[i+n][j+n]=arr[i][j];
                //擴展矩陣以處理環狀矩陣，將原始矩陣複製到右邊、下方和右下方。
            }
        }
        for(int i=1;i<=(n<<1);i++)
            for(int j=1;j<=(n<<1);j++)
                sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+arr[i][j];
                //使用動態規劃，sum[i][j] 表示從 (1,1) 到 (i,j) 的子矩陣和。
        int result=INT_MIN;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=i;k<i+n;k++)
                    for(int l=j;l<j+n;l++)
                        result=max(result,sum[k][l]-sum[i-1][l]-sum[k][j-1]+sum[i-1][j-1]);
        cout<<result<<endl;
    }
    return 0;
}
