////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-12-18 21:13:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5919
////Problem Title: 
////Run result: Accept
////Run time:2059MS
////Run memory:86476KB
//////////////////System Comment End//////////////////
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
const int MAX=2e5+10;
const ll mod=1e9+7;
struct president_tree
{
	int root[MAX],ls[40*MAX],rs[40*MAX],sum[40*MAX],tot;
	void init()
	{
		mem(root,0);
		tot=1;
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
	int kth(int l,int r,int id,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		if(sum[ls[id]]>=k) return kth(l,mid,ls[id],k);
		else return kth(mid+1,r,rs[id],k-sum[ls[id]]);
	}
}pt;
int last[MAX],a[MAX];
int main()
{
	int t,cas=1,i,n,m,l,r,res,x,y;
	scanf("%d",&t);
	while(t--)
	{
		pt.init();
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			last[a[i]]=-1;
		}
		for(i=n;i>=1;i--)
		{
			if(last[a[i]]==-1) pt.Insert(1,n,pt.root[i],pt.root[i+1],i,1);
			else
			{
				int temp;
				pt.Insert(1,n,temp,pt.root[i+1],last[a[i]],-1);
				pt.Insert(1,n,pt.root[i],temp,i,1);
			}
			last[a[i]]=i;
		}
		vector<int>ans;
		res=0;
		while(m--)
		{
			scanf("%d%d",&x,&y);
			l=min((x+res)%n+1,(y+res)%n+1);
			r=max((x+res)%n+1,(y+res)%n+1);
			res=pt.kth(1,n,pt.root[l],(pt.kindcnt(1,n,pt.root[l],l,r)+1)/2);
			ans.pb(res);
		}
		printf("Case #%d:",cas++);
		for(i=0;i<sz(ans);i++) printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}