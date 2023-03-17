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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
struct Fenwick_Tree
{
	int bit[MAX];
	int n;
	void init(int _n){n=_n;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void update(int x,int v)
	{
		while(x<=n)
		{
			bit[x]^=v;
			x+=lowbit(x);
		}
	}
	int operator [](int x)
	{
		int res=0;
		while(x)
		{
			res^=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
}t;
int bit[MAX],v[MAX];
struct node
{
	int l,r,id;
	void input(int i)
	{
		scanf("%d%d",&l,&r);
		id=i;
	}
	friend bool operator <(node a,node b)
	{
		return a.r<b.r;
	}
}a[MAX];
int ans[MAX];
int main()
{
	int n,i,q,r,pre;
	while(~scanf("%d",&n))
	{
		t.init(n);
		bit[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			bit[i]=v[i];
			bit[i]^=bit[i-1]; 
		}
		scanf("%d",&q);
		for(i=1;i<=q;i++) a[i].input(i);
		sort(a+1,a+1+q);
		map<int,int> last;
		r=1;
		for(i=1;i<=q;i++)
		{
			while(r<=a[i].r)
			{
				if(last.count(v[r]))
				{
					pre=last[v[r]];
					t.update(pre,v[pre]);
				}
				t.update(r,v[r]);
				last[v[r]]=r;
				r++;
			}
			ans[a[i].id]=bit[a[i].r]^bit[a[i].l-1]^t[a[i].r]^t[a[i].l-1];
		}
		for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	}
	return 0;
}