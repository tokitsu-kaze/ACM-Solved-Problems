#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
struct ODT
{
	#define type int
	#define init_val 0
	struct ODT_node
	{
		int l,r;
		mutable type v;
		inline bool operator<(const ODT_node &o)const {return l<o.l;}
	};
	set<ODT_node> odt;
	typedef set<ODT_node>::iterator odt_iter;
	void init()
	{
		odt.clear();
		odt.insert({-1,-1,-1});
	}
	void insert(int l,int r)
	{
		odt.insert({l,r,1});
	}
	odt_iter find(int x){return --odt.upper_bound({x,0,init_val});}
	void erase(int x)
	{
		odt_iter it=find(x);
		assert(x>=it->l);
		int l1=it->l;
		int r1=it->r;
		if(x>it->r)
		{
			odt_iter it2=odt.upper_bound({x,0,init_val});
			int l2=it2->l;
			int r2=it2->r;
			odt.erase(it2);
			if(l2+1<=r2) odt.insert({l2+1,r2,1});
			if(x==r1+1)
			{
				odt.erase(it);
				odt.insert({l1,l2-1,1});
			}
			else odt.insert({x,l2-1,1});
		}
		else
		{
			odt.erase(it);
			if(l1<=x-1) odt.insert({l1,x-1,1});
			if(x+1<=r1) odt.insert({x+1,r1,1});
		}
	}
	void insert(int x)
	{
		odt_iter it=find(x);
		assert(x>=it->l);
		int l1=it->l;
		int r1=it->r;
		if(x>it->r)
		{
			odt_iter it2=odt.upper_bound({x,0,init_val});
			int l2,r2;
			l2=r2=-1;
			if(it2!=odt.end())
			{
				l2=it2->l;
				r2=it2->r;
			}
			if(r1+1==x && x+1==l2)
			{
				odt.erase(it);
				odt.erase(it2);
				odt.insert({l1,r2,1});
				return;
			}
			if(r1+1==x)
			{
				odt.erase(it);
				odt.insert({l1,x,1});
				return;
			}
			if(x+1==l2)
			{
				odt.erase(it2);
				odt.insert({x,r2,1});
				return;
			}
			odt.insert({x,x,1});
		}
		else
		{
			odt.erase(it);
			if(l1<=x-1) odt.insert({l1,x-1,1});
			insert(r1+1);
		}
	}
	type getmax()
	{
		return (*odt.rbegin()).r;
	}
	#undef init_val
	#undef type
}odt;
const int limt=4e5+1;
int a[MAX],cnt[MAX];
int main()
{
	int n,q,i,l,r,x,y;
	scanf("%d%d",&n,&q);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	cnt[0]=0;
	odt.init();
	for(i=1;i<=limt;i++)
	{
		cnt[i+1]+=cnt[i]/2;
		cnt[i]%=2;
		if(cnt[i]==1 && cnt[i-1]==0) l=i;
		else if(cnt[i]==0 && cnt[i-1]==1)
		{
			r=i-1;
			odt.insert(l,r);
		}
	}
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(a[x]==y)
		{
			printf("%d\n",odt.getmax());
			continue;
		}
		odt.erase(a[x]);
		odt.insert(y);
		a[x]=y;
		printf("%d\n",odt.getmax());
/*		puts("*****");
		for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		for(auto &it:odt.odt) cout<<it.l<<" "<<it.r<<endl;
		puts("*****");*/
	}
	return 0;
}
