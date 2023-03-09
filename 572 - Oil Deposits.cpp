#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[1000][1000];
int dir[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

void bfs(int nx,int ny){
	int x1,y1;
	for(int i=0;i<8;i++){
		x1=nx+dir[i][0];
		y1=ny+dir[i][1];
		if(x1>=0&&y1>=0&&x1<=n&&y1<=m&&a[x1][y1]=='@'){
			a[x1][y1]='*';
			bfs(x1,y1);
		}
	}
}

int main(){
	while(cin>>n>>m){
		if(n==0&&m==0) break;
		string s;
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>s;
			for(int j=0;j<m;j++){
				a[i][j]=s[j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]=='@'){
					ans++;
					bfs(i,j);
				}
			}
		}
		cout<<ans<<endl;
	}
}
