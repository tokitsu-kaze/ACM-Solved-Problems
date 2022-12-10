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
const int MAX=2e5+10;
const ll mod=1e9+7;
int a[MAX],st[MAX];
int main()
{
	int n,i,k,tot;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		tot=0;
		for(i=1;i<n;i++)
		{
			if(a[i+1]>a[i]&&a[i+1]-a[i]<=k);
			else st[tot++]=a[i];
			while(tot&&a[i+1]>st[tot-1]&&a[i+1]-st[tot-1]<=k) tot--;
		}
		printf("%d\n",tot+1);
	}
	return 0;
}
