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
const int MAX=3e5+10;
const ll mod=1e9+7;
struct Trie
{
	int root,tot,ls[MAX*31],rs[MAX*31],val[MAX*31],cnt[MAX*31];
	void init()
	{
		root=0;
		ls[0]=rs[0]=0;
		val[0]=cnt[0]=0; 
		tot=1;
	}
	int newnode()
	{
		ls[tot]=rs[tot]=0;
		val[tot]=0;
		return tot++;
	}
	void Insert(int &x,int pos,int v)
	{
		if(!x) x=newnode();
		if(pos<0)
		{
			cnt[x]++;
			val[x]=v;
			return;
		}
		if((v>>pos)&1) Insert(rs[x],pos-1,v);
		else Insert(ls[x],pos-1,v);
		cnt[x]=cnt[ls[x]]+cnt[rs[x]];
	}
	void Delete(int x,int pos,int v)
	{
		if(pos<0)
		{
			cnt[x]--;
			return;
		}
		if((v>>pos)&1) Delete(rs[x],pos-1,v);
		else Delete(ls[x],pos-1,v);
		cnt[x]=cnt[ls[x]]+cnt[rs[x]];
	}
	int query(int x,int pos,int v)
	{
		if(pos<0) return val[x];
		int temp=(v>>pos)&1;
		if(temp)
		{
			if(cnt[rs[x]]) return query(rs[x],pos-1,v);
			else return query(ls[x],pos-1,v);
		}
		else
		{
			if(cnt[ls[x]]) return query(ls[x],pos-1,v);
			else return query(rs[x],pos-1,v);
		}
	}
}t;
int a[MAX];
int main()
{
	int n,i,x,ans;
	while(~scanf("%d",&n))
	{
		t.init();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			t.Insert(t.root,30,x);
		}
		for(i=1;i<=n;i++)
		{
			ans=t.query(t.root,30,a[i]);
			t.Delete(t.root,30,ans);
			printf("%d%c",ans^a[i]," \n"[i==n]);
		}
	}
	return 0;
}