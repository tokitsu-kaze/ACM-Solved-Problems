////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-04-03 14:17:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1848
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1680KB
//////////////////System Comment End//////////////////
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
const int MAX=1e3+10;
const ll mod=1e9+7;
int f[22],sg[MAX],S[22];
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
	int i;
	f[1]=1;
	f[2]=2;
	for(i=3;;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>1000) break;
	}
	SG(1000,16);
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c)&&a+b+c)
	{
		if(sg[a]^sg[b]^sg[c]) puts("Fibo");
		else puts("Nacci");
	}
	return 0;
}