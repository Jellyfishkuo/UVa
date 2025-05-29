#include <bits/stdc++.h>
#define maxn 100005
#define INF 0x3f3f3f3f
using namespace std;

int x[maxn],y[maxn];
int d2o[maxn],total_dist[maxn],total_weight[maxn];
int d[maxn];

int f(int j)
{
    return d[j]-total_dist[j+1]+d2o[j+1];
}

int cas,c,n,w;

int main()
{
    cin>>cas;
    while(cas--)
    {
        cin>>c>>n;
        total_dist[0]=total_weight[0]=x[0]=y[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i]>>y[i]>>w;
            d2o[i]=abs(x[i])+abs(y[i]);                                        // 到原點距離
            total_dist[i]=total_dist[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);   // 總距離
            total_weight[i]=total_weight[i-1]+w;                               // 總重量
        }
        deque<int> q;
        q.push_back(0);
        for(int i=1;i<=n;i++)
        {
            while(!q.empty()&&(total_weight[i]-total_weight[q.front()]>c))     // 如果從 q.front() 到目前 i 的總重量 > 背包容量 c，就不能從那裡轉移來
                q.pop_front();                                                 // 所以把它從佇列前面移除
            d[i]=f(q.front())+total_dist[i]+d2o[i];                            // 在 j 時的最佳狀態，加上從 j+1 到 i 的距離與花費
            while(!q.empty()&&(f(q.back())>=f(i)))                             // 保持佇列中 f(j) 單調遞增（或至少不會比 i 好）
                q.pop_back();                                                  // 因為 f(i) 越小越好，所以把不如它的通通踢掉
            q.push_back(i);                                                    // q.front() 永遠是「最小的 f(j)」
        }
        cout<<d[n]<<endl;
        if(cas) cout<<endl;
    }
    return 0;
}


/*
2

10
4
1 2 3
1 0 3
3 1 4
3 1 4

10
4
1 2 3
1 0 3
3 1 4
3 1 4

*/
