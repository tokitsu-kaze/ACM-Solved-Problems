#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e6+10;
const ll mod=998244353;
/****************************************  head  ****************************************/
int main()
{
	int n,m,i,j,a[2222],mp[2222],cnt,ans,tmp,flag[2222];
	while(~scanf("%d%d",&n,&m))
	{
		mem(mp,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<=m) mp[a[i]]++;
		}
		cnt=0;
		tmp=n/m;
		mem(flag,0);
		for(i=1;i<=m;i++)
		{
			if(!mp[i]) continue;
			cnt=min(mp[i],tmp);
			for(j=1;j<=n;j++)
			{
				if(!cnt) break;
				if(a[j]==i)
				{
					cnt--;
					flag[j]=1;
				}
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(flag[i]) continue;
			for(j=1;j<=m;j++)
			{
				if(mp[j]<tmp)
				{
					ans++;
					mp[j]++;
					a[i]=j;
					break;
				}
			}
		}
		printf("%d %d\n",tmp,ans);
		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}