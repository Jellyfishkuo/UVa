#include <bits/stdc++.h>
#define maxn 23+5
using namespace std;

int SG[maxn];
int visited[1000+5];
int pile[maxn],ans;

void calculateSG(){
    SG[0]=0;
    for(int i=1;i<=maxn;i++){
        int cur=0;
        for(int j=0;j<i;j++)
            for(int k=0;k<=j;k++)
                visited[SG[j]^SG[k]]=i;
        while(visited[cur]==i) cur++;
        SG[i]=cur;
    }
}

int main(){
    calculateSG();
    int Case=0,n;
    while(cin>>n,n){
        ans=0;
        for(int i=1;i<=n;i++) cin>>pile[i];
        for(int i=1;i<=n;i++) if(pile[i]&1) ans^=SG[n-i];
        cout<<"Game "<<++Case<<": ";
        if(!ans) cout<<"-1 -1 -1\n";
        else{
            bool flag=0;
            for(int i=1;i<=n;i++){
                if(pile[i]){
                    for(int j=i+1;j<=n;j++){
                        for(int k=j;k<=n;k++){
                            if((SG[n-i]^SG[n-j]^SG[n-k])==ans){
                                cout<<i-1<<" "<<j-1<<" "<<k-1<<endl;
                                flag=1;
                                break;
                            }
                        }
                        if(flag) break;
                    }
                    if(flag) break;
                }
            }
        }
    }
    return 0;
}
