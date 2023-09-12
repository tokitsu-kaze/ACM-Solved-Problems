#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=4e5+10;
const ll mod=1e6;
int a[MAX],now[MAX];
vector<int> mp[MAX];
struct node
{
	int id,v;
	node(){}
	node(int a,int b)
	{
		id=a;
		v=b;
	}
	friend bool operator<(node a,node b)
	{
		if(a.v==b.v) return a.id>b.id;
		return a.v<b.v;
	}
};
int main()
{
	int n,k,i,j,ans;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			mp[a[i]].pb(i);
		}
		set<node> s;
		set<node> ::iterator it;
		ans=0;
		mem(now,0);
		node t;
		for(i=0;i<n;i++)
		{
			if(now[a[i]])
			{
				mp[a[i]].erase(mp[a[i]].begin());
				if(mp[a[i]].size()==0) mp[a[i]].pb(INF);
				it=s.begin();
				s.erase(it);
				t=node(a[i],mp[a[i]][0]);
				s.insert(t);
				continue;
			}
			if(k==0)
			{
				it=s.end();
				it--;
				now[(*it).id]--;
				s.erase(it);
				k++;
			}
			if(k>0)
			{
				ans++;
				now[a[i]]=1;
				mp[a[i]].erase(mp[a[i]].begin());
				if(mp[a[i]].size()==0) mp[a[i]].pb(INF);
				t=node(a[i],mp[a[i]][0]);
				s.insert(t);
				k--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}