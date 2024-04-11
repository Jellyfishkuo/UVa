#include <bits/stdc++.h>
#define maxn 1000+5
using namespace std;


int solve(int n,int arr[]){
    int b[maxn];
    int ret=0x3f3f3f3f;
    for(int i=0,j=n;i<n;i++,j++) arr[j]=arr[i];
    for(int i=0;i<n;i++){              // 找 a[i],a[i+1],…,a[i+n-1](暫存在b陣列中) 的最少交換次數
        int mark[maxn],cnt=0;          // mark 陣列作為查表之用
        for(int j=0;j<n;j++){          // 填值到 mark 與 b 陣列中
            mark[arr[i+j]]=i+j;
            b[i+j]=arr[i+j];
        }
        for(int j=0;j<n;j++){          // 要讓 j 值在 b 陣列中就定位
            if(b[i+j]!=j){             // j 值尚未定位
                cnt++;                 // cnt 存 a[i],a[i+1],…,a[i+n-1] 需要交換的次數
                int idx=mark[j];       // j 值在 b 陣列的 mark[j](=idx) 位置中
                swap(b[i+j],b[idx]);
                mark[b[idx]]=idx;
            }
        }
        ret=min(ret,cnt);              // 更新交換最小值
    }
    return ret;
}

int n;
int arr[maxn];

int main(){
    while(cin>>n,n){
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr[i]--;
        }
        int ret;
        ret=solve(n,arr);               // 順時針順序找最小交換次數
        reverse(arr,arr+n);             // 逆時針排列輸入資料 arr 陣列內容
        ret=min(ret,solve(n,arr));      // 逆時針順序找最小交換次數，並更新答案
        cout<<ret<<endl;
    }
    return 0;
}
