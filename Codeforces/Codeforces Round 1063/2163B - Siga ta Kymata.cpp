#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int p[MAX],pos[MAX];
char x[MAX];
int main()
{
	int T,n,i,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			pos[p[i]]=i;
		}
		scanf("%s",x+1);
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(x[i]=='1')
			{
				if(i==1 || i==n || i==pos[1] || i==pos[n]) ok=0;
			}
		}
		if(!ok) puts("-1");
		else
		{
			puts("5");
			printf("%d %d\n",1,pos[1]);
			printf("%d %d\n",1,pos[n]);
			printf("%d %d\n",pos[n],n);
			printf("%d %d\n",pos[1],n);
			if(pos[1]>pos[n]) printf("%d %d\n",pos[n],pos[1]);
			else printf("%d %d\n",pos[1],pos[n]);
		}
	}
	return 0;
}
