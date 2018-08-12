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
const int MAX=1e4+10;
const ll mod=1e9+7;
int f[105],sg[MAX],S[105];
void SG(int n,int m)
{
	int i,j;
	mem(sg,0);
	for(i=1;i<=n;i++)
	{
		mem(S,0);
		for(j=1;f[j]<=i&&j<=m;j++)
		{
			S[sg[i-f[j]]]=1;
		}
		for(j=0;;j++)
		{
			if(!S[j])
			{
				sg[i]=j;
				break;
			}
		}
	}
}
int main()
{
	int k,i,x,m,n,res;
	string ans;
	while(~scanf("%d",&k)&&k)
	{
		for(i=1;i<=k;i++) scanf("%d",&f[i]);
		sort(f+1,f+1+k);
		SG(10000,k);
		scanf("%d",&m);
		ans="";
		while(m--)
		{
			scanf("%d",&n);
			res=0;
			for(i=1;i<=n;i++)
			{
				scanf("%d",&x);
				res^=sg[x];
			}
			if(res) ans+='W';
			else ans+='L';
		}
		cout<<ans<<"\n";
	}
	return 0;
}