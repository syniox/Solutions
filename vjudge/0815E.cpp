#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 3000
int T,n,m,cnt,top,s[N],id[N],fir[N],cbf[N];
long long dis[N],aft[N];
vector<int> prt[N];
struct edge {
	int to,wi,nx;
} eg[N*24];
inline void add(int a,int b,int v) {
	eg[++cnt]=(edge) {b,v,fir[a]};
	fir[a]=cnt;
}
inline void dij() {
	for(int i=1; i<=n; ++i) {
		long long x=0,tp=123456789012345678;
		for(int i=1; i<=n; ++i) {
			if(!cbf[i]&&!s[i]&&dis[i]<tp) {
				x=i,tp=dis[i];
			}
		}
		s[x]=1;
		for(int k,i=0; i<prt[x].size(); ++i) {
			k=prt[x][i];
			--cbf[k];
			aft[k]=max(aft[k],dis[x]);
			if(dis[k]<1234567890123456&&!cbf[k]){
				dis[k]=max(dis[k],aft[k]);
			}
		}
		prt[x].clear();
		for(int i=fir[x]; i; i=eg[i].nx) {
			long long y=eg[i].to,w=eg[i].wi+dis[x];
			if(dis[y]>w) {
				dis[y]=max(aft[y],w);
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
		printf("%lld\n",dis[n]);
	}
	return 0;
}
