#include <bits/stdc++.h>
using namespace std;

int n,cnt;
vector<int> a,ans;

void dfs(int s){
    if(ans.size()==6)
    {
        for(int i=0;i<6;i++)
        {
            if(i) cout<<" ";
            cout<<ans[i];
        }
        cout<<"\n";
        return;
    }

    for(int i=s;i<n;i++)
    {
        ans.push_back(a[i]);
        dfs(i+1);
        ans.pop_back();
    }
}

int main(){
    while(cin>>n,n)
    {
        if(cnt++) cout<<"\n";
        a.resize(n);
        for(int i=0;i<n;i++) cin>>a[i];
        ans.clear();
        dfs(0);
    }
    return 0;
}


/*
7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0

*/
