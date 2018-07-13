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
int main()
{
	int t,n,k,i,flag[222],x,ans,tag;
	scanf("%d",&t);
	while(t--)
	{
		mem(flag,0);
		scanf("%d%d",&n,&k);
		set<int> s,tmp;
		set<int> ::iterator it;
		for(i=1;i<=k;i++)
		{
			scanf("%d",&x);
			flag[x]=1;
			s.insert(x);
		}
		ans=1;
		while(1)
		{
			tag=0;
			for(i=1;i<=n;i++)
			{
				if(!flag[i]) tag=1;
			}
			if(!tag) break;
			ans++;
			tmp.clear();
			for(it=s.begin();it!=s.end();it++)
			{
				if(*it<1||*it>n) continue;
				flag[*it-1]=flag[*it+1]=1;
				tmp.insert(*it-1);
				tmp.insert(*it+1);
			}
			for(it=tmp.begin();it!=tmp.end();it++)
			{
				s.insert(*it);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}