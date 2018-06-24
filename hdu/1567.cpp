////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-01-27 14:13:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1567
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:6048KB
//////////////////System Comment End//////////////////
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
bool mp[2111][2111];
bool check(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(!mp[i][j]) return 0;
		}
	}
	return 1;
}
char s[1111];
int vis[2111];
int main()
{
	int n,i,j,a,b,ok;
	while(~scanf("%d",&n))
	{
		getchar();
		mem(mp,0);
		ok=1;
		for(i=0;i<n-1;i++)
		{
			mem(vis,0);
			for(j=1;j<=n/2;j++)
			{
				scanf("%d-%d",&a,&b);
				vis[a]++;
				vis[b]++;
				mp[a][b]++;
				mp[b][a]++;
			}
			for(j=1;j<=n;j++)
			{
				if(vis[j]!=1) ok&=0;
			}
		}
		if(check(n)&&ok) puts("Yes");
		else puts("No");
	}
	return 0;
}