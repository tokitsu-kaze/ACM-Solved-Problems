#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sqr(x) ((x)*(x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;
typedef vector<VPII> VVPII;
/************* define end  *************/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/********* gp_hash_table end  **********/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type v;
		void init(){v=INF;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=min(x.v,y.v);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
		if(l==r)
		{
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			t[id].v=min(t[id].v,qv);
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls);
		if(ql>mid) return query(mid+1,r,rs);
		return merge_node(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
		null_node.init();
	}
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return null_node.v;
		ql=l;
		qr=r;
		return query(1,n,1).v;
	}
	#undef type
	#undef ls
	#undef rs
}tr[12];
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
int a[MAX],b[MAX],dp[MAX][12];
class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n,m,i,j,k,l,r,nowand;
        n=sz(nums);
        m=sz(andValues);
        for(i=0;i<sz(nums);i++) a[i+1]=nums[i];
        for(i=0;i<sz(andValues);i++) b[i+1]=andValues[i];
        int lst[33];
        mem(lst,-1);
        for(k=0;k<=m;k++) tr[k].build(n);
        nowand=(1<<30)-1;
        for(i=1;i<=n;i++)
        {
        	nowand&=a[i];
        	mem(dp[i],0x3f);
       // 	printf("%d\n",i);
        	for(j=0;j<30;j++)
        	{
        		if((a[i]>>j)&1)
        		{
        			if(lst[j]==-1) lst[j]=i;
				}
        		else lst[j]=-1;
     //   		printf("%d %d\n",j,lst[j]);
			}
			if(nowand==b[1]) dp[i][1]=min(dp[i][1],a[i]);
			tr[1].upd(i,i,dp[i][1]);
			for(k=2;k<=m;k++)
			{
				l=1;
				r=i-1;
				for(j=0;j<30;j++)
				{
					if((b[k]>>j)&1)
					{
						if(lst[j]==-1)
						{
							l=-1;
							break;
						}
						l=max(lst[j]-1,l);
					}
					else
					{
						if(lst[j]==1)
						{
							l=-1;
							break;
						}
						if(lst[j]!=-1) r=min(lst[j]-2,r);
					}
				}
				if(l==-1) continue;
				if(l>r) continue;
	//			printf("%d %d %d %d\n",i,k,l,r);
				dp[i][k]=min(dp[i][k],tr[k-1].ask(l,r)+a[i]);
				tr[k].upd(i,i,dp[i][k]);
			}
		}
		if(dp[n][m]==INF) return -1;
		return dp[n][m];
    }
};
/*
[4,8,2,9]
[0,0]
[1,1,2,2,2,2,1,2,1,1]
[1,1,2,1,1]
*/
