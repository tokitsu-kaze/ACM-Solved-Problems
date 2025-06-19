#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,j,tot,x,y,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		map<int,int> mp;
		tot=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(!mp.count(x)) a[++tot]=x;
			mp[x]=1;
		}
		ok=0;
		for(i=1;i<=tot;i++)
		{
			for(j=i;j<=tot;j++)
			{
				if(!mp.count(a[i]+a[j]))
				{
					x=a[i];
					y=a[j];
					ok=1;
					break;
				}
			}
			if(ok) break;
		}
		if(!ok) puts("-1");
		else printf("%d %d\n",x,y);
	}
	return 0;
}
