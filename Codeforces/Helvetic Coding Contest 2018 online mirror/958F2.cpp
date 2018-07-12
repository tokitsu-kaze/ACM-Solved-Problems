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
const int MAX=2e5+10;
const ll mod=1e9+7;
int v[MAX],t[MAX],cnt[MAX];
int main()
{
	int n,m,i,j,k,ans,now,num;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++) scanf("%d",&v[i]);
		for(i=1;i<=m;i++) scanf("%d",&t[i]);
		ans=INF;
		now=0;
		num=0;
		mem(cnt,0);
		for(i=1;i<=m;i++)
		{
			if(!t[i]) num++;
		}
		for(i=1,j=1;i<=n;i++)
		{
			if(i>=j)
			{
				cnt[v[i]]++;
				j=i+1;
				if(cnt[v[i]]==t[v[i]]) num++;
				else if(cnt[v[i]]>t[v[i]]) now++;
			}
			while(j<=n&&num<m)
			{
				cnt[v[j]]++;
				if(cnt[v[j]]==t[v[j]]) num++;
				else if(cnt[v[j]]>t[v[j]]) now++;
				j++;
			}
			if(num==m) ans=min(ans,now);
			cnt[v[i]]--;
			if(cnt[v[i]]==t[v[i]]-1) num--;
			else if(cnt[v[i]]>=t[v[i]]) now--;
		}
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}