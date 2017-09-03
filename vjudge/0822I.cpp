#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
ll cnt;
struct node{
	int a,b,c,dep;
}s,t,rs,rt;
inline void sort(node x){
	if(x.a>x.b) swap(x.a,x.b);
	if(x.b>x.c) swap(x.b,x.c);
	if(x.a>x.b) swap(x.a,x.b);
}
inline int abs(int x){
	return x>0?x:-x;
}
inline node fr(node x){
	node tp=x;
	long long dep=0;
	while(abs(tp.a-tp.b)!=abs(tp.b-tp.c)){
		int xy=abs(tp.a-tp.b),yz=abs(tp.b-tp.c);
		if(xy<yz){
			dep+=yz/xy;
			int jp=(yz/xy)*xy;
			tp.a+=jp,tp.b+=jp;
			if(yz%xy==0){
				dep-=1;
				tp.a-=xy,tp.b-=xy;
			}
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
		printf("%d %d %d %d\n",cs,x.a,x.b,x.c);
		int xy=abs(x.a-x.b),yz=abs(x.b-x.c);
		if(xy<yz){
			int jp=yz/xy;
			if(yz%xy==0) jp-=1;
			cs-=jp;
			x.a+=jp*xy,x.b+=jp*xy;
			if(yz%xy==0) return;
		}else{
			int jp=xy/yz;
			if(xy%yz==0) jp-=1;
			cs-=jp;
			x.b-=jp*yz,x.c-=jp*yz;
			if(xy%yz==0) return;
		}
	}
}
inline void lca(node x,node y){
	if(x.dep>y.dep) rvs(x,x.dep-y.dep);
	else rvs(y,y.dep-x.dep);
	if(x.a==y.a&&x.b==y.b&&x.c==y.c) return;
	for(int k=30;k>=0;--k){
		puts("ff");
		node k1=x,k2=y;
		rvs(k1,1<<k),rvs(k2,1<<k);
		printf("%d %d %d %d %d %d\n%d %d %d %d %d %d\n",x.a,x.b,x.c,y.a,y.b,y.c,k1.a,k1.b,k1.c,k2.a,k2.b,k2.c);
		if(k1.a!=k2.a||k1.b!=k2.b||k1.c!=k2.c){
			x=k1,y=k2,cnt+=1<<k;
		}
	}
}
int main(){
	while(scanf("%d%d%d%d%d%d",&s.a,&s.b,&s.c,&t.a,&t.b,&t.c)){
		sort(s),sort(t);
		rs=fr(s),rt=fr(t);
		printf("%d %d %d\n%d %d %d\n",s.a,s.b,s.c,t.a,t.b,t.c);
		if(rs.a!=rt.a||rs.b!=rt.b||rs.c!=rt.c){
			puts("NO");
			continue;
		}
		lca(s,t);
		puts("YES");
		printf("%lld\n",cnt);
	}
	system("pause");
	return 0;
}
