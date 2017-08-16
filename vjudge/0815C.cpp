#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 1005
int T,n,m,cnt,ans,dp[N],fir[N],fis[N];
int cnf,clk,top,sz[N],fa[N],stk[N],dfn[N],low[N];
bool ins[N];
struct edge{
    int to,nx;
}eg[N*50],sce[N*50];
inline void add(int a,int b){
    eg[++cnt]=(edge){b,fir[a]};
    fir[a]=cnt;
}
inline void tarjan(int x){
    dfn[x]=low[x]=++clk;
    stk[++top]=x;
    ins[x]=1;
    for(int i=fir[x];i;i=eg[i].nx){
        int y=eg[i].to;
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }else if(ins[y]==1){
            low[x]=min(low[x],dfn[y]);
        }
    }
    if(dfn[x]==low[x]){
        ++cnf;
        int k;
        do{
            k=stk[top--];
            ins[k]=0;
            fa[k]=cnf;
            ++sz[cnf];
        }while(k!=x);
    }
}
int ask(int x){
    if(dp[x]) return dp[x];
    for(int i=fis[x];i;i=sce[i].nx){
        int y=sce[i].to;
        dp[x]=max(dp[x],ask(y));
    }
    return dp[x]+=sz[x];
}
int main(){
    scanf("%d",&T);
    while(T--){
        cnt=cnf=clk=ans=0;
        memset(fir,0,sizeof(fir));
        scanf("%d%d",&n,&m);
        for(int a,b,i=1;i<=m;++i){
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        for(int i=1;i<=n;++i){
            if(!dfn[i]) tarjan(i);
        }
        cnt=0;
        for(int x=1;x<=n;++x){
            for(int i=fir[x];i;i=eg[i].nx){
                int y=eg[i].to;
                if(fa[x]!=fa[y]){
                    sce[++cnt]=(edge){fa[y],fis[x]};
                    fis[x]=cnt;
                }
            }
        }
        for(int i=1;i<=cnf;++i){
            ans=max(ans,ask(i));
        }
        printf("%d\n",ans);
    }
    return 0;
}
