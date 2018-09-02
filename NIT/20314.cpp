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
int main()
{
	int n,i,flag;
	double fz,fm,a[22],b[22];
	while(~scanf("%d",&n))
	{
		flag=0;
		fz=fm=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&a[i]);
			if(fabs(a[i])<eps) flag=1;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lf",&b[i]);
		}
		if(flag) puts("No");
		else
		{
			for(i=0;i<n;i++)
			{
				fz+=a[i]*b[i];
				fm+=b[i];
			}
			if(fz/fm>2.7) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}