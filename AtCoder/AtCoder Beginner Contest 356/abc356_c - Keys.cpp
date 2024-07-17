#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int n,m,k,res[105],ans;
char op[105][2];
void dfs(int x,int now)
{
	if(x==n)
	{
		for(int i=0;i<m;i++)
		{
			if(op[i][0]=='o')
			{
				if(__builtin_popcount(now&res[i])<k) return;
			}
			else
			{
				if(__builtin_popcount(now&res[i])>=k) return;
			}
		}
		ans++;
		return;
	}
	dfs(x+1,now);
	dfs(x+1,now|(1<<x));
}
int main()
{
	int i,x,y;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		scanf("%d",&x);
		res[i]=0;
		while(x--)
		{
			scanf("%d",&y);
			res[i]|=1<<(y-1);
		}
		scanf("%s",op[i]);
	}
	ans=0;
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}
