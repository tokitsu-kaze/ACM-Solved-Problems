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
const int MAX=1e5+10;
const ll mod=1e9+7;
struct president_tree
{
	int root[MAX],ls[40*MAX],rs[40*MAX],sum[40*MAX],tot;
	void init()
	{
		mem(root,0);
		tot=1;
		ls[0]=rs[0]=sum[0]=0;
	}
	int newnode(int x)
	{
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		sum[tot]=sum[x];
		return tot++;
	}
	void Insert(int l,int r,int &id,int pre,int pos,int v)
	{
		id=newnode(pre);
		sum[id]+=v;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(pos<=mid) Insert(l,mid,ls[id],ls[pre],pos,v);
		else Insert(mid+1,r,rs[id],rs[pre],pos,v);
	}
	int kindcnt(int l,int r,int id,int x,int y)  
	{
		if(x<=l&&r<=y) return sum[id];  
		int mid=(l+r)>>1;
		int res=0;
		if(x<=mid) res+=kindcnt(l,mid,ls[id],x,y);  
		if(y>=mid+1) res+=kindcnt(mid+1,r,rs[id],x,y);
		return res;
	}
	int kthsmall(int l,int r,int id,int pre,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		int temp=sum[ls[id]]-sum[ls[pre]];
		if(temp>=k) return kthsmall(l,mid,ls[id],ls[pre],k);
		else return kthsmall(mid+1,r,rs[id],rs[pre],k-temp);
	}
	int kthbig(int l,int r,int id,int pre,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		int temp=sum[rs[id]]-sum[rs[pre]];
		if(temp>=k) return kthbig(mid+1,r,rs[id],rs[pre],k);
		else return kthbig(l,mid,ls[id],ls[pre],k-temp);
	}
}pt;
int last[MAX],a[MAX];
int main()
{
	int n,i,k,l;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		pt.init();
		mem(last,-1);
		for(i=n;i>=1;i--)
		{
			int temp;
			if(last[a[i]]==-1) pt.Insert(1,n+1,pt.root[i],pt.root[i+1],i,1);
			else
			{
				pt.Insert(1,n+1,temp,pt.root[i+1],last[a[i]],-1);
				pt.Insert(1,n+1,pt.root[i],temp,i,1);
			}
			last[a[i]]=i;
		}
		for(k=1;k<=n;k++)
		{
			l=1;
			int ans=0;
			while(l<=n)
			{
				l=pt.kthsmall(1,n+1,pt.root[l],pt.root[n+1],k+1);
				ans++;
			}
			if(k==1) printf("%d",ans);
			else printf(" %d",ans);
		}
		puts("");
	}
	return 0;
}