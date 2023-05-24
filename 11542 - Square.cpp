#include<bits/stdc++.h>
#define maxn 505
using namespace std;

int A[maxn][maxn];
int prime[maxn],visited[maxn];

int sieve(int n){
    memset(visited,0,sizeof(visited));
    int i,j,k=0,m;
    m=(int)sqrt(n);
    for(i=2;i<=m;i++)
        for(j=i*i;j<=n;j+=i)
            visited[j]=1;
    for(i=2;i<=n;i++)
        if(!visited[i])
            prime[k++]=i;
    return k;
}

int gaussian_elimination(int m,int n){
    int i,j,k,r,u;
    i=j=0;
    while(i<m&&j<n){
        r=i;
        for(k=i;k<m;k++)
            if(A[k][j]){
                r=k;
                break;
            }
        if(A[k][j]){
            if(r!=i)
                for(k=0;k<=n;k++)
                    swap(A[r][k],A[i][k]);
            for(u=i+1;u<m;u++)
                if(A[u][j])
                    for(k=i;k<=n;k++)
                        A[u][k]^=A[i][k];
            i++;
        }
        j++;
    }
    return n-i;
}

int main(){
    int m,Case;
    m=sieve(maxn);
    cin>>Case;
    while(Case--){
        memset(A,0,sizeof(A));
        int n,i,j,maxp=0,free_var;
        long long x;
        cin>>n;
        memset(A,0,sizeof(A));
        for(i=0;i<n;i++){
            cin>>x;
            for(j=0;j<m;j++){
                while((x%prime[j])==0){
                    maxp=max(maxp,j);
                    x=x/prime[j];
                    A[j][i]^=1;
                }
            }
        }
        free_var=gaussian_elimination(maxp+1,n);
        cout<<((1LL<<free_var)-1)<<endl;
    }
    return 0;
}
