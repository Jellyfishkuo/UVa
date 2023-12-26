#include <bits/stdc++.h>
#define maxn 200000+5
using namespace std;

int s,len;
bool vaildBackward[maxn],vaildForward[maxn];
int cnt[maxn],seq[maxn];

void solve(){
    memset(cnt,0,sizeof(cnt));
    memset(vaildBackward,0,sizeof(vaildBackward));
    memset(vaildForward,0,sizeof(vaildForward));
    int diffNum=0,ans=0;
    for(int i=0;i<len+s;i++){
        if(i-s+1>=0&&diffNum==s) vaildBackward[i-s]=true;
        if(i-s>=0){
            cnt[seq[i-s]]--;
            if(cnt[seq[i-s]]==0) diffNum--;
        }
        if(i>=len) diffNum++;
        else{
            if(cnt[seq[i]]==0) diffNum++;
            cnt[seq[i]]++;
        }
        if(i<s&&diffNum==i+1) vaildForward[i]=true;
    }
    for(int i=0;i<s;i++){
        int ok=1;
        if(i!=0&&!vaildForward[i-1]) continue;
        for(int j=i;j<len&&ok;j+=s)
            if(!vaildBackward[j]) ok=0;
        ans+=ok;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s>>len;
        for(int i=0;i<len;i++) cin>>seq[i];
        solve();
    }
    return 0;
}
