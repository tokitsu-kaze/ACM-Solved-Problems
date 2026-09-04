#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int p[MAX],pos[MAX];
int main()
{
	int n,q,i,op,x,y,f;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	f=0;
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			if(!f)
			{
				swap(pos[p[x]],pos[p[y]]);
				swap(p[x],p[y]);
			}
			else
			{
				swap(p[pos[x]],p[pos[y]]);
				swap(pos[x],pos[y]);
			}
		}
		else f^=1;
//		for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
//		for(i=1;i<=n;i++) printf("%d%c",pos[i]," \n"[i==n]);
	}
	if(!f)
	{
		for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
	}
	else
	{
		for(i=1;i<=n;i++) printf("%d%c",pos[i]," \n"[i==n]);
	}
	return 0;
}
