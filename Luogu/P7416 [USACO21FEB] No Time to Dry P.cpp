#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct ST_table
{
	#define type int
	static const int N=MAX;
	static const int LOG=21;
	type v[N];
	int lg[N],bin[LOG],pmx[LOG][N],pmn[LOG][N];
	int pmin(const int &a,const int &b){return v[a]<v[b]?a:b;}
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			pmn[0][i]=i;
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				pmn[j][i]=pmin(pmn[j-1][i],pmn[j-1][i+bin[j-1]]);
			}
		}
	}
	int ask_pmin(int l,int r)
	{
		int t=lg[r-l+1];
		return pmin(pmn[t][l],pmn[t][r-bin[t]+1]);
	}
	type ask_min(int l,int r){return v[ask_pmin(l,r)];}
	#undef type
}st;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX][2];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			bit[i][0]=bit[i][1]=0;
		}
	}
	int lowbit(int x){return x&(-x);}
	void _insert(int x,type v)
	{
		for(int i=x;i<=n;i+=lowbit(i))
		{
			bit[i][0]+=v;
			bit[i][1]+=v*(x-1);
		}
	}
	type get(int x)
	{
		type res=0;
		for(int i=x;i;i-=lowbit(i))
		{
			res+=x*bit[i][0]-bit[i][1];
		}
		return res;
	}
	void upd(int l,int r,type v)
	{
		_insert(l,v);
		_insert(r+1,-v);
	}
	type ask(int l,int r)
	{
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr;
struct Q{int l,id;};
vector<Q> qst[MAX];
int a[MAX],ans[MAX],lst[MAX],pre[MAX];
int main()
{
	int n,q,i,l,r;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		lst[i]=0;
		qst[i].clear();
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pre[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		qst[r].push_back({l,i});
	}
	st.work(n,a);
	tr.init(n);
	for(i=1;i<=n;i++)
	{
		if(!pre[i]) tr.upd(1,i,1);
		else
		{
			if(st.ask_min(pre[i],i)>=a[i]) tr.upd(pre[i]+1,i,1);
			else tr.upd(1,i,1);
		}
		for(auto &qs:qst[i]) ans[qs.id]=tr.ask(qs.l,qs.l);
	}
	for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
/*
考虑维护每个位置为左端点的答案。
当 min{a[pre[i] ~ i]} >= ai，i 对 1~pre[i] 没有贡献；
否则 i 对 1~i 都有贡献。
*/
