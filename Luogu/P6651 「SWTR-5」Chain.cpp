#include <bits/stdc++.h>
using namespace std;
const int MAX=2e3+10;
const int mod=1e9+7;
int dp[MAX][MAX],topn[MAX];
void topsort(int n,vector<int> mp[],int *in)
{
	int i,tot;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	tot=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		dp[x][x]=1;
		topn[x]=++tot;
		for(auto &to:mp[x])
		{
			in[to]--;
			if(!in[to]) q.push(to);
			for(i=1;i<=n;i++) dp[i][to]=(dp[i][to]+dp[i][x])%mod;
		}
	}
}
vector<int> mp[MAX],revmp[MAX];
int in[MAX],out[MAX],tmpin[MAX];
int dppre[MAX],dpsuf[MAX];
int main()
{
	int n,m,i,j,a,b,q,k,ans,sum,now,res[22];
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		in[i]=out[i]=0;
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		in[b]++;
		out[a]++;
	}
	memset(dp,0,sizeof dp);
	for(i=1;i<=n;i++) tmpin[i]=in[i];
	topsort(n,mp,tmpin);
	vector<int> s,t;
	for(i=1;i<=n;i++)
	{
		if(in[i]==0) s.push_back(i);
		if(out[i]==0) t.push_back(i);
	}
	sum=0;
	for(auto &ss:s)
	{
		for(auto &tt:t)
		{
			sum=(sum+dp[ss][tt])%mod;
		}
	}
	for(i=1;i<=n;i++)
	{
		dppre[i]=dpsuf[i]=0;
		for(auto &it:s) dppre[i]=(dppre[i]+dp[it][i])%mod;
		for(auto &it:t) dpsuf[i]=(dpsuf[i]+dp[i][it])%mod;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&k);
		vector<int> tmp(k);
		for(auto &it:tmp) scanf("%d",&it);
		sort(tmp.begin(),tmp.end(),[&](int x,int y){
			return topn[x]<topn[y];
		});
		ans=sum;
		for(i=k-1;~i;i--)
		{
			res[i]=dpsuf[tmp[i]];
			for(j=i+1;j<k;j++)
			{
				res[i]=(res[i]-1LL*dp[tmp[i]][tmp[j]]*res[j])%mod;
			}
			ans=(ans-1LL*dppre[tmp[i]]*res[i])%mod;
		}
		if(ans<0) ans+=mod;
		printf("%d\n",ans);
	}
	return 0;
}
