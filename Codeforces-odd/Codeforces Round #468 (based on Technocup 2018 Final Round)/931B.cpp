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
	int a,b,n,ans,i,x,y,sz;
	while(~scanf("%d%d%d",&n,&a,&b))
	{
		if(a>b) swap(a,b);
		queue<int> q;
		for(i=1;i<=n;i++) q.push(i);
		ans=0;
		while(sz(q))
		{
			sz=sz(q)/2;
			ans++;
			while(sz--)
			{
				x=q.front();
				q.pop();
				y=q.front();
				q.pop();
				if(x==a||x==b) q.push(x);
				else q.push(y);
				if(x==a&&y==b) goto end;
			}
		}
		end:;
		if(sz(q)==1) puts("Final!");
		else printf("%d\n",ans);
	}
	return 0;
}