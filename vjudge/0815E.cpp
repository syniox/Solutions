#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 3000
int T,n,m,cnt,top,s[N],id[N],fir[N],cbf[N],hp[N];
long long dis[N];
vector<int> prt[N];
struct edge {
	int to,wi,nx;
} eg[N*24];
inline void add(int a,int b,int v) {
	eg[++cnt]=(edge) {
		b,v,fir[a]
	};
	fir[a]=cnt;
}
inline void dij() {
	for(int i=1; i<=n; ++i) {
		long long x=0,tp=123456789012345;
		for(int i=1; i<=n; ++i) {
			if(!s[i]&&dis[i]<tp) {
				x=i,tp=dis[i];
			}
		}
		s[x]=1;
		for(int i=0; i<prt[x].size(); ++i) {
			--cbf[prt[x][i]];
		}
		prt[x].clear();
		for(int i=fir[x]; i; i=eg[i].nx) {
			int y=eg[i].to,w=eg[i].wi+dis[x];
			if(!cbf[y]&&dis[y]>w) {
				dis[y]=w;
			}
		}
	}
}
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		cnt=0;
		memset(s,0,sizeof(s));
		memset(dis,127,sizeof(dis));
		memset(fir,0,sizeof(fir));
		for(int a,b,v,i=1; i<=m; ++i) {
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
		}
		for(int li,k,i=1; i<=n; ++i) {
			scanf("%d",&li);
			cbf[i]=li;
			while(li--) {
				scanf("%d",&k);
				prt[k].push_back(i);
			}
		}
		dis[0]=dis[1]=0;
		dij();
		printf("%lld",dis[n]);
	}
	return 0;
}
