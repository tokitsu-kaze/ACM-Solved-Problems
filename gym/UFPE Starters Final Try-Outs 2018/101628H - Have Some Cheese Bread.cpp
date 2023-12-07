#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
struct node
{
	int id,v;
	node(){}
	node(int a,int b) :id(a),v(b){}
};
vector<int> mp[MAX];
int flag[MAX],dis[MAX],cnt[MAX];
int n;
int spfa(int f)
{
	int i,sz,to;
	queue<node> q;
	node t;
	mem(dis,f*(0x3f));
	mem(flag,0);
	dis[1]=cnt[1];
	flag[1]=1;
	q.push(node(1,cnt[1]));
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		flag[t.id]=0;
		sz=sz(mp[t.id]);
		for(i=0;i<sz;i++)
		{
			to=mp[t.id][i];
			if(dis[to]*f>(dis[t.id]+cnt[to])*f)
			{
				dis[to]=dis[t.id]+cnt[to];
				if(!flag[to])
				{
					q.push(node(to,dis[to]));
					flag[to]=1;
				}
			}
		}
	}
	return dis[n];
}
int main()
{
	int k,m,i,a,b;
	while(~scanf("%d%d%d",&n,&k,&m))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			cnt[i]=0;
		}
		while(k--)
		{
			scanf("%d",&a);
			cnt[a]++;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mp[a].pb(b);
		}
		printf("%d %d\n",spfa(1),spfa(-1));
	}
	return 0;
}