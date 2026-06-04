#include <bits/stdc++.h>
using namespace std;

const int maxn = 305;
vector<int> G[maxn];
int n, color[maxn];

bool dfs(int u)
{
    for(int v : G[u])
    {
        if(!color[v])
        {
            color[v] = 3 - color[u];
            if(!dfs(v)) return false;
        }
        else if(color[u] == color[v]) return false;
    }
    return true;
}

int main()
{
    while(cin >> n, n)
    {
        for(int i = 0; i < n; i++) G[i].clear();
        int u, v;
        while(cin >> u >> v)
        {
            if(u == 0 && v == 0) break;
            v--, u--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(color, 0, sizeof(color));
        bool f = true;
        for(int i = 0; i < n; i++)
        {
            if(!color[i])
            {
                color[i] = 1;
                if(!dfs(i))
                {
                    f = false;
                    break;
                }
            }
        }
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
