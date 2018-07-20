#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
bool flag[MAX];
int bfs(int x)
{
	int i,t,res=0;
	queue<int> q;
	q.push(x);
	flag[x]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		res++;
		for(i=0;i<sz(mp[t]);i++)
		{
			if(!flag[mp[t][i]])
			{
				q.push(mp[t][i]);
				flag[mp[t][i]]=1;
			}
		}
	}
	return res;
}
int main()
{
	int n,m,a,b,i;
	ll ans;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		mem(flag,0);
		ans=0;
		for(i=1;i<=n;i++)
		{
			int temp=0;
			if(!flag[i]) temp=bfs(i);
			ans+=(ll)temp*(temp-1)/2;
		}
		if(ans==(ll)m) puts("YES");
		else puts("NO");
	}
	return 0;
}