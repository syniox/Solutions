#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200005
int n,rt,cnt;
struct node{
	int w,sz,fa,ch[2];//0-left 1-right
}tr[N];
inline void add(int k,bool c,int v){
	tr[++cnt].fa=k;
	tr[k].ch[c]=cnt;
	tr[cnt].w=v;
	tr[cnt].sz=1;
}
inline void upd(int k){
	tr[k].sz=tr[tr[k].ch[0]].sz+tr[tr[k].ch[1]].sz+1;
}
void rot(int k,bool v){//0-left 1-right
	int f=tr[k].fa,ff=tr[f].fa;
	if(f==rt) rt=k;
	if(ff) tr[ff].ch[tr[ff].ch[1]==f]=k;
	tr[k].fa=ff;
	tr[f].ch[v^1]=tr[k].ch[v];
	tr[tr[k].ch[v]].fa=f;
	tr[k].ch[v]=f;
	tr[f].fa=k;
	upd(f);
	upd(k);
}
void splay(int k){
	while(k!=rt){
		int f=tr[k].fa,ff=tr[f].fa;
		if(f!=rt){
			if((tr[f].ch[0]==k)^(tr[ff].ch[0]==f)) rot(k,tr[f].ch[0]==k);
			else rot(f,tr[ff].ch[0]==f);
		}
		rot(k,tr[tr[k].fa].ch[0]==k);
	}
}
void ins(int k,int p,int v){
	int tp=tr[tr[k].ch[0]].sz;
	if(tp>=p){
		if(tr[k].ch[0]) ins(tr[k].ch[0],p,v);
		else{
			add(k,0,v);
			splay(cnt);
		}
	}else{
		if(tr[k].ch[1]) ins(tr[k].ch[1],p-tp-1,v);
		else{
			add(k,1,v);
			splay(cnt);
		}
	}
	upd(k);
}
void print(int k){
	if(tr[k].ch[0]) print(tr[k].ch[0]);
	printf("%d ",tr[k].w);
	if(tr[k].ch[1]) print(tr[k].ch[1]);
}
int main(){
	while(~scanf("%d",&n)){
		memset(tr,0,sizeof(tr));
		cnt=0;
		int p,v;
		scanf("%d%d",&p,&v);
		rt=tr[++cnt].sz=1;
		tr[cnt].w=v;
		for(int i=1;i<n;++i){
			scanf("%d%d",&p,&v);
			ins(rt,p,v);
		}
		print(rt);
		putchar('\n');
	}
	return 0;
}
