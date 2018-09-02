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
const int MAX=2e5+10;
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
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	int operator [](int x)
	{
		int res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
}t1,t2;
struct node
{
	int a,b,t;
	friend bool operator<(node a,node b)
	{
		if(a.a==b.a) return a.b>b.b;
		return a.a<b.a;
	}
}a[MAX];
vector<int> Hash;
int ans[MAX];
int getid(int x)
{
	return lower_bound(all(Hash),x)-Hash.begin()+1;
}
int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		Hash.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i].a,&a[i].b);
			a[i].t=i;
			Hash.pb(a[i].a);
			Hash.pb(a[i].b);
		}
		sort(all(Hash));
		Hash.resize(unique(all(Hash))-Hash.begin());
		t1.init(sz(Hash));
		t2.init(sz(Hash));
		for(i=1;i<=n;i++)
		{
			t2.update(getid(a[i].b),1);
		}
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++)
		{
			ans[a[i].t]=t1[getid(a[i].a)-1]+t2[getid(a[i].b)-1];
			t1.update(getid(a[i].a),1);
			t2.update(getid(a[i].b),-1);
		}
		for(i=1;i<=n;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
/*
3
3 5
2 3
3 3
4
4 9
3 5
5 6
7 7
*/