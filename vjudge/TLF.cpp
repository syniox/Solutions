#include<iostream>
#include<cstdio>
using namespace std;
#define N 10005
int n,m,cnt,hr[N];
int cnf,fa[N],sz[N],od[N];
int top,dfn[N],low[N],stk[N];
bool ins[N];
struct edges {
	int to,nx;
} eg[N*5];
inline void add(int a,int b) {
	eg[++cnt].to=b;
	eg[cnt].nx=hr[a];
	hr[a]=cnt;
}
void tarjan(int x) {
	stk[++top]=x;
	ins[x]=1;
	low[x]=dfn[x]=++cnt;
	for(int i=hr[x]; i; i=eg[i].nx) {
		int y=eg[i].to;
		if(!dfn[y]) {
			tarjan(y);
			low[x]=min(low[x],low[y]);
		} else if(ins[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x]) {
		++cnf;
		int j;
		do{
			++sz[cnf];
			j=stk[top--];
			ins[j]=0;
			fa[j]=cnf;
		}while(j!=x);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int a,b,i=1; i<=m; ++i) {
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	for(int i=1; i<=n; ++i) {
		if(!dfn[i]) tarjan(i);
	}
	if(cnf==1) {
		printf("%d\n",n);
		return 0;
	}
	for(int x=1; x<=n; ++x) {
		for(int i=hr[x]; i; i=eg[i].nx) {
			int y=eg[i].to;
			if(fa[x]!=fa[y]) ++od[fa[x]];
		}
	}
	int pf,cod=0;
	for(int i=1; i<=cnf; ++i) {
		if(!od[i]) {
			if(!cod) pf=i;
			++cod;
		}
	}
	printf("%d\n",cod==1?sz[pf]:0);
}
