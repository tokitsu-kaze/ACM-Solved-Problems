#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct node{int x,w;};
vector<node> mp[MAX];
int in[MAX],n;
double f[MAX],dp[MAX];
void topsort()
{
	int i;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto &to:mp[x])
		{
			in[to.x]--;
			dp[to.x]+=(dp[x]+f[x]*to.w)/mp[x].size();
			f[to.x]+=f[x]/mp[x].size();
			if(!in[to.x]) q.push(to.x);
		}
	}
}
int main()
{
	int m,i,a,b,w;
	double ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		in[i]=0;
		f[i]=dp[i]=0;
	}
	f[1]=1;
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&w);
		mp[a].push_back({b,w});
		in[b]++;
	}
	topsort();
	ans=0;
	printf("%.2f\n",dp[n]);
	return 0;
}
