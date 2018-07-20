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
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	ll w,v,d1,d2;
	void input()
	{
		scanf("%lld%lld",&w,&v);
		d1=min(w,v);
		d2=w*2;
		if(d2>v) d2=v;
	}
	friend bool operator <(node a,node b)
	{
		return (a.d2-a.d1)<(b.d2-b.d1);
	}
}a[MAX];
int main()
{
	ll n,k,i,ans;
	node t;
	while(~scanf("%lld%lld",&n,&k))
	{
		priority_queue<node> q;
		for(i=0;i<n;i++)
		{
			a[i].input();
			q.push(a[i]);
		}
		ans=0;
		while(!q.empty())
		{
			t=q.top();
			q.pop();
			if(k>0)
			{
				ans+=t.d2;
				k--;
			}
			else ans+=t.d1;
	//		cout<<ans<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}