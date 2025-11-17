#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX],c[MAX],fa[MAX][20];
int main()
{
	int q,i,j,op,x,w,now,suma,tmp;
	ll sumc;
	scanf("%d%d%d",&q,&a[0],&c[0]);
	for(j=0;j<20;j++) fa[0][j]=0;
	for(i=1;i<=q;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%d",&fa[i][0],&a[i],&c[i]);
			for(j=1;j<20;j++) fa[i][j]=fa[fa[i][j-1]][j-1];
		}
		else
		{
			scanf("%d%d",&x,&w);
			suma=sumc=0;
			while(suma<w)
			{
				now=x;
				for(j=19;~j;j--)
				{
					if(a[fa[now][j]]>0) now=fa[now][j];
				}
				tmp=min(a[now],w-suma);
				suma+=tmp;
				a[now]-=tmp;
				sumc+=1LL*tmp*c[now];
				if(now==x) break;
			}
			printf("%d %lld\n",suma,sumc);
			fflush(stdout);
		}
	}
	return 0;
}

