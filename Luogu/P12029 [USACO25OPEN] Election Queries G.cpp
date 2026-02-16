#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],cnt[MAX];
int main()
{
	int n,q,i,p,x,tar,mx,mn,ans;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) cnt[i]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	map<int,set<int>> mp;
	for(i=1;i<=n;i++)
	{
		if(cnt[i]==0) continue;
		mp[cnt[i]].insert(i);
	}
	while(q--)
	{
		scanf("%d%d",&p,&x);
		
		mp[cnt[a[p]]].erase(a[p]);
		if(mp[cnt[a[p]]].size()==0) mp.erase(cnt[a[p]]);
		cnt[a[p]]--;
		if(cnt[a[p]]>0) mp[cnt[a[p]]].insert(a[p]);
		
		a[p]=x;
		
		mp[cnt[a[p]]].erase(a[p]);
		if(mp[cnt[a[p]]].size()==0) mp.erase(cnt[a[p]]);
		cnt[a[p]]++;
		if(cnt[a[p]]>0) mp[cnt[a[p]]].insert(a[p]);
		
		auto it2=mp.end();
		it2--;
		tar=(*it2).first;
		mx=*(*it2).second.rbegin();
		mn=*(*it2).second.begin();
		ans=0;
		for(auto &it:mp)
		{
			while((*it2).first+it.first>=tar)
			{
				mx=max(mx,*(*it2).second.rbegin());
				mn=min(mn,*(*it2).second.begin());
				if(it2==mp.begin()) break;
				it2--;
			}
			ans=max({ans,
				abs(*it.second.rbegin()-mn),
				abs(*it.second.begin()-mx),});
		}
		printf("%d\n",ans);
	}
	return 0;
}

