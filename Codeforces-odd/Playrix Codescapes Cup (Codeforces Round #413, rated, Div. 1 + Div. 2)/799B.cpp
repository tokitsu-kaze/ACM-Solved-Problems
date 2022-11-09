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
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=200000+10;
const ll mod=1e6;
int p[MAX],flag[MAX];
struct cmp
{
	bool operator()(int a,int b)
	{
		return p[a]<p[b];
	}
};
struct node
{
	set<int,cmp> s;
}s[5];
int main()
{
	int n,i,m,a,b,q;
	while(~scanf("%d",&n))
	{
		mem(p,0);
		mem(flag,0);
		for(i=0;i<4;i++)
		{
			s[i].s.clear();
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&p[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			s[a].s.insert(i);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&b);
			s[b].s.insert(i);
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&q);
			while(s[q].s.size())
			{
				if(flag[*s[q].s.begin()])
				{
					s[q].s.erase(s[q].s.begin());
				}
				else break;
			}
			if(!i)
			{
				if(s[q].s.size())
				{
					if(!flag[*s[q].s.begin()]) printf("%d",p[*s[q].s.begin()]);
					flag[*s[q].s.begin()]=1;
					s[q].s.erase(s[q].s.begin());
				}
				else printf("-1");
			}
			else
			{
				if(s[q].s.size())
				{
					if(!flag[*s[q].s.begin()]) printf(" %d",p[*s[q].s.begin()]);
					flag[*s[q].s.begin()]=1;
					s[q].s.erase(s[q].s.begin());
				}
				else printf(" -1");
			}
		}
		puts("");
	} 
	return 0;
}