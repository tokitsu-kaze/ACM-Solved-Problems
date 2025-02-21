#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct persistable_tree
{
	int mn[40*MAX],rt[40*MAX],c[40*MAX][2];
	int tot;
	void modify(int pos,int k,int tl,int tr,int pre,int &p)
	{
		p=++tot;
		if (tl==tr)
		{
			mn[p]=k;
			return;
		}
		c[p][0]=c[pre][0];
		c[p][1]=c[pre][1];
		int mid=(tl+tr)>>1;
		if(mid>=pos) modify(pos,k,tl,mid,c[pre][0],c[p][0]);
		else modify(pos,k,mid+1,tr,c[pre][1],c[p][1]);
		mn[p]=min(mn[c[p][0]],mn[c[p][1]]);
	}
	int query(int k,int tl,int tr,int p)
	{
		if(tl==tr) return tl;
		int mid=(tl+tr)>>1;
		if(mn[c[p][0]]<k) return query(k,tl,mid,c[p][0]);
		else return query(k,mid+1,tr,c[p][1]);
	}
}tr;
int n;
int ask_mex(int l,int r)
{
	return tr.query(l,0,n,tr.rt[r]);
}
int a[MAX],premex[MAX],sufmex[MAX];
ll sum[MAX];
int main()
{
	int T,i,j,now,ok;
	ll mn,mx;
	scanf("%d",&T);
	while(T--)
	{
		tr.tot=0;
		scanf("%d",&n);
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
			tr.modify(a[i],i,0,n,tr.rt[i-1],tr.rt[i]);
		}
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
			while(j+1<n && ask_mex(i+1,j)<premex[i]) j++;
			if(j<n && ask_mex(i+1,j)==premex[i] && sufmex[j+1]==premex[i])
			{
				mx=max(mx,sum[i]-(sum[j]-sum[i])+(sum[n]-sum[j]));
				ok=1;
			}
		}
		for(i=1,j=1;i<=n;i++)
		{
			if(j<=i) j=i+1;
			while(j+1<n && ask_mex(i+1,j+1)<=premex[i] && sufmex[j+2]>=premex[i]) j++;
			if(j<n && ask_mex(i+1,j)==premex[i] && sufmex[j+1]==premex[i])
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
