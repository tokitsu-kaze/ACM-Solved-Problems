#include <bits/stdc++.h>
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
const int MAX=3e6+10;
const ll mod=1e9+7;
vector<int> v[MAX],mp[MAX];
int degree[MAX],tot;
void topsort()
{
	int i,t;
	queue<int> q;
	for(i=1;i<=tot;i++)
	{
	//	cout<<degree[i]<<endl;
		if(degree[i]==0) q.push(i);
	}
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<sz(mp[t]);i++)
		{
			int to=mp[t][i];
			degree[to]--;
			if(degree[to]==0) q.push(to);
		}
	}
}
hash_map<string,int,str_hash> Hash;
int main()
{
	int i,j;
	char s[1111];
	queue<int> q;
	tot=0;
	while(~scanf("%s",s))
	{
		if(s[0]=='0')
		{
			int t=q.front();
			q.pop();
			while(!q.empty())
			{
				v[t].pb(q.front());
				q.pop();
			}
			v[t].pb(INF);
		}
		else
		{
			if(!Hash[s]) Hash[s]=++tot;
			q.push(Hash[s]);
		}
	}
	mem(degree,-1);
	for(i=1;i<=tot;i++)
	{
		if(sz(v[i]))
		{
			degree[i]=0;
			for(j=0;j<sz(v[i]);j++)
			{
				if(v[i][j]==INF) continue;
				mp[v[i][j]].pb(i);
				degree[i]++;
			}
		}
	}
	topsort();
	int ans=0;
	for(i=1;i<=tot;i++)
	{
		ans+=(degree[i]==0);
	}
	printf("%d\n",ans);
	return 0;
}