#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
set<int> pos[MAX];
int main()
{
	int T,n,m,q,i,pre,cnt,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(i=1;i<=n;i++) pos[i].clear();
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++)
		{
			scanf("%d",&b[i]);
			pos[b[i]].insert(i);
		}
		set<pair<int,int>> ck,s;
		a[0]=0;
		for(i=0;i<n;i++) ck.insert({a[i],a[i+1]});
		pos[0].insert(0);
		for(i=0;i<=n;i++)
		{
			if(pos[i].size()==0) continue;
			s.insert({*pos[i].begin(),i});
		}
		pre=-1;
		cnt=0;
		for(auto &it:s)
		{
			if(pre!=-1)
			{
				if(!ck.count({pre,it.second})) cnt++;
			}
			pre=it.second;
		}
		if(cnt==0) puts("YA");
		else puts("TIDAK");
		while(q--)
		{
			scanf("%d%d",&x,&y);
			if(b[x]==y)
			{
				if(cnt==0) puts("YA");
				else puts("TIDAK");
				continue;
			}
			if(*pos[b[x]].begin()==x)
			{
				auto it=s.find({x,b[x]});
				auto preit=it;
				if(it!=s.begin())
				{
					preit--;
					if(!ck.count({(*preit).second,(*it).second})) cnt--;
				}
				auto nexit=it;
				nexit++;
				if(nexit!=s.end())
				{
					if(!ck.count({(*it).second,(*nexit).second})) cnt--;
				}
				if(it!=s.begin() && nexit!=s.end())
				{
					if(!ck.count({(*preit).second,(*nexit).second})) cnt++;
				}
				s.erase({x,b[x]});
				
				pos[b[x]].erase(x);
				
				if(pos[b[x]].size()>0)
				{
					s.insert({*pos[b[x]].begin(),b[x]});
					it=s.find({*pos[b[x]].begin(),b[x]});
					preit=it;
					if(it!=s.begin())
					{
						preit--;
						if(!ck.count({(*preit).second,(*it).second})) cnt++;
					}
					nexit=it;
					nexit++;
					if(nexit!=s.end())
					{
						if(!ck.count({(*it).second,(*nexit).second})) cnt++;
					}
					if(it!=s.begin() && nexit!=s.end())
					{
						if(!ck.count({(*preit).second,(*nexit).second})) cnt--;
					}
				}
			}
			else pos[b[x]].erase(x);
			if(pos[y].size()>0 && *pos[y].begin()>x)
			{
				auto it=s.find({*pos[y].begin(),y});
				auto preit=it;
				if(it!=s.begin())
				{
					preit--;
					if(!ck.count({(*preit).second,(*it).second})) cnt--;
				}
				auto nexit=it;
				nexit++;
				if(nexit!=s.end())
				{
					if(!ck.count({(*it).second,(*nexit).second})) cnt--;
				}
				if(it!=s.begin() && nexit!=s.end())
				{
					if(!ck.count({(*preit).second,(*nexit).second})) cnt++;
				}
				s.erase({*pos[y].begin(),y});
			}
			b[x]=y;
			pos[b[x]].insert(x);
			if(*pos[b[x]].begin()==x)
			{
				s.insert({x,b[x]});
				auto it=s.find({x,b[x]});
				auto preit=it;
				if(it!=s.begin())
				{
					preit--;
					if(!ck.count({(*preit).second,(*it).second})) cnt++;
				}
				auto nexit=it;
				nexit++;
				if(nexit!=s.end())
				{
					if(!ck.count({(*it).second,(*nexit).second})) cnt++;
				}
				if(it!=s.begin() && nexit!=s.end())
				{
					if(!ck.count({(*preit).second,(*nexit).second})) cnt--;
				}
			}
			assert(cnt>=0);
			if(cnt==0) puts("YA");
			else puts("TIDAK");
		}
	}
	return 0;
}
/*
1
2 2 0
1 2
2 2
*/
