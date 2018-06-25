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
const int MAX=2e4+10;
const ll mod=1e9+7;
struct node
{
	int a,b;
	node(){}
	node(int _a,int _b) :a(_a),b(_b){}
	void input()
	{
		scanf("%d%d",&a,&b);
	}
	friend bool operator <(node a,node b)
	{
		if(a.a==b.a) return a.b>b.b;
		return a.a<b.a;
	}
}a[MAX];
int main()
{
	int n,i,ans,maxx;
	scanf("%d",&n);
	for(i=0;i<n;i++) a[i].input();
	sort(a,a+n);
	ans=0;
	maxx=-1;
	for(i=0;i<n;i++)
	{
		ans+=(a[i].b<maxx);
		maxx=max(maxx,a[i].b);
	}
	printf("%d\n",ans);
	return 0;
}
