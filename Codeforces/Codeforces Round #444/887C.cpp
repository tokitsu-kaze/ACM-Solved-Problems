#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
struct ll_hash{size_t operator()(ll x)const{return x;}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int a[25],x[3][8]={{1,3,5,7,9,11,24,22},{13,14,5,6,17,18,21,22},{1,2,18,20,12,11,15,13}};
int flag;
void judge()
{
	int i,j;
	for(i=1;i<=6;i++)
	{
		for(j=(4*(i-1)+1);j<4*i;j++)
		{
			if(a[j]!=a[4*i]) return;
		}
	}
	puts("YES");
	flag=1;
}
void copy(int i)
{
	int v=a[x[i][0]],v2=a[x[i][1]],j;
	for(j=0;j<6;j++)
	{
		a[x[i][j]]=a[x[i][j+2]];
	}
	a[x[i][6]]=v;
	a[x[i][7]]=v2;
}
int main()
{
	int i,j;
	for(i=1;i<=24;i++)
	{
		scanf("%d",&a[i]);
	}
	flag=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			copy(i);
			judge();
			copy(i);
		}
	}
	if(!flag) puts("NO");
	return 0;
}