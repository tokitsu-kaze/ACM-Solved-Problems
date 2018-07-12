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
const int MAX=1e3+10;
const ll mod=1e9+7;
struct node
{
	int d,a,b;
	friend bool operator <(node a,node b)
	{
		return a.d<b.d;
	}
}a[MAX];
int main()
{
	int n,x,y,i;
	ll ans;
	while(~scanf("%d%d%d",&n,&x,&y))
	{
		ans=0;
		priority_queue<node> q;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i].a);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i].b);
			a[i].d=abs(a[i].a-a[i].b);
			q.push(a[i]);
		}
		node t;
		while(x+y)
		{
			t=q.top();
			q.pop();
			if(x&&y)
			{
				if(x>y)
				{
					if(abs(t.a-1-t.b)<abs(t.a+1-t.b)) t.a--;
					else t.a++;
					x--;
				}
				else
				{
					if(abs(t.a-t.b+1)<abs(t.a-t.b-1)) t.b--;
					else t.b++;
					y--;
				}
			}
			else if(x)
			{
				if(abs(t.a-1-t.b)<abs(t.a+1-t.b)) t.a--;
				else t.a++;
				x--;
			}
			else if(y)
			{
				if(abs(t.a-t.b+1)<abs(t.a-t.b-1)) t.b--;
				else t.b++;
				y--;
			}
			t.d=abs(t.a-t.b);
			q.push(t);
		}
		while(!q.empty())
		{
			t=q.top();
			q.pop();
			ans+=1LL*t.d*t.d;
		}
		printf("%lld\n",ans);
	}
	return 0;
}