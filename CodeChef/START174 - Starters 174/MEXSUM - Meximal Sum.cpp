#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Range_Mex
{
	int root[MAX],ls[MAX<<5],rs[MAX<<5],mn[MAX<<5];
	int tot,qpos,qv,mxans;
	int copy_node(int x)
	{
		++tot;
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		mn[tot]=mn[x];
		return tot;
	}
	void update(int l,int r,int &id,int pre)
	{
		if(!id) id=copy_node(pre);
		if(l==r)
		{
			mn[id]=qv;
			return;
		}
		int mid=(l+r)>>1;
		if(qpos<=mid) update(l,mid,ls[id]=0,ls[pre]);
		else update(mid+1,r,rs[id]=0,rs[pre]);
		mn[id]=min(mn[ls[id]],mn[rs[id]]);
	}
	int ask(int l,int r,int id,int pos)
	{
		if(l==r) return l;
		int mid=(l+r)>>1;
		if(mn[ls[id]]<pos) return ask(l,mid,ls[id],pos);
		else return ask(mid+1,r,rs[id],pos);
	}
	void work(int n,int *a)
	{
		int i;
		root[0]=0;
		ls[0]=rs[0]=mn[0]=tot=0;
		mxans=n;
		for(i=1;i<=n;i++)
		{
			if(a[i]>mxans)
			{
				root[i]=root[i-1];
				continue;
			}
			qpos=a[i];
			qv=i;
			update(0,mxans,root[i]=0,root[i-1]);
		}
	}
	int ask_mex(int l,int r){return ask(0,mxans,root[r],l);}
}rm;
/*
rm.work(n,a); a[1..n]
rm.ask_mex(l,r);
*/
int a[MAX],premex[MAX],sufmex[MAX];
ll sum[MAX];
int main()
{
	int T,n,i,j,now,ok;
	ll mn,mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		rm.work(n,a);
		set<int> s;
		now=0;
		for(i=1;i<=n;i++)
		{
			s.insert(a[i]);
			while(s.count(now)) now++;
			premex[i]=now;
		}
		s.clear();
		now=0;
		for(i=n;i;i--)
		{
			s.insert(a[i]);
			while(s.count(now)) now++;
			sufmex[i]=now;
		}
		mn=LLINF;
		mx=-LLINF;
		ok=0;
		for(i=1,j=1;i<=n;i++)
		{
			if(j<=i) j=i+1;
			while(j+1<n && rm.ask_mex(i+1,j)<premex[i]) j++;
			if(j<n && rm.ask_mex(i+1,j)==premex[i] && sufmex[j+1]==premex[i])
			{
				mx=max(mx,sum[i]-(sum[j]-sum[i])+(sum[n]-sum[j]));
				ok=1;
			}
		}
		for(i=1,j=1;i<=n;i++)
		{
			if(j<=i) j=i+1;
			while(j+1<n && rm.ask_mex(i+1,j+1)<=premex[i] && sufmex[j+2]>=premex[i]) j++;
			if(j<n && rm.ask_mex(i+1,j)==premex[i] && sufmex[j+1]==premex[i])
			{
				mn=min(mn,sum[i]-(sum[j]-sum[i])+(sum[n]-sum[j]));
				ok=1;
			}
		}
		if(ok==0) puts("-1 -1");
		else printf("%lld %lld\n",mn,mx);
	}
	return 0;
}
