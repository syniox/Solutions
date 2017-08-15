#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define N 1010
int T,n,ans,cnt,clk,fir[N],ind[N];
int cnf,top,dfn[N],low[N],stk[N],fa[N],mc[N];
bool ins[N];
struct bomb {
	int x,y,r,c;
} mb[N];
struct edge {
	int to,nx;
} eg[N<<10];
inline void add(int a,int b) {
	eg[++cnt]=(edge) {
		b,fir[a]
	};
	fir[a]=cnt;
}
void tarjan(int x) {
	low[x]=dfn[x]=++clk;
	ins[x]=1;
	stk[++top]=x;
	for(int i=1; i<=n; ++i) {
		int y=eg[i].to;
		if(!dfn[y]) {
			tarjan(y);
			low[x]=min(low[x],low[y]);
		} else if(ins[y]) {
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x]) {
		int k=++cnf;
		do {
			k=stk[top--];
			ins[k]=0;
			fa[k]=cnf;
			mc[cnf]=min(mc[cnf],mb[k].c);
		} while(k!=x);
	}
}
int main() {
	scanf("%d",&T);
	for(int cas=1; cas<=T; ++cas) {
		ans=cnt=cnf=0;
		memset(fir,0,sizeof(fir));
		memset(mc,127,sizeof(mc));
		scanf("%d",&n);
		for(int i=1; i<=n; ++i) {
			scanf("%d%d%d%d",&mb[i].x,&mb[i].y,&mb[i].r,&mb[i].c);
			for(int j=1; j<i; ++j) {
				int x=mb[i].x-mb[j].x,y=mb[i].y-mb[j].y;
				float dis=sqrt(x*x+y*y);
				if(mb[i].r>=dis) add(i,j);
				if(mb[j].r>=dis) add(j,i);
			}
		}
		for(int i=1; i<=n; ++i) {
			if(!dfn[i]) tarjan(i);
		}
		for(int i=1; i<=n; ++i) {
			for(int j=fir[i]; j; j=eg[j].nx) {
				int y=eg[j].to;
				if(fa[i]!=fa[y]) ++ind[fa[y]];
			}
		}
		for(int i=1; i<=cnf; ++i) {
			if(!ind[i]) ans+=mc[i];
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}