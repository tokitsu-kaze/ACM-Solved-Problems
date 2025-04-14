#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int ans[MAX];
int main()
{
	int T,n,m,i,x,mx,l,r;
	char op[2];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			mx=max(mx,x);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%s%d%d",op,&l,&r);
			if(mx>=l &&mx<=r)
			{
				if(op[0]=='+') mx++;
				else mx--;
			}
			ans[i]=mx;
		}
		for(i=1;i<=m;i++) printf("%d%c",ans[i]," \n"[i==m]);
	}
	return 0;
}

