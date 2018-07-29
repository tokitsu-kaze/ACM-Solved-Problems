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
const int MAX=1e5+10;
const ll mod=1e9+7;
int dp[2222][2222];
int LPS(char *s,int n)
{
	int i,j,len;
	for(i=1;i<=n;i++) dp[i][i]=1;
	for(len=2;len<=n;len++)
	{
		for(i=1;i<=n-len+1;i++)
		{
			j=i+len-1;
			if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
			else dp[i][j]=max({dp[i+1][j],dp[i][j-1],dp[i+1][j-1]});
		}
	}
	return dp[1][n];
}
int main()
{
	int i,len;
	char s[2222];
	while(~scanf("%s",s+1))
	{
		len=strlen(s+1);
		for(i=1;i<=len;i++)
		{
			if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
		}
		printf("%d\n",len-LPS(s,len));
	}
	return 0;
}