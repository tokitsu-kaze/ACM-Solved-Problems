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
const ll mod=1e6;
ll bit[MAX],n;
ll lowbit(ll x)
{
	return x&(-x);
}
void update(ll k,ll v)
{
	while(k<=n)
	{
		bit[k]+=v;
		k+=lowbit(k);
	}
}
ll getsum(ll k)
{
	ll res=0;
	while(k)
	{
		res+=bit[k];
		k-=lowbit(k);
	}
	return res;
}
vector<ll> mp[MAX];
int main()
{
	ll i,j,ans,a,pre;
	while(~scanf("%lld",&n))
	{
		set<ll> s;
		set<ll> ::iterator it;
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a);
			mp[a].pb(i);
			s.insert(a);
			bit[i]=0;
		}
		pre=0;
		ans=0;
		for(it=s.begin();it!=s.end();it++)
		{
			for(j=0;j<mp[*it].size();j++)
			{
				if(mp[*it][j]<pre) mp[*it][j]+=MAX;
				else break;
			}
			sort(mp[*it].begin(),mp[*it].end());
			for(j=0;j<mp[*it].size();j++)
			{
				if(mp[*it][j]>MAX) mp[*it][j]-=MAX;
				if(mp[*it][j]>pre)
				{
					if(!pre) ans+=mp[*it][j];
					else ans+=mp[*it][j]-pre-(getsum(mp[*it][j])-getsum(pre-1))+1;
				}
				else
				{
					ans+=mp[*it][j]-getsum(mp[*it][j]-1)+(n-pre+1-(getsum(n)-getsum(pre-1)));
				}
				update(mp[*it][j],1);
				pre=mp[*it][j];
			}
	//		cout<<ans<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}