#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],mx;
set<pair<int,int>> s;
void upd(int l,int r)
{
	int x,y;
	vector<pair<int,int>> del;
	auto it=--s.upper_bound({l,-1});
	for(;it!=s.end();it++)
	{
		x=(*it).first;
		y=(*it).second;
		if(y<l) continue;
		if((x<=l && l<=y) || (l<=x && x<=r))
		{
			l=min(x,l);
			r=max(y,r);
		}
		else break;
		del.push_back(*it);
	}
	for(auto &it:del) s.erase(it);
	s.insert({l,r});
	mx=max(mx,r-l);
}
int main()
{
	int T,n,i;
	ll now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		s.clear();
		s.insert({-1,-1});
		mx=now=0;
		for(i=1;i<=n;i++)
		{
			upd(b[i],a[i]);
			now+=a[i]-b[i];
			printf("%lld%c",now-mx," \n"[i==n]);
		}
	}
	return 0;
}
