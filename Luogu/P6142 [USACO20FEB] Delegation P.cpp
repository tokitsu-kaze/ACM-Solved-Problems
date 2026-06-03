#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
vector<int> mp[MAX];
int k,ok,dep[MAX];
void dfs(int x,int fa)
{
	int f,now;
	dep[x]=0;
	multiset<int> s;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
		s.insert(dep[to]+1);
	}
	if(x==1 && s.size()%2==1) s.insert(0);
	else if(x!=1 && s.size()%2==0) s.insert(0);
	f=0;
	while(s.size())
	{
		now=*s.begin();
		s.erase(s.begin());
		auto it=s.lower_bound(k-now);
		if(it==s.end())
		{
			if(x==1 || f)
			{
				ok=0;
				return;
			}
			f=1;
			dep[x]=now;
		}
		else s.erase(it);
	}
}
int ck(int _k)
{
	k=_k;
	ok=1;
	dfs(1,0);
	return ok;
}
int main()
{
	int n,i,a,b,l,r,mid;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	l=1;
	r=n;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}
