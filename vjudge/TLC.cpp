#include<cstdio>
#include<cstring>
using namespace std;
int n,m,b,ans,map[8][8],vis[8][8];
int cr[]= {1,-1,0,0},cc[]= {0,0,-1,1};
bool lp[8][8];
inline bool inm(int r,int c) {
	return r&&c&&r<=n&&c<=m;
}
inline void mod(int r,int c,int x) {
	vis[r][c]+=x;
	for(int i=0; i<4; ++i) {
		int a=r+cr[i],b=c+cc[i];
		if(map[a][b]<5) map[a][b]-=x;
		while(inm(a,b)&&map[a][b]>4) {
			vis[a][b]+=x;
			a+=cr[i];
			b+=cc[i];
		}
	}
}
inline bool ok() {
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			if(map[i][j]==16843009) {
				if(!vis[i][j]) return 0;
			} else{
				if(map[i][j]>0) return 0;
			}
		}
	}
	return 1;
}
inline bool judge(int r,int c) {
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			printf("%d ",vis[i][j]);
		}
		puts("");
	}
	if(map[r][c]!=16843009||vis[r][c]) return 0;
	for(int i=0; i<4; ++i) {
		int x=r+cr[i],y=c+cc[i];
		if(inm(x,y)&&!map[x][y]) return 0;
	}
	puts("d");
	int x=r,y=c+1;
	if(map[x][y]<5) {
		for(int i=x-1; i&&map[i][y]>5; --i) {
			if(!vis[i][y]) return 0;
		}
	}
	return 1;
}
void dfs(int r,int c,int t) {
	if(ok()) {
		ans=ans<t?ans:t;
		return;
	}
	if(t>ans) return;
	for(int i=r; i<=n; ++i) {
		for(int j=i==r?c+1:1; j<=n; ++j) {
			if(judge(i,j)) {
//				printf("%d %d\n",i,j);
				mod(i,j,1);
				dfs(i,j,t+1);
				mod(i,j,-1);
			}
		}
	}
}
int main() {
	while(~scanf("%d%d",&n,&m)&&(n||m)) {
		memset(vis,0,sizeof(vis));
		memset(map,1,sizeof(map));//16843009
		scanf("%d",&b);
		for(int r,c,k,i=1; i<=b; ++i) {
			scanf("%d%d%d",&r,&c,&k);
			map[r][c]=k;
		}
		ans=123456;
		dfs(1,0,0);
		printf(ans==123456?"No solution\n":"%d\n",ans);
	}
	return 0;
}
