#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double eps=1e-12;
const int MAX=3e5+10;
char mp[1010][1010];
int main()
{
	int n,m,i,j,a,b,c,d,ok;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	a=b=INF;
	c=d=-INF;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='#')
			{
				a=min(a,i);
				b=min(b,j);
				c=max(c,i);
				d=max(d,j);
			}
		}
	}
	ok=1;
	for(i=a;i<=c;i++)
	{
		for(j=b;j<=d;j++)
		{
			if(mp[i][j]=='.') ok=0;
		}
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
