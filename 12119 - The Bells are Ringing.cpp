#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1e6+5;
int total,num[maxn];
int primecnt,prime[maxn],vis[maxn];
int factorcnt,factor[maxn],cnt[maxn];

int GCD(int a,int b){
    if(b==0) return a;
    return GCD(b,a%b);
}

int LCM(int a,int b){
    int k=GCD(a,b);
    return a/k*b;
}

void p(int n){
    primecnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=n;i++)
        if(!vis[i]){
            for(int j=i*i;j<=n;j+=i) vis[j]=1;
            prime[primecnt++]=i;
        }
}

void find_factor(int n){
    factorcnt=0;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<primecnt;i++){
        if(n%prime[i]==0){
            factor[factorcnt]=prime[i];
            while(n%prime[i]==0){
                n/=prime[i];
                cnt[factorcnt]++;
            }
            factorcnt++;
        }
    }
    if(n>1){
        factor[factorcnt]=n;
        cnt[factorcnt++]=1;
    }
}

void dfs(int d,int p){
    if(p>1e6) return ;
    if(d==factorcnt){
        num[total++]=p;
        return;
    }
    for(int i=0;i<=cnt[d];i++){
        dfs(d+1,p);
        p*=factor[d];
    }
}

main(){
    int t,cas=1;
    p(maxn);
    while(cin>>t,t){
        int result=total=0;
        cout<<"Scenario "<<cas++<<":\n";
        find_factor(t);
        dfs(0,1);
        sort(num,num+total);
        for(int i=0;i<total;i++){
            for(int j=i+1;j<total;j++){
                if(num[j]-num[i]>25) break;
                int d=LCM(num[i],num[j]);
                for(int k=j+1;k<total;k++){
                    if(num[k]-num[i]>25) break;
                    if(LCM(d,num[k])==t){
                        cout<<num[i]<<" "<<num[j]<<" "<<num[k]<<endl;
                        result++;
                    }
                }
            }
        }
        if(result==0) cout<<"Such bells don't exist\n";
        cout<<endl;
    }
    return 0;
}
