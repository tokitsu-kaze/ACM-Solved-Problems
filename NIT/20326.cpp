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
const int MAX=6e3+10;
const ll mod=1e9+7;
vector<int> res;
void init()
{
	int i,a[]={2,3,5,7},t;
	res.clear();
	queue<int> q;
	for(i=0;i<4;i++) q.push(a[i]);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		res.pb(t);
		for(i=0;i<4;i++)
		{
			if(t%a[i]) q.push(t*a[i]);
		}
	}
	sort(all(res));
	res.resize(unique(all(res))-res.begin());
}
int main()
{
	int n,sz;
	init();
	sz=(int)sz(res);
	while(~scanf("%d",&n))
	{
		if(sz<n) puts("-1");
		else printf("%d\n",res[n-1]);
	}
	return 0;
}