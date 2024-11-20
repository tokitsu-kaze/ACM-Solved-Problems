#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int main()
{
	int n,m,i,x,vis[105];
	char s[2];
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) vis[i]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%s",&x,s);
		if(s[0]=='M' && !vis[x])
		{
			puts("Yes");
			vis[x]=1;
		}
		else puts("No");
	}
	return 0;
}

