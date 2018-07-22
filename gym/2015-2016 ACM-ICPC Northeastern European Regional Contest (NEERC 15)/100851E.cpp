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
const int MAX=1e6+10;
const ll mod=1e9+7;
int mp[55][55];
int main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	int n,m,i,j,ans,x,y,cnt;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<=14;i++)
		{
			for(j=0;j<=14;j++)
			{
				mp[i][j]=50;
			}
		}
		y=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			y=max(y,x);
			for(j=0;j<x;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		cnt=0;
		ans=0;
		for(i=0;i<y;i++)
		{
			for(j=0;j<n;j++)
			{
				if(mp[j][i]>=ans) ans+=mp[j][i],cnt++;
				if(mp[j][i]==50||cnt==m) goto end;
			}
		}
		end:;
		printf("%d\n",ans+(m-cnt)*50);
	}
	return 0;
}