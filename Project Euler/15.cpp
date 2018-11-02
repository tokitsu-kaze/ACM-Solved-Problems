#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
ll dp[22][22];
int main()
{
	int i,j,n=21;
	for(i=0;i<n;i++) dp[i][0]=dp[0][i]=1;
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	printf("%lld\n",dp[n-1][n-1]);
	return 0;
} 
/*

137846528820

*/