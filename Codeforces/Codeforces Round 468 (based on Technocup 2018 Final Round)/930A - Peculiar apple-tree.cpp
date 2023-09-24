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
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int ans;
void bfs()
{
	queue<int> q;
	q.push(1);
	ans++;
	int i,sz,res,t;
	while(!q.empty())
	{
		sz=sz(q);
		res=0;
		while(sz--)
		{
			t=q.front();
			q.pop();
			for(i=0;i<sz(mp[t]);i++) q.push(mp[t][i]),res++;
		}
		ans+=res%2;
	}
}
int main()
{
	int n,i,x;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&x);
			mp[x].pb(i);
		}
		ans=0;
		bfs();
		printf("%d\n",ans);
	}
	return 0;
}