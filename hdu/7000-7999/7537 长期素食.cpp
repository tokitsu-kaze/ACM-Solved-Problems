#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct LiChao_Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	static const int MIN_TAG=0;
	static const int MAX_TAG=1;
	int TAG;
	struct line{type k,b;int id;}sg[3][MAX<<2];
	struct seg{type k,b;int id,l,r;}tmpqv[4][33];
	int qvtot[4];
	bool ext[3][MAX<<2];
	int ql,qr,n,p;
	type cal(const line &l,const int &x){return l.k*x+l.b;}
	int sgn(const type &x){return x==0?0:(x>0?1:-1);}
	int cmp_min(const type &x,const type &y){return sgn(y-x);}
	int cmp_max(const type &x,const type &y){return sgn(x-y);}
	int cmp(const type &x,const type &y){return TAG==MIN_TAG?cmp_min(x,y):cmp_max(x,y);}
	void build(int l,int r,int id)
	{
		for(int i=0;i<3;i++)
		{
			ext[i][id]=0;
			sg[i][id]={0,0,0};
		}
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void pushdown(int l,int r,int id,line qv)
	{
		int cl,cr,mid;
		if(!ext[p][id])
		{
			ext[p][id]=1;
			sg[p][id]=qv;
			return;
		}
		mid=(l+r)>>1;
		if(cmp(cal(qv,mid),cal(sg[p][id],mid))==1) swap(qv,sg[p][id]);
		cl=cmp(cal(qv,l),cal(sg[p][id],l));
		cr=cmp(cal(qv,r),cal(sg[p][id],r));
		if(cl>=0&&cr>=0)
		{
			tmpqv[p+1][qvtot[p+1]++]={sg[p][id].k,sg[p][id].b,sg[p][id].id,l,r};
			sg[p][id]=qv;
			return;
		}
		if(cl==1)
		{
			tmpqv[p+1][qvtot[p+1]++]={qv.k,qv.b,qv.id,mid+1,r};
			pushdown(l,mid,ls,qv);
		}
		else if(cr==1)
		{
			tmpqv[p+1][qvtot[p+1]++]={qv.k,qv.b,qv.id,l,mid};
			pushdown(mid+1,r,rs,qv);
		}
		else tmpqv[p+1][qvtot[p+1]++]={qv.k,qv.b,qv.id,l,r};
	}
	void update(int l,int r,int id,line qv)
	{
		if(l>=ql&&r<=qr)
		{
			pushdown(l,r,id,qv);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls,qv);
		if(qr>mid) update(mid+1,r,rs,qv);
	}
	int ban;
	void query(int l,int r,int id,vector<pair<ll,int>> &res)
	{
		for(int i=0;i<3;i++)
		{
			if(sg[i][id].id==ban) continue;
			pair<ll,int> tmp={cal(sg[i][id],max(l,ql)),sg[i][id].id};
			for(auto &it:res)
			{
				if(it<tmp) swap(it,tmp);
			}
		}
		if(l==r) return;
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls,res);
		if(qr>mid) query(mid+1,r,rs,res);
	}
	void build(int _n,int _TAG){n=_n;TAG=_TAG;build(1,n,1);}
	void upd(int l,int r,type k,type b,int id)
	{
		int i,j;
		qvtot[0]=0;
		tmpqv[0][qvtot[0]++]={k,b,id,l,r};
		for(p=0;p<3;p++)
		{
			qvtot[p+1]=0;
			for(i=0;i<qvtot[p];i++)
			{
				ql=tmpqv[p][i].l;
				qr=tmpqv[p][i].r;
				line qv={tmpqv[p][i].k,tmpqv[p][i].b,tmpqv[p][i].id};
				update(1,n,1,qv);
			}
		}
	}
	void ask(int x,int _ban,vector<pair<ll,int>> &now)
	{
		ql=x;
		qr=x;
		ban=_ban;
		query(1,n,1,now);
	}
	#undef type
	#undef MIN_TAG
	#undef MAX_TAG
	#undef ls
	#undef rs
}tr;
/*
upd:O(log^2), ask:O(log)

tr.build(n,LiChao_Segment_Tree::MIN_TAG);
tr.build(n,LiChao_Segment_Tree::MAX_TAG);
tr.upd(l,r,k,b);
tr.ask(l,r);
*/
ll dp[2][3];
int pre[2][3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n,k,i,j,l,f,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		tr.build(k,LiChao_Segment_Tree::MAX_TAG);
		for(i=1;i<=n;i++)
		{
			cin>>a>>b;
			tr.upd(1,k,b,a,i);
		}
		memset(dp,0,sizeof dp);
		memset(pre,0,sizeof pre);
		vector<pair<ll,int>> res(9),now(3);
		f=0;
		for(i=1;i<=k;i++)
		{
			f^=1;
			l=0;
			for(j=0;j<3;j++)
			{
				now[0]=now[1]=now[2]={0,0};
				tr.ask(i,pre[!f][j],now);
				res[l++]={dp[!f][j]+now[0].first,now[0].second};
				res[l++]={dp[!f][j]+now[1].first,now[1].second};
				res[l++]={dp[!f][j]+now[2].first,now[2].second};
			}
			sort(res.begin(),res.end());
			reverse(res.begin(),res.end());
			dp[f][0]=res[0].first;
			pre[f][0]=res[0].second;
			j=1;
			for(auto &it:res)
			{
				if(it.second==pre[f][j-1]) continue;
				dp[f][j]=it.first;
				pre[f][j]=it.second;
				j++;
				if(j==3) break;
			}
		}
		cout<<max({dp[f][0],dp[f][1],dp[f][2]})<<"\n";
	}
	return 0;
}

