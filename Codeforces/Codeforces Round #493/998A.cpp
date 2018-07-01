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
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=5e5+10;
const ll mod=998244353;
int main()
{
	int n,a[22],s;
	while(~scanf("%d",&n))
	{
		s=0;
		for(int i=0;i<n;i++) cin>>a[i],s+=a[i];
		int flag=0;
		int pos[22];
		function<void(int,int)> dfs=[&](int x,int sum)
		{
			if(flag) return;
			if(x==n)
			{
				if(s-sum!=sum&&s-sum!=0&&sum!=0) flag=1;
				return;
			}
			pos[x]=0;
			dfs(x+1,sum);
			if(flag) return;
			pos[x]=1;
			dfs(x+1,sum+a[x]);
			if(flag) return;
			pos[x]=0;
		};
		dfs(0,0);
		vector<int> res;
		for(int i=0;i<n;i++)
		{
			if(pos[i]) res.push_back(i+1);
		}
		if(!sz(res))
		{
			puts("-1");
			continue;
		}
		printf("%d\n",sz(res));
		for(int i=0;i<sz(res);i++) printf("%d%c",res[i]," \n"[i==sz(res)-1]);
	}
	return 0;
}