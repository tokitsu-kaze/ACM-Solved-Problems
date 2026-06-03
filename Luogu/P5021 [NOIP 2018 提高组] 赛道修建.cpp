#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
struct node{int to,w;};
vector<node> mp[MAX];
int m,k,cnt,dep[MAX];
void dfs(int x,int fa)
{
	int now;
	dep[x]=0;
	multiset<int> s;
	for(auto &it:mp[x])
	{
		if(it.to==fa) continue;
		dfs(it.to,x);
		if(dep[it.to]+it.w>=k) cnt++;
		else s.insert(dep[it.to]+it.w);
	}
	while(s.size())
	{
		now=*s.begin();
		s.erase(s.find(now));
		auto it=s.lower_bound(k-now);
		if(it==s.end()) dep[x]=max(dep[x],now);
		else
		{
			s.erase(it);
			cnt++;
		}
	}
//	printf("%d %d %d\n",x,dep[x],cnt);
}
int ck(int _k)
{
	k=_k;
	cnt=0;
	dfs(1,0);
	return cnt>=m;
}
int main()
{
	int n,i,a,b,c,l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	l=0;
	r=1e9;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}
/*
8 3
3 2 1
3 1 100
3 4 1
3 7 1
7 6 9
7 5 11
7 8 10
*/
