#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
vector<int> mp[MAX];
int ban[MAX][32],ans[MAX];
int main()
{
	int n,q,i,j,a,b,x,f;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		memset(ban[i],0,sizeof ban[i]);
		ans[i]=-1;
		mp[i].clear();
	}
	while(q--)
	{
		scanf("%d%d%d",&a,&b,&x);
		for(i=0;i<30;i++)
		{
			if(!((x>>i)&1)) ban[a][i]=ban[b][i]=1;
		}
		if(a==b)
		{
			ans[a]=x;
			continue;
		}
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	for(i=1;i<=n;i++)
	{
		if(ans[i]!=-1) continue;
		ans[i]=0;
		for(j=29;~j;j--)
		{
			if(ban[i][j]) continue;
			f=0;
			for(auto &to:mp[i])
			{
				if(ban[to][j]) f=1;
			}
			ans[i]|=(f<<j);
			ban[i][j]=!f;
		}
	}
	for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}
/*
从前往后考虑，从高位到低位尽量不填 1。
i 的 k 位不填 1，出边是 1 的必须填 1；
但要考虑出边不能填 1 的情况。
对于每一位，预处理每个点的出边能不能填 1。
*/
