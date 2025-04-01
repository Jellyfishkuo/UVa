#include <bits/stdc++.h>
#define maxn 10010
using namespace std;

typedef pair<int,int> Pair;
int num[maxn];

// 區間[l,r]內前一半數字與後一半數字對調
void change(int l,int r)
{
    for(int i=l,j=l+(r-l+1)/2;j<=r;i++,j++)
        swap(num[i],num[j]);
}

int t,n;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>num[i];
        vector<pair<int,int>> ans;
        for(int i=1;i<=n;i++)
        {
            int pos;
            for(int j=i;j<=n;j++)
            {
                if(num[j]==i)
                {
                    pos=j;
                    break;
                }
            }
            if(pos==i) continue;
            if(i+2*(pos-i)-1<=n)
            {
                ans.push_back(Pair(i,i+2*(pos-i)-1));
                change(i,i+2*(pos-i)-1);
            }
            else
            {
                if((pos-i)%2)
                {
                    ans.push_back(Pair(i,pos));
                    change(i,pos);
                }
                else
                {
                    ans.push_back(Pair(i+1,pos));
                    change(i+1,pos);
                }
                i--;
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}


/*
2
6
5 4 6 3 2 1
5
1 2 3 4 5

*/
