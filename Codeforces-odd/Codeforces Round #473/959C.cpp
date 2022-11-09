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
void work1(int n)
{
	if(n<6)
	{
		puts("-1");
		return;
	}
	printf("1 2\n");
	printf("1 3\n");
	printf("1 4\n");
	for(int i=5;i<=n;i++)
	{
		printf("2 %d\n",i);
	}
}
void work2(int n)
{
	for(int i=2;i<=n;i++)
	{
		printf("1 %d\n",i);
	}
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		work1(n);
		work2(n);
	}
	return 0;
}