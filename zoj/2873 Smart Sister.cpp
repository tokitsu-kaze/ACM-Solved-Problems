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
const int MAX=1e5+10;
const ll mod=1e9+7;
ll a[MAX];
map<ll,ll> mp;
void init()
{
	mem(a,0);
	mp.clear();
	ll cnt=0,t,next;
	priority_queue<ll,vector<ll>,greater<ll> > q;
	q.push(2);
	q.push(3);
	q.push(5);
	q.push(7);
	a[cnt++]=1;
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		a[cnt++]=t;
		mp[t]=1;
		next=t*2;
		if(next<=1e18&&!mp[next])
		{
			mp[next]=1;
			q.push(next);
		}
		next=t*3;
		if(next<=1e18&&!mp[next])
		{
			mp[next]=1;
			q.push(next);
		}
		next=t*5;
		if(next<=1e18&&!mp[next])
		{
			mp[next]=1;
			q.push(next);
		}
		next=t*7;
		if(next<=1e18&&!mp[next])
		{
			mp[next]=1;
			q.push(next);
		}
//		cout<<cnt<<"  "<<t<<endl;
	}
}
int main()
{
	ll t,n;
	init();
	while(~scanf("%lld",&t))
	{
		while(t--)
		{
			scanf("%lld",&n);
			printf("%lld\n",a[n-1]);
		}
	}
	return 0;
}