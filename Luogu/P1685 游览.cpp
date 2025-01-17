#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e4+10;
const int mod=1e4;
struct node{int to,w;};
vector<node> mp[MAX];
int dp[MAX],cnt[MAX],in[MAX],tag[MAX];
void topsort(int n,int s)
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		cnt[i]=tag[i]=dp[i]=0;
		if(!in[i]) q.push(i);
	}
	cnt[s]=1;
	tag[s]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto &it:mp[x])
		{
			if(tag[x])
			{
				dp[it.to]=(dp[it.to]+dp[x]+cnt[x]*it.w)%mod;
				cnt[it.to]=(cnt[it.to]+cnt[x])%mod;
				tag[it.to]=1;
			}
			in[it.to]--;
			if(!in[it.to]) q.push(it.to);
		}
	}
}
int main()
{
	int n,m,s,t,t0,i,a,b,c;
	scanf("%d%d%d%d%d",&n,&m,&s,&t,&t0);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		in[i]=0;
	}
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		in[b]++;
	}
	topsort(n,s);
	printf("%lld\n",(dp[t]+1LL*(cnt[t]-1+mod)*t0)%mod);
	return 0;
}
/*
4 3 1 4 2
1 2 3
2 4 3
3 1 3

4 3 1 4 2
1 2 3
2 4 3
3 2 3

4 3 1 4 2
1 2 3
2 4 3
2 3 3
*/
