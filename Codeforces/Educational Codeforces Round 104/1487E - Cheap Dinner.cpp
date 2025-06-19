#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],c[MAX],d[MAX];
int rb[MAX],rc[MAX],rd[MAX];
vector<int> banb[MAX],banc[MAX],band[MAX];
int main()
{
	int n1,n2,n3,n4,i,m,x,y,ans;
	scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
	for(i=1;i<=n1;i++) scanf("%d",&a[i]);
	for(i=1;i<=n2;i++) scanf("%d",&b[i]);
	for(i=1;i<=n3;i++) scanf("%d",&c[i]);
	for(i=1;i<=n4;i++) scanf("%d",&d[i]);
	for(i=1;i<=n2;i++) banb[i].clear();
	for(i=1;i<=n3;i++) banc[i].clear();
	for(i=1;i<=n4;i++) band[i].clear();
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		banb[y].push_back(x);
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		banc[y].push_back(x);
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		band[y].push_back(x);
	}
	map<int,int> mp;
	for(i=1;i<=n1;i++) mp[a[i]]++;
	for(i=1;i<=n2;i++)
	{
		for(auto &it:banb[i])
		{
			mp[a[it]]--;
			if(mp[a[it]]==0) mp.erase(a[it]);
		}
		if(mp.size()==0) rb[i]=INF;
		else rb[i]=(*mp.begin()).first+b[i];
		for(auto &it:banb[i]) mp[a[it]]++;
	}
	
	mp.clear();
	for(i=1;i<=n2;i++)
	{
		if(rb[i]==INF) continue;
		mp[rb[i]]++;
	}
	for(i=1;i<=n3;i++)
	{
		for(auto &it:banc[i])
		{
			mp[rb[it]]--;
			if(mp[rb[it]]==0) mp.erase(rb[it]);
		}
		if(mp.size()==0) rc[i]=INF;
		else rc[i]=(*mp.begin()).first+c[i];
		for(auto &it:banc[i]) mp[rb[it]]++;
	}
	
	mp.clear();
	for(i=1;i<=n3;i++)
	{
		if(rc[i]==INF) continue;
		mp[rc[i]]++;
	}
	for(i=1;i<=n4;i++)
	{
		for(auto &it:band[i])
		{
			mp[rc[it]]--;
			if(mp[rc[it]]==0) mp.erase(rc[it]);
		}
		if(mp.size()==0) rd[i]=INF;
		else rd[i]=(*mp.begin()).first+d[i];
		for(auto &it:band[i]) mp[rc[it]]++;
	}
	ans=INF;
	for(i=1;i<=n4;i++) ans=min(ans,rd[i]);
	if(ans==INF) ans=-1;
	printf("%d\n",ans);
	return 0;
}
