#include<cstdio>
#include<algorithm>
#define maxn 100000+5
using namespace std;

int n,tower[maxn],left[maxn],right[maxn];

bool test(int p){
    int x=tower[1],y=p-x;
    left[1]=x;
    right[1]=0;
    for(int i=2;i<=n;i++){
        if(i%2){
            right[i]=min(y-right[i-1],tower[i]);
            left[i]=tower[i]-right[i];
        }
        else{
            left[i]=min(x-left[i-1],tower[i]);
            right[i]=tower[i]-left[i];
        }
    }
    return (left[n]==0);
}

int main(){
    while(scanf("%d",&n)==1 && n){
        for(int i=1;i<=n;i++) scanf("%d",&tower[i]);
        if(n==1){
            printf("%d\n",tower[1]);
            continue;
        }
        tower[n+1]=tower[1];
        int L=0,R=0;
        for(int i=1;i<=n;i++) L=max(L,tower[i]+tower[i+1]);
        if(n%2){
            for(int i=1;i<=n;i++) R=max(R,tower[i]*3);
            while(L<R){
                int mid=L+(R-L)/2;
                if(test(mid)) R=mid;
                else L=mid+1;
            }
        }
        printf("%d\n",L);
    }
}
