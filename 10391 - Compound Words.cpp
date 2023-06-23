#include<bits/stdc++.h>
#define N 120000
#define LEN 110
#define P 0x7fffffff
using namespace std;

int n,tot;
char word[N+10][LEN];
int head[N+10];
struct list{
    int n;
    int next;
}e[N+10];

void add(unsigned int index,int m){
    e[tot].n=m;
    e[tot].next=head[index];
    head[index]=tot++;
}

unsigned int BKDRhash(char *str){
    unsigned int seed=131;
    unsigned int hash=0;
    int len=strlen(str);
    for(int i=0;i<len;i++)
        hash=hash*seed+str[i];
    return (hash &P)%N;
}

int find(char *str){
    unsigned int index=BKDRhash(str);
    for(int k=head[index];k!=-1;k=e[k].next){
        int m=e[k].n;
        if(!strcmp(word[m],str))
            return k;
    }
    return -1;
}

int main(){
    n=tot=0;
    memset(head,-1,sizeof(head));
    while(cin>>word[n]){
        unsigned int index=BKDRhash(word[n]);
        add(index,n);
        n++;
    }
    for(int i=0;i<n;i++){
        char str1[LEN],str2[LEN];
        int len=strlen(word[i]);
        for(int j=0;j<len-1;j++){
            int k,kk;
            for(k=0,kk=0;kk<=j;k++,kk++) str1[k]=word[i][kk];
            str1[k]='\0';
            for(k=0,kk=j+1;kk<len;k++,kk++) str2[k]=word[i][kk];
            str2[k]='\0';
            int ok[2];
            ok[0]=find(str1);
            ok[1]=find(str2);
            if(ok[0]!=-1&&ok[1]!=-1){
                cout<<word[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
