#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
ll cnt;
struct node {
	ll a,b,c,dep;
} s,t,rs,rt;
inline void sort(node &x) {
	if(x.a>x.b) swap(x.a,x.b);
	if(x.b>x.c) swap(x.b,x.c);
	if(x.a>x.b) swap(x.a,x.b);
}
inline ll Abs(ll x) {
	return x>(ll)0?x:-x;
}
inline node fr(node &x) {
	node tp=x;
	ll dep=0;
	while(tp.b-tp.a!=tp.c-tp.b) {
		ll xy=tp.b-tp.a,yz=tp.c-tp.b;
		if(xy<yz) {
			ll jp=(yz-1)/xy;
			dep+=jp;
			jp*=xy;
			tp.a+=jp,tp.b+=jp;
		} else {
			ll jp=(xy-1)/yz;
			dep+=jp;
			jp*=yz;
			tp.b-=jp,tp.c-=jp;
		}
	}
	x.dep=dep;
	return tp;
}
inline void mov(node &x,ll cs) {
	x.dep-=cs;
	while(cs) {
		ll xy=x.b-x.a,yz=x.c-x.b;
		if(xy<yz) {
			ll jp=min((yz-1)/xy,cs);
			cs-=jp;
			jp*=xy;
			x.a+=jp,x.b+=jp;
		} else {
			ll jp=min((xy-1)/yz,cs);
			cs-=jp;
			jp*=yz;
			x.b-=jp,x.c-=jp;
		}
	}
}
inline void lca() {
	int dx=s.dep-t.dep;
	if(dx>0) mov(s,dx);
	else mov(t,-dx);
	cnt+=Abs(dx);
	if(s.a==t.a&&s.b==t.b&&s.c==t.c) return;
	for(int k=31; k>=0; --k) {
		if(s.dep>=(ll)1<<k&&t.dep>=(ll)1<<k) {
			node k1=s,k2=t;
			mov(k1,(ll)1<<k),mov(k2,(ll)1<<k);
			if(k1.a!=k2.a||k1.b!=k2.b||k1.c!=k2.c) {
				s=k1,t=k2;
				cnt+=(ll)1<<(k+1);
			}
		}
	}
	cnt+=2;
}
int main() {
	scanf("%lld%lld%lld%lld%lld%lld",&s.a,&s.b,&s.c,&t.a,&t.b,&t.c);
	sort(s),sort(t);
	rs=fr(s),rt=fr(t);
	if(rs.a!=rt.a||rs.b!=rt.b||rs.c!=rt.c) {
		puts("NO");
		return 0;
	}
	lca();
	puts("YES");
	printf("%lld\n",cnt);
	return 0;
}
