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
const long double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
char mp[111][111];
int main()
{
	int n,k,i,j;
	while(~scanf("%d%d",&n,&k))
	{
		mem(mp,'.');
		if(k&1)
		{
			puts("YES");
			if(k>=n-2)
			{
				k-=n-2;
				for(i=1;i<=n-2;i++) mp[1][i]='#';
				for(i=1;i<=k/2;i++) mp[2][i]=mp[2][n-i-1]='#';
			}
			else
			{
				mp[1][n/2]='#';
				k--;
				for(i=1;i<=k/2;i++) mp[2][i]=mp[2][n-i-1]='#';
			}
			
			for(i=0;i<4;i++)
			{
				for(j=0;j<n;j++)
				{
					putchar(mp[i][j]);
				}
				puts("");
			}
		}
		else
		{
			puts("YES");
			for(i=1;i<=k/2;i++) mp[1][i]=mp[2][i]='#';
			for(i=0;i<4;i++)
			{
				for(j=0;j<n;j++)
				{
					putchar(mp[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}