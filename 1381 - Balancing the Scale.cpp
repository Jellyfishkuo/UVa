#include <bits/stdc++.h>
#define int long long
using namespace std;

int num[16];
const int M = 12000;
const int N = (1<<16);
vector<int> state[M];
int cnt[N], x[16];

void init(){
    sort(num,num+16);
    for(int i=0;i<M;i++) state[i].clear();
    memset(cnt,0,sizeof(cnt));
}
bool judge(int s){
    int count=0;
    for(int i=0;i<16;i++)
        if(s & 1<<i) x[count++]=num[i];
    return count==4;
}

int solve(){
    int t,ans=0;
    for(int i=0;i<N;i++){
        if(judge(i))
            do{
                t=x[0]*4+x[1]*3+x[2]*2+x[3];
                for(int k=0; k<state[t].size(); k++)
                    if((state[t][k] & i)==0) cnt[state[t][k]|i]++;
                state[t].push_back(i);
            } while(next_permutation(x, x+4));
    }
    for(int i=0;i<N;i++) ans+=cnt[i]*cnt[i^(N-1)];
    return ans/2;
}


main(){
    int cas=1;
    while(cin>>num[0],num[0]){
        for(int i=1;i<16;i++) cin>>num[i];
        init();
        cout<<"Case "<<cas++<<": "<<solve()<<endl;
    }
    return 0;
}
