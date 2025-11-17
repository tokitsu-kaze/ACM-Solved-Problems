#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int l[MAX],r[MAX],in[MAX],p[MAX];
vector<int> mp[MAX];
void topsort(int n)
{
	int i,now,x;
	priority_queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	now=n;
	while(!q.empty())
	{
		x=q.top();
		q.pop();
		p[x]=now--;
		for(auto &to:mp[x])
		{
			in[to]--;
			if(in[to]==0) q.push(to);
		}
	}
}
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			in[i]=0;
		}
		for(i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j) continue;
				if(l[i]>l[j] && r[i]<r[j])
				{
					mp[j].push_back(i);
					in[i]++;
				}
			}
		}
		topsort(n);
		for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
	}
	return 0;
}
