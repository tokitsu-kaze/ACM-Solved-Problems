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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
struct node
{
	ll l,r,cost;
	void input()
	{
		scanf("%lld%lld%lld",&l,&r,&cost);
	}
	friend bool operator <(node a,node b)
	{
		return a.r>b.r;
	}
}a[MAX];
int cmp(node a,node b)
{
	return a.l<b.l;
}
ll res[MAX];
int main()
{
	ll n,x,i,ans;
	while(~scanf("%lld%lld",&n,&x))
	{
		for(i=0;i<n;i++)
		{
			a[i].input();
		}
		sort(a,a+n,cmp);
		priority_queue<node> q;
		ans=1e10;
		mem(res,0x3f);
		for(i=0;i<n;i++)
		{
			while(!q.empty()&&q.top().r<a[i].l)
			{
				node temp;
				temp=q.top();
				q.pop();
				res[temp.r-temp.l+1]=min(res[temp.r-temp.l+1],temp.cost);
			}
			ll t=x-(a[i].r-a[i].l+1);
			if(t<0||res[t]==1e10) continue;
			ans=min(ans,res[t]+a[i].cost);
			q.push(a[i]);
		}
		printf("%lld\n",ans==1e10?-1:ans);
	}
	return 0;
}