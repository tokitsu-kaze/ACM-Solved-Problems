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
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int main()
{
	int n,ans,i,a[2222],flag[2222],k;
	while(~scanf("%d%d",&n,&k))
	{
		priority_queue<PII > q;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			q.push(MP(a[i],i));
		}
		mem(flag,0);
		ans=0;
		for(i=1;i<=k;i++)
		{
			auto t=q.top();
			q.pop();
			ans+=t.fi;
			flag[t.se]=1;
	//		cout<<t.se<<endl;
		}
		printf("%d\n",ans);
		VI res;
		int pre=0;
		for(i=1;i<=n;i++)
		{
			if(flag[i])
			{
				if(sz(res)==k-1) continue;
				res.pb(i-pre);
				pre=i;
			}
		}
		res.pb(n-pre);
		for(i=1;i<=k;i++)
		{
			printf("%d%c",res[i-1]," \n"[i==k]);
		}
	}
	return 0;
}