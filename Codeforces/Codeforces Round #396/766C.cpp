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
const int MAX=1e5+10;
const ll mod=1e9+7;
int dp[1011],limt[333],d[1011];
char s[1011];
bool check(int l,int r)
{
	int i,len=r-l+1;
	for(i=l;i<=r;i++)
	{
		if(len>limt[s[i]]) return 0;
	}
	return 1;
}
int main()
{
	int n,i,j,len;
	while(~scanf("%d",&n))
	{
		mem(limt,0);
		scanf("%s",s+1);
		for(i='a';i<='z';i++) scanf("%d",&limt[i]);
		mem(dp,0);
		mem(d,0x3f);
		dp[0]=1;
		d[0]=0;
		len=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				if(check(i-j+1,i))
				{
					dp[i]=(dp[i]+dp[i-j])%mod;
					d[i]=min(d[i],d[i-j]+1);
					len=max(len,j);
				}
			}
		}
		printf("%d\n",dp[n]);
		printf("%d\n",len);
		printf("%d\n",d[n]);
	}
	return 0;
}