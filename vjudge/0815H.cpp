#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 105
int T,n,m,cnt,ans,dif,sh[N],h[N],fir[N],que[N],dis[N];
bool inq[N];
struct edge {
	int to,wi,nx;
} eg[N*N];
inline void add(int a,int b,int v) {
	eg[++cnt]=(edge) {
		b,v,fir[a]
	};
	fir[a]=cnt;
}
inline int spfa(int mn,int mx) {
	if(h[1]>mx||h[1]<mn) return -1;
	memset(dis,31,sizeof(dis));
	int hd=0,tl=1;
	que[0]=1;
	dis[1]=0;
	while(hd!=tl) {
		int x=que[hd++];
		if(hd==N) hd=0;
		inq[x]=0;
		for(int i=fir[x]; i; i=eg[i].nx) {
			int y=eg[i].to,w=dis[x]+eg[i].wi;
			if(h[y]>=mn&&h[y]<=mx&&dis[y]>w) {
				dis[y]=w;
				if(!inq[y]) {
					que[tl++]=y;
					if(tl==N) tl=0;
					inq[y]=1;
				}
			}
		}
	}
	return dis[n]==522133279?-1:dis[n];
}
int main() {
	scanf("%d",&T);
	while(T--) {
		cnt=0;
		memset(fir,0,sizeof(fir));
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; ++i) {
			scanf("%d",h+i);
			sh[i]=h[i];
		}
		for(int a,b,v,i=1; i<=m; ++i) {
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
			add(b,a,v);
		}
		sort(sh+1,sh+n+1);
		int l=0,r=1e9+1,tp,mid;
		while(l<r) {
			mid=(l+r)>>1;
			tp=1e9+1;
			for(int i=1; i<=n; ++i) {
				int cp=spfa(sh[i],sh[i]+mid);
				if(~cp) tp=min(tp,cp);
			}
			if(tp==1e9+1) {
				l=mid+1;
			} else {
				ans=tp,dif=mid;
				r=mid;
			}
		}
		printf("%d %d\n",dif,ans);
	}
	return 0;
}
