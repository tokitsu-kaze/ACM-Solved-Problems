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
char mp[5111][5111];
int main()
{
	int n,i,j,k,now;
	while(~scanf("%d",&n))
	{
		mem(mp,0);
		for(i=1,j=0;i<=n;i++)
		{
			mp[0][j++]=' ';
			mp[0][j++]='_';
			if(i!=n) mp[0][j++]=' ';
			if(i!=n) mp[0][j++]=' ';
		}
		for(i=1,j=0;i<=n;i++)
		{
			mp[1][j++]='/';
			mp[1][j++]=' ';
			mp[1][j++]='\\';
			if(i!=n) mp[1][j++]='_';
		}
	/*	for(i=1,j=0;i<=n;i++)
		{
			mp[2][j++]='\\';
			mp[2][j++]='_';
			mp[2][j++]='/';
			if(i!=n) mp[2][j++]=' ';
		}*/
		
		now=2;
		for(i=n;i;i--)
		{
			k=0;
			for(j=1;j<=(n-i)*2;j++)
			{
				mp[now][k++]=' ';
			}
			for(j=1;j<=i;j++)
			{
				mp[now][k++]='\\';
				mp[now][k++]='_';
				mp[now][k++]='/';
				if(j!=i) mp[now][k++]=' ';
			}
			now++;
		}
		
		
		for(i=0;i<now;i++) puts(mp[i]);
	}
	return 0;
}