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
const int MAX=1e6+10;
const ll mod=1e9+7;
char mp[55][55];
int main()
{
	int a[5],i,j,p;
	while(~scanf("%d",&a[0]))
	{
		for(i=1;i<4;i++) scanf("%d",&a[i]);
		a[0]--;
		a[1]--;
		mem(mp,0);
		for(i=0;i<25;i++)
		{
			for(j=0;j<50;j++)
			{
				mp[i][j]='A';
			}
		}
		p=1;
		i=1;
		while(p<4)
		{
			for(j=0;j<50;j+=2)
			{
				while(p<4&&!a[p]) p++;
				if(p==4) break;
				mp[i][j]='A'+p;
				a[p]--;
			}
			i+=2;
		}
		for(i=25;i<50;i++)
		{
			for(j=0;j<50;j++)
			{
				mp[i][j]='B';
			}
		}
		i=26;
		while(a[0])
		{
			for(j=0;j<50;j+=2)
			{
				if(!a[0]) break;
				a[0]--;
				mp[i][j]='A';
			}
			i+=2;
		}
		puts("50 50");
		for(i=0;i<50;i++) puts(mp[i]);
	}
	return 0;
}
