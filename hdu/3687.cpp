////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-07 15:05:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3687
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1740KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define  _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,m,i,j,k,a,b,ans;
	while(~scanf("%d%d",&n,&m)&&n+m)
	{
		vector<int> v[66];
		for(i=1;i<=n*n;i++)
		{
			scanf("%d%d",&a,&b);
			v[a].pb(b);
		}
		for(i=1;i<=n;i++)
		{
			sort(all(v[i]));
		}
		ans=INF;
		for(j=n;j<=m;j++)
		{
			int now=0;
			for(i=1;i<=n;i++)
			{
				int p=j-n+1;
				for(k=0;k<sz(v[i]);k++,p++)
				{
					now+=abs(v[i][k]-p);
				}
			}
			ans=min(ans,now);
		}
		printf("%d\n",ans);
	}
	return 0;
}