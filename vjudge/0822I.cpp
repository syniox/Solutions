#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
ll cnt;
struct node{
	long long a,b,c,dep;
}s,t,rs,rt;
inline void sort(node x){
	if(x.a>x.b) swap(x.a,x.b);
	if(x.b>x.c) swap(x.b,x.c);
	if(x.a>x.b) swap(x.a,x.b);
}
inline int abs(int x){
	return x>0?x:-x;
}
inline node fr(node &x){
	node tp=x;
	long long dep=0;
	while(tp.b-tp.a!=tp.c-tp.b){
		int xy=tp.b-tp.a,yz=tp.c-tp.b;
		if(xy<yz){
			int jp=yz/xy-(yz%xy==0);
			dep+=jp;
			jp*=xy;
			tp.a+=jp,tp.b+=jp;
		}else{
			dep+=xy/yz;
			int jp=(xy/yz)*yz;
			tp.b-=jp,tp.c-=jp;
			if(xy%yz==0){
				dep-=1;
				tp.b+=yz,tp.c+=yz;
			}
		}
	}
	x.dep=dep;
	return tp;
}
inline void rvs(node &x,int cs){
	while(cs){
		printf("%d %lld %lld %lld\n",cs,x.a,x.b,x.c);
		int xy=x.b-x.a,yz=x.c-x.b;
		if(xy<yz){
			int jp=min(yz/xy,cs);
			cs-=jp;
			jp*=xy;
			x.a+=jp,x.b+=jp;
		}else{
			int jp=min(xy/yz,cs);
			cs-=jp;
			jp*=yz;
			x.b-=jp,x.c-=jp;
		}
	}
}
inline void lca(node x,node y){
	if(x.dep>y.dep) rvs(x,x.dep-y.dep);
	else rvs(y,y.dep-x.dep);
	cnt+=abs(x.dep-y.dep);
	if(x.a==y.a&&x.b==y.b&&x.c==y.c) return;
	for(int k=30;k>=0;--k){
		if(x.dep>=(1<<k)&&y.dep>=(1<<k)){
			node k1=x,k2=y;
			rvs(k1,1<<k),rvs(k2,1<<k);
			if(k1.a!=k2.a||k1.b!=k2.b||k1.c!=k2.c){
				x=k1,y=k2,cnt+=1<<k;
			}
		}
	}
}
int main(){
	while(scanf("%lld%lld%lld%lld%lld%lld",&s.a,&s.b,&s.c,&t.a,&t.b,&t.c)){
		sort(s),sort(t);
		rs=fr(s),rt=fr(t);
		if(rs.a!=rt.a||rs.b!=rt.b||rs.c!=rt.c){
			puts("NO");
			continue;
		}
		lca(s,t);
		puts("YES");
		printf("%lld\n",cnt);
	}
	return 0;
}
