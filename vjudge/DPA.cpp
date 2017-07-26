#include<cstdio>
#include<cstring> 
using namespace std;
#define P 62505
int n,t,p,q,top,a[P],mp[P],stk[P];
int main() {
	scanf("%d",&t);
	for(int cas=1; cas<=t; ++cas) {
		memset(mp,0,sizeof(mp));
		top=0;
		scanf("%d%d%d",&n,&p,&q);
		for(int k,i=1; i<=p+1; ++i) {
			scanf("%d",&k);
			mp[k]=i;
		}
		for(int i=1; i<=q+1; ++i) {
			scanf("%d",a+i);
			a[i]=mp[a[i]];
		}
		for(int i=1; i<=q+1; ++i) {
			int tp=a[i];
			if(tp>stk[top]) stk[++top]=tp;
			else {
				int l=1,r=top;
				while(l<r) {
					int mid=(l+r)>>1;
					stk[mid]<=tp?l=mid+1:r=mid;
				}
				stk[l]=tp;
			}
		}
		printf("Case %d: %d\n",cas,top);
	}
}
