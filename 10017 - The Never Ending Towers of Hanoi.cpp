#include <bits/stdc++.h>
#define max_disks 251
#define max_pegs 4
using namespace std;

int disk,lastmove,steps;
bool pegs[max_pegs][max_disks],stepsreached;

void print()
{
    if(steps>lastmove)
    {
        stepsreached=true;
        return;
    }
    cout<<endl;
    for(int i=1;i<=3;i++)
    {
        cout<<(char)('A'+i-1)<<"=>";
        bool printspace=0;
        for(int j=disk;j>=1;j--)
        {
            if(pegs[i][j])
            {
                if(printspace==0)
                {
                    cout<<"  ";
                    printspace=1;
                }
                cout<<" "<<j;
            }
        }
        cout<<endl;
    }
    steps++;
}

void move(int n,int from,int mid,int to)
{
    pegs[from][n]=0;
    pegs[to][n]=1;
    print();
}

void hanoi(int n,int from,int mid,int to)
{
    if(stepsreached) return;
    if(n==1)
    {
        move(n,from,mid,to);
        return;
    }
    else
    {
        hanoi(n-1,from,to,mid);
        move(n,from,mid,to);
        hanoi(n-1,mid,from,to);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cas=1;
    bool case_1=0;
    while(cin>>disk>>lastmove&&disk||lastmove)
    {
        if(case_1) cout<<endl;
        else case_1=1;
        cout<<"Problem #"<<cas++<<endl;
        steps=0;
        stepsreached=0;
        for(int i=1;i<max_pegs;i++)
            for(int j=1;j<=disk;j++)
                pegs[i][j]=0;
        for(int i=1;i<=disk;i++) pegs[1][i]=1;
        print();
        hanoi(disk,1,2,3);
    }
    cout<<endl;
    return 0;
}


/*
64 2
8 45
0 0

*/
