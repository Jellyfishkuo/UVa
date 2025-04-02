#include <bits/stdc++.h>
#define maxn 100100
#define INF 1000010
#define eps 1e-9
using namespace std;

int n;

struct point
{
    double l,r;
}a[maxn];

bool cmp(point a,point b)
{
    return a.l<b.l;
}

bool judge(double l)
{
    int f=1;                      //flag
    double s=0;                   //起始點
    for(int i=0;i<n&&f;i++)       //由左至右掃描
    {
        if(s<a[i].l)              //s在a[i]最左端的左邊
        {
            if(a[i].l+l<=a[i].r)  //如果區間長度可行
            {
                s=a[i].l+l;       //更新起始點
                continue;         //繼續檢查
            }
            else f=0;             //不可行，結束迴圈
        }
        else                      //s在a[i]最左端的右邊
        {
            if(s+l<=a[i].r)       //沒超過右界
            {
                s+=l;             //更新起始點
                continue;         //繼續檢查
            }
            else f=0;             //不可行，結束迴圈
        }
    }
    return f;
}

int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++) cin>>a[i].l>>a[i].r;
        sort(a,a+n,cmp);
        double L=0,R=INF;
        while(R-L>eps)
        {
            double mid=(R+L)/2;
            if(judge(mid)) L=mid;
            else R=mid;
        }
        double ans=L;
        int rp=0,rq=1;
        for(int p,q=1;q<=n;++q)
        {
            p=round(ans*q);
            if(fabs((double)p/q-ans)<fabs((double)rp/rq-ans))
            {
                rp=p;
                rq=q;
            }
        }
        cout<<rp<<"/"<<rq<<endl;
    }
    return 0;
}


/*
3
2 6
1 4
8 12

*/
