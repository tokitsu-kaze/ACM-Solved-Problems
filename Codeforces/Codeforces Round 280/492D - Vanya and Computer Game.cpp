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
const int MAX=2e6+10;
const ll mod=1e9+7;
int ans[MAX];
int main()
{
	int n,a,b,i,j,x;
	ll t1,t2,l;
	while(~scanf("%d%d%d",&n,&a,&b))
	{
		mem(ans,0);
		l=1LL*a*b/__gcd(a,b);
		for(i=0,j=0;i<a&&j<b;)
		{
			t1=(i+1)*l/a;
			t2=(j+1)*l/b;
			if(t1<t2)
			{
				i++;
				ans[i+j]=1;
			}
			else if(t1>t2)
			{
				j++;
				ans[i+j]=2;
			}
			else
			{
				i++;
				ans[i+j]=3;
				j++;
				ans[i+j]=3;
			}
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			x%=(a+b);
			if(x==0) x=a+b;
			if(ans[x]==1) puts("Vanya");
			else if(ans[x]==2) puts("Vova");
			else puts("Both");
		}
	}
	return 0;
}