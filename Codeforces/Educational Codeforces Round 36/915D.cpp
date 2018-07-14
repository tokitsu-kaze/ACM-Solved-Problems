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
vector<int> mp[505];
int in[505],n;
bool topsort()
{
	int i,x,to,res=0;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(!in[i]) q.push(i);
	}
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		res++;
		for(i=0;i<sz(mp[x]);i++)
		{
			to=mp[x][i];
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
	return res==n;
}
int main()
{
	int m,i,j,a,b,indegree[505];
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			indegree[i]=0;
			mp[i].clear();
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
			indegree[b]++;
		}
		for(i=1;i<=n;i++)
		{
			if(!indegree[i]) continue;
			for(j=1;j<=n;j++) in[j]=indegree[j];
			in[i]--;
			if(topsort())
			{
				puts("YES");
				goto end;
			}
		}
		puts("NO");
		end:;
	}
	return 0;
}