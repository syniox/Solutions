#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100005
int T,X,n,m,cas,cnt,ans,fir[N];
int clk,top,cnf,fa[N],sz[N],dfn[N],low[N],stk[N];
bool ins[N],ind[N],otd[N];
struct edge{
    int to,nx;
}eg[N];
inline void add(int a,int b){
    eg[++cnt]=(edge){b,fir[a]};
    fir[a]=cnt;
}
void tarjan(int x) {
	low[x]=dfn[x]=++clk;
	ins[x]=1;
	stk[++top]=x;
	for(int i=fir[x]; i; i=eg[i].nx) {
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
            ++sz[cnf];
		} while(k!=x);
	}
}
int main(){
    scanf("%d",&T);
    while(T--){
        cnt=cnf=clk=0;
        memset(fir,0,sizeof(fir));
        scanf("%d%d",&n,&m);
        for(int a,b,i=1;i<=m;++i){
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        for(int i=1;i<=n;++i){
            if(dfn[i]) tarjan(i);
        }
        for(int x=1;x<=n;++x){
            for(int i=fir[x];i;i=eg[i].nx){
                int y=eg[i].to;
                if(fa[x]!=fa[y]){
                    otd[x]=ind[y]=1;
                }
            }
        }
        X=N;
        for(int i=1;i<=cnf;++i){
            if(!ind[i]||!otd[i]){
                X=min(X,sz[i]);
            }
        }
        ans=n*(n-1);
        ans-=m+X*(n-X);
        printf("Case %d: %d\n",++cas,ans);
    }
}
