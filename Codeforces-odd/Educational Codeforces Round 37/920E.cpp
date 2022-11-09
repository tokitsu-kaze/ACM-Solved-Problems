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
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
int ban[MAX];
vector<int> mp[MAX];
int flag[MAX],n;
set<int> s;
set<int> ::iterator it;
int bfs(int x)
{
	int i,t,res=0;
	queue<int> q;
	q.push(x);
	flag[x]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		res++;
		for(i=0;i<sz(mp[t]);i++) ban[mp[t][i]]=1;
		for(it=s.begin();it!=s.end();)
		{
			if(*it==t) s.erase(it++);
			else if(!ban[*it])
			{
				flag[*it]=1;
				q.push(*it);
				s.erase(it++);
			}
			else it++;
		}
		for(i=0;i<sz(mp[t]);i++) ban[mp[t][i]]=0;
	}
	return res;
}
int main()
{
	int m,a,b,i;
	while(~scanf("%d%d",&n,&m))
	{
		s.clear();
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			s.insert(i);
		}
		mem(flag,0);
		mem(ban,0);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			mp[b].pb(a);
		}
		vector<int> ans;
		for(i=1;i<=n;i++)
		{
			if(!flag[i]) ans.pb(bfs(i));
		}
		sort(all(ans));
		printf("%d\n",sz(ans));
		for(i=0;i<sz(ans);i++) printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
	}
	return 0;
}