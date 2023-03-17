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
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=1e9+7;
char s[111];
int main()
{
	int len,i,j,dp[3];
	while(~scanf("%s",s))
	{
		len=strlen(s);
		mem(dp,0);
		for(i=0;i<len;i++)
		{
			if(s[i]=='Q')
			{
				dp[0]++;
				dp[2]+=dp[1];
			}
			else if(s[i]=='A') dp[1]+=dp[0];
		}
		printf("%d\n",dp[2]);
	}
	return 0;
}