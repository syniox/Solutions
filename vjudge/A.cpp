#include<cstdio>
#include<iostream>
using namespace std;
#define P 12505
//int n,t,p,q,a[P],b[P],f[P][P];
int n,t,p,q,top,a[P],mp[P],stk[P];
int main() {
	scanf("%d",&t);
	for(int cas=1; cas<=t; ++cas) {
		/*scanf("%d%d%d",&n,&p,&q);
		for(int i=1;i<=p+1;++i){
			scanf("%d",a+i);
		}
		for(int i=1;i<=q+1;++i){
			scanf("%d",b+i);
		}
		for(int i=1;i<=p+1;++i){
			for(int j=1;j<=q+1;++j){
				if(a[i]==b[j]){
					f[i][j]=f[i-1][j-1]+1;
				}
				else{
					f[i][j]=max(f[i-1][j],f[i][j-1]);
				}
			}
		}
		printf("%d\n",f[p+1][q+1]);*/
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
				while(l<=r) {
					int mid=(l+r)>>1;
					stk[mid]<=tp?l=mid+1:r=mid;
				}
				stk[l]=tp;
			}
		}
		printf("Case %d: %d\n",cas,top);
	}
}