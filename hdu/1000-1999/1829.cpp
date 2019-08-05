////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-09 08:58:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1829
////Problem Title: 
////Run result: Accept
////Run time:561MS
////Run memory:1488KB
//////////////////System Comment End//////////////////
#include<cstdio>  
#define N 2005  
using namespace std;  
int f[N],rank[N], n, k;  
bool flag;  
  
inline void init(){  
    flag=false;  
    for(int i=0; i<=n; ++i)  
        f[i]=i, rank[i]=0;  
}  
int find(int x){  
    if(x==f[x])return f[x];  
    int t=find(f[x]);  
    rank[x] = (rank[f[x]]+rank[x])&1;  
    f[x]=t;  
    return f[x];  
}  
void Union(int x, int y){  
    int a=find(x), b=find(y);  
    if(a==b){  
        if(rank[x]==rank[y])  
            flag=true;  
        return;  
    }  
    f[a]=b;  
    rank[a] = (rank[x]+rank[y]+1)&1;  
}  
  
  
int main(){  
    int T,a,b,cas=1;  
    scanf("%d",&T);  
    while(T--){  
        scanf("%d%d",&n,&k);  
        init();  
        for(int i=0; i<k; ++i){  
            scanf("%d%d",&a,&b);  
            if(flag)continue;  
            Union(a,b);  
        }  
        printf("Scenario #%d:\n",cas++);  
        if(flag)printf("Suspicious bugs found!\n");  
        else printf("No suspicious bugs found!\n");  
        printf("\n");  
    }  
    return 0;  
}  