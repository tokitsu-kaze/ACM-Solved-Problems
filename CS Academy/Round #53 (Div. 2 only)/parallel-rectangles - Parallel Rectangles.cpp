#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define PII pair<int,int>
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
vector<int> v,x[MAX];
int flag[MAX];
map<PII,int> mp;
map<PII,int> ::iterator it;
int main()
{
	int lim=20;
	int n,i,j,k,xx,yy,cnt;
	ll ans;
	while(~scanf("%d",&n))
	{
		mp.clear();
		v.clear();
		for(i=1;i<=1e5;i++)
		{
			x[i].clear();
		}
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&xx,&yy);
			if(!flag[xx])
			{
				flag[xx]=1;
				v.pb(xx);
			}
			x[xx].pb(yy);
		}
		ans=0;
		for(i=0;i<sz(v);i++)
		{
			if(sz(x[v[i]])>=lim)
			{
				mem(flag,0);
				for(j=0;j<sz(x[v[i]]);j++)
				{
					flag[x[v[i]][j]]=1;
				}
				for(j=0;j<sz(v);j++)
				{
					cnt=0;
					if(j>=i&&sz(x[v[j]])>=lim) continue;
					for(k=0;k<sz(x[v[j]]);k++)
					{
						cnt+=flag[x[v[j]][k]];
					}
					ans+=(ll)cnt*(cnt-1)/2;
				}
			}
			else
			{
				sort(all(x[v[i]]));
				for(j=0;j<sz(x[v[i]]);j++)
				{
					for(k=j+1;k<sz(x[v[i]]);k++)
					{
						mp[MP(x[v[i]][j],x[v[i]][k])]++;
					}
				}
			}
		}
		for(it=mp.begin();it!=mp.end();it++)
		{
			ans+=(ll)it->se*(it->se-1)/2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}