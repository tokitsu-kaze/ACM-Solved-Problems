#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
int n,c,ans;
char s[MAX];
void dfs(int x,int sta,int now)
{
	if(x==5)
	{
		int i,sd;
		sd=1;
		for(i=1;i<=n;i++)
		{
			if((sta>>(s[i]-'A'))&1) continue;
			now+=sd;
			sd++;
		}
		ans=min(ans,now);
		return;
	}
	dfs(x+1,sta,now);
	dfs(x+1,sta|(1<<x),now+c);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&c);
		scanf("%s",s+1);
		ans=INF;
		dfs(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
