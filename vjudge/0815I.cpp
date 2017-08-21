#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define N 1005
int n,m,s,t,k,cnr,cnt[2],dis[N],fir[N][2];
bool vis[N];
struct edge {
	int to,wi,nx;
} eg[N*100][2];
struct node {
	int n,dis;
};
struct nodf{
    int n,fr;
};
bool operator < (node a,node b) {
	return a.dis>b.dis;
}
bool operator < (nodf a,nodf b) {
    return a.fr+dis[a.n]>b.fr+dis[b.n];
}
priority_queue<node> q;
inline void add(int a,int b,int t,bool k) {
	eg[++cnt[k]][k]=(edge) {b,t,fir[a][k]};
	fir[a][k]=cnt[k];
}
inline void dij() {
	q.push((node) {t,0});
	while(!q.empty()) {
		node x=q.top();
		q.pop();
		if(!vis[x.n]) {
			dis[x.n]=x.dis;
			vis[x.n]=1;
			for(int i=fir[x.n][1]; i; i=eg[i][1].nx) {
				q.push((node) {eg[i][1].to,x.dis+eg[i][1].wi});
			}
		}
	}
}
priority_queue<nodf> Q;
inline void asr(){
    Q.push((nodf){s,0});
    while(!Q.empty()){
        nodf x=Q.top();
        Q.pop();
        if(x.n==t) ++cnr;
        if(cnr==k){
            printf("%d\n",x.fr);
            return;
        }
        for(int i=fir[x.n][0];i;i=eg[i][0].nx){
            Q.push((nodf) {eg[i][0].to,x.fr+eg[i][0].wi});
        }
    }
    puts("-1");
}
int main() {
	memset(dis,127,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int a,b,tt,i=1; i<=m; ++i) {
		scanf("%d%d%d",&a,&b,&tt);
        add(a,b,tt,0);
        add(b,a,tt,1);
    }
    scanf("%d %d %d",&s,&t,&k);
    if(s==t) ++k;
    dij();
    if(dis[s]>10000000) puts("-1");
    else asr();
    return 0;
}
