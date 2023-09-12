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
		set<int> s;
		set<int> ::iterator it,del;
		ans=0;
		mem(now,0);
		for(i=0;i<n;i++)
		{
			if(now[a[i]])
			{
				mp[a[i]].erase(mp[a[i]].begin());
				continue; 
			}
			if(k==0)
			{
				int maxx=0;
				for(it=s.begin();it!=s.end();it++)
				{
					if(mp[*it].size()==0)
					{
						del=it;
						break;
					}
					if(mp[*it][0]>maxx)
					{
						del=it;
						maxx=mp[*it][0];
					}
				}
				now[*del]--;
				s.erase(del);
				k++;
			}
			if(k>0)
			{
				ans++;
				now[a[i]]=1;
				s.insert(a[i]);
				mp[a[i]].erase(mp[a[i]].begin());
				k--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}