#include<cstdio>
using namespace std;
#define N 205
int n,na,nb,sa,sb,a[N],b[N];
int map[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main(){
	scanf("%d%d%d",&n,&na,&nb);
	for(int i=1;i<=na;++i) scanf("%d",a+i);
	for(int i=1;i<=nb;++i) scanf("%d",b+i);
	for(int ca=0,cb=0,i=1;i<=n;++i){
		if(ca==na) ca=0;
		if(cb==nb) cb=0;
		sa+=map[a[++ca]][b[++cb]];
		sb+=map[b[cb]][a[ca]];
	}
	printf("%d %d\n",sa,sb);
}
