#include <bits/stdc++.h>
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e6+10;
const ll mod=1e9+7;
struct node
{
	int a,b,c;
	friend bool operator<(node a,node b)
	{
		if(a.a==b.a) return a.b<b.b;
		return a.a<b.a;
	}
}a[111];
int main()
{
	int n,i,j,x;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			a[i]={x+i,x,i};
		}
		sort(a+1,a+1+n);
		printf("%d",a[1].c);
		for(i=2;i<=n;i++)
		{
			printf(" %d",a[i].c);
		}
		puts("");
	}
	return 0;
}
