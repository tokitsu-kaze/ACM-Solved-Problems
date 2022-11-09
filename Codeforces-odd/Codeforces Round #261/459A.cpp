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
int main()
{
	int i,x[2],y[2],n;
	for(i=0;i<2;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	if(x[0]==x[1])
	{
		n=abs(y[0]-y[1]);
		x[0]+=n;
		x[1]+=n;
		printf("%d %d %d %d\n",x[0],y[0],x[1],y[1]);
	}
	else if(y[0]==y[1])
	{
		n=abs(x[0]-x[1]);
		y[0]+=n;
		y[1]+=n;
		printf("%d %d %d %d\n",x[0],y[0],x[1],y[1]);
	}
	else
	{
		if(abs(x[0]-x[1])!=abs(y[0]-y[1])) puts("-1");
		else
		{
			printf("%d %d %d %d\n",x[0],y[1],x[1],y[0]);
		}
	}
	return 0;
}