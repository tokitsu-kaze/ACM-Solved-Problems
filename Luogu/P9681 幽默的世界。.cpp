#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct Fenwick_Tree
{
	#define type ll
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
struct node{int l,id;};
vector<node> qst[MAX];
ll a[MAX],bit[MAX],ans[MAX];
int main()
{
	int n,q,i,l,r,mid,pre;
	scanf("%d%d",&n,&q);
	bit[0]=0;
	for(i=1;i<=n;i++)
	{
		qst[i].clear();
		scanf("%lld",&a[i]);
		bit[i]=bit[i-1]+a[i];
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		qst[r].push_back({l,i});
	}
	tr.init(n);
	pre=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>0)
		{
			l=pre+1;
			r=i;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(bit[i]-bit[mid-1]>0) r=mid;
				else l=mid+1;
			}
			pre=i;
			tr.upd(l,i,1);
		}
		for(auto &it:qst[i])
		{
			ans[it.id]=tr.ask(it.l,i);
		}
	}
	for(i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}
