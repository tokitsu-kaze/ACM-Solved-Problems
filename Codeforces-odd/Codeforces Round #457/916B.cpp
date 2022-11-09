#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ll x,k,i,t;
	while(~scanf("%lld%lld",&x,&k))
	{
		priority_queue<ll> q;
		for(i=0;(1LL<<i)<=x;i++)
		{
			if(x&(1LL<<i)) q.push(i);
		}
		if(sz(q)>k) puts("No");
		else
		{
			puts("Yes");
			while(sz(q)<k)
			{
				t=q.top();
				q.pop();
				q.push(t-1);
				q.push(t-1);
			}
			vector<ll> ans;
			while(!q.empty())
			{
				t=q.top();
				q.pop();
				ans.pb(t);
			}
			for(i=1;i<sz(ans)-1;i++)
			{
				if(ans[i]==ans[0]) continue;
				if(ans[i-1]==ans[i])
				{
					ans[i-1]++;
					ans[i]=ans[sz(ans)-1]-1;
					ans[sz(ans)-1]--;
				}
			}
			sort(all(ans),cmp);
			printf("%lld",ans[0]);
			for(i=1;i<sz(ans);i++) printf(" %lld",ans[i]);
			puts("");
		}
	}
	return 0;
}