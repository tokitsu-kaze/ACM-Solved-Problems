////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-18 17:28:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5091
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:5932KB
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
const int MAX=4e4+10;
const ll mod=1e9+7;
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qv;
	int v[MAX<<2],tag[MAX<<2];
	void pushup(int id)
	{
		v[id]=max(v[ls],v[rs]);
	}
	void pushdown(int id)
	{
		if(!tag[id]) return;
		v[ls]+=tag[id];
		v[rs]+=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			tag[id]+=qv;
			v[id]+=qv;
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	void build(int _n){n=_n;mem(v,0);mem(tag,0);}
	
}tr;
int x[MAX],y[MAX];
vector<int> rx[MAX];
int main()
{
	int n,i,xx,yy,l,r,ans;
	while(~scanf("%d",&n)&&n>=0)
	{
		scanf("%d%d",&xx,&yy);
		xx++;
		yy++;
		for(i=1;i<=40001;i++) rx[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			x[i]+=20001;
			y[i]+=20001;
			assert(x[i]>=1&&y[i]>=1);
			assert(x[i]<=40001&&y[i]<=40001);
			rx[x[i]].pb(y[i]);
		}
		tr.build(40001);
		l=r=1;
		ans=0;
		while(r<=xx)
		{
			for(auto it:rx[r])//3 2 3-5
			{
				tr.qv=1;
				tr.ql=it;
				tr.qr=min(40001,it+yy-1);
				tr.update(1,40001,1);
			}
			r++;
		}
		ans=max(ans,tr.v[1]);
		for(;r<=40001;l++,r++)
		{
			for(auto it:rx[r])
			{
				tr.qv=1;
				tr.ql=it;
				tr.qr=min(40001,it+yy-1);
				tr.update(1,40001,1);
			}
			for(auto it:rx[l])
			{
				tr.qv=-1;
				tr.ql=it;
				tr.qr=min(40001,it+yy-1);
				tr.update(1,40001,1);
			}
			ans=max(ans,tr.v[1]);
		}
		printf("%d\n",ans);
	}
	return 0;
} 