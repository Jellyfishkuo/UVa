#include <bits/stdc++.h>
#define maxn 1505
using namespace std;

int t,a,b,c;
int ans[maxn];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        int len=0,pos=0;
        ans[len++]=0;
        if(c%3==0)
        {
            for(int i=0;i<c/3;i++) ans[len++]=(pos+=3);    // 首先向右用三站票c/3張
			ans[len++]=++pos;                              // 向右用一張一站票
			a--;
			for(int i=0;i<c/3;i++) ans[len++]=(pos-=3);    // 向左用三站票c/3張
			ans[len++]=++pos;                              // 向右用一張一站票
			a--;
			for(int i=0;i<c/3;i++) ans[len++]=(pos+=3);    // 向右用三站票c/3張
        }
        if(c%3==1)
        {
			for(int i=0;i<c/3+1;i++) ans[len++]=(pos+=3);  // 首先向右用三站票c/3+1張
			ans[len++]=(pos-=2);                           // 向左用一張二站票
			b--;
			for(int i=0;i<c/3;i++) ans[len++]=(pos-=3);    // 向左用三站票c/3張
			ans[len++]=(pos+=1);                           // 向右用一張一站票
			a--;
			for(int i=0;i<c/3;i++) ans[len++]=(pos+=3);    // 向右用三站票c/3 張
			ans[len++]=(pos+=2);                           // 向右用一張二站票
			b--;
		}
		if(c%3==2)
        {
			for(int i=0;i<c/3+1;i++) ans[len++]=(pos+=3);  // 首先向右用三站票c/3+1張
			ans[len++]=(pos-=1);                           // 向左用一張一站票
			a--;
			for(int i=0;i<c/3;i++) ans[len++]=(pos-=3);    // 向左用三站票c/3張
			ans[len++]=(pos-=1);                           // 向左用一張一站票
			a--;
			for(int i=0;i<c/3+1;i++) ans[len++]=(pos+=3);  // 向右用三站票c/3+1張
        }
        while(a-->1) ans[len++]=++pos;                     // 向右連續使用剩下的一站票到剩下一張
        for(int i=0;i<(b+1)/2;i++) ans[len++]=(pos+=2);    // 向右連續使用一半剩下的二站票
        if(b%2) ans[len++]=--pos;                          // 如果剩下的二站票是奇數,向左用一張一站票
        else ans[len++]=++pos;                             // 如果剩下的二站票是偶數,向右用一張一站票
        for(int i=b&1;i<(b+1)/2;i++) ans[len++]=(pos-=2);  // 向左連續使用一半剩下的二站票
        for(int i=0;i<len-1;i++) cout<<ans[i]<<" ";        // 輸出拜訪過程結果
		cout<<ans[len-1]<<endl;
    }
    return 0;
}


/*
2
3 3 3
3 4 3

*/
