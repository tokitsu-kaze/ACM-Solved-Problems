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
const int MAX=2e5+10;
const ll mod=1e9+7;
struct Fenwick_Tree
{
	int bit[MAX];
	int n;
	void init(int _n){n=_n;mem(bit,0);}
	int lowbit(int x){return x&(-x);}
	void insert(int x,int v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	int get(int x)
	{
		int res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	int query(int l,int r)
	{
		return get(r)-get(l-1);
	}
}t;
int flag[MAX];
int getpos(int x)
{
	int l,r,mid;
	l=1;
	r=t.n;
	while(l<r)
	{
		mid=(l+r)>>1;
		int res=mid-t.query(1,mid);
		if(res==x&&!flag[mid]) return mid;
		else if(res<x) l=mid+1;
		else r=mid;
	}
	return l;
}
int main()
{
	int n,m,i,l,r,cnt;
	string s,ans;
	char op[11];
	while(~scanf("%d%d",&n,&m))
	{
		cin>>s;
		set<int> pos[333];
		for(i=0;i<n;i++) pos[s[i]].insert(i+1);
		t.init(n);
		mem(flag,0);
		while(m--)
		{
			scanf("%d%d%s",&l,&r,op);
			set<int> ::iterator it;
			l=getpos(l);
			r=getpos(r);
			it=pos[op[0]].lower_bound(l);
			cnt=0;
	//		cout<<l<<" "<<r<<endl;
			for(;it!=pos[op[0]].end();)
			{
				if(*it>r) break;
				t.insert(*it,1);
				flag[*it]=1;
				pos[op[0]].erase(it++);
				cnt++;
			}
		}
		ans="";
		for(i=0;i<n;i++)
		{
			if(!flag[i+1]) ans+=s[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}