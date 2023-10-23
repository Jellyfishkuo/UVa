#include<bits/stdc++.h>
#define maxn 800
using namespace std;

int A[maxn],B[maxn];
struct Item{
    int sum,b;
    Item(int sum=0,int b=0):sum(sum),b(b){}
    bool operator<(const Item &rhs)const{
        return sum>rhs.sum;
    }
};

void merge(int* A,int* B,int* C, int k){
    priority_queue<Item> pq;
    for(int i=0;i<k;i++)
        pq.push(Item(A[i]+B[0],0));
    for(int i=0;i<k;i++){
        Item item=pq.top();
        pq.pop();
        C[i]=item.sum;
        int b=item.b;
        if(b+1<k) pq.push(Item(item.sum-B[b]+B[b+1],b+1));
    }
}

int main(){
    int k,first;
    first=1;
    while(cin>>k){
        for(int i=1;i<k;i++){
            if(first){
                for(int i=0;i<k;i++) cin>>A[i];
                sort(A,A+k);
                first=0;
            }
            for(int j=0;j<k;j++) cin>>B[j];
            sort(B,B+k);
            merge(A,B,A,k);
        }
        for(int i=0;i<k;i++){
            cout<<A[i];
            if(i==k-1) cout<<endl;
            else cout<<" ";
        }
        first=1;
    }
    return 0;
}
