#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX],tmp[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		tmp[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=a[i];
			tmp[i]+=tmp[i-1];
			bit[i]=tmp[i]-tmp[i-lowbit(i)];
		}
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	void upd(int x,type v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr;
struct node{int x,y,z,v,ans;}a[MAX],res[MAX],tmp[MAX];
int tot,tmp_tot;
void cdq(int l,int r)
{
	if(l==r) return;
	int mid,i,j,k;
	mid=(l+r)>>1;
	cdq(l,mid);
	cdq(mid+1,r);
	i=l;
	j=mid+1;
	tmp_tot=0;
	while(i<=mid&&j<=r)
	{
		if(res[i].y<=res[j].y)
		{
			tr.upd(res[i].z,res[i].v);
			tmp[++tmp_tot]=res[i++];
		}
		else
		{
			res[j].ans+=tr.ask(1,res[j].z);
			tmp[++tmp_tot]=res[j++];
		}
	}
	while(j<=r)
	{
		res[j].ans+=tr.ask(1,res[j].z);
		tmp[++tmp_tot]=res[j++];
	}
	for(k=l;k<i;k++) tr.upd(res[k].z,-res[k].v);
	while(i<=mid) tmp[++tmp_tot]=res[i++];
	for(i=1;i<=tmp_tot;i++) res[l+i-1]=tmp[i];
}
int ans[MAX];
int main()
{
	int n,k,i,x,y,z;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[i]={x,y,z,1,0};
	}
	sort(a+1,a+1+n,[](node a,node b){
		if(a.x==b.x)
		{
			if(a.y==b.y) return a.z<b.z;
			return a.y<b.y;
		}
		return a.x<b.x;
	});
	tot=0;
	for(i=1;i<=n;i++)
	{
		if(tot && (res[tot].x==a[i].x&&
				   res[tot].y==a[i].y&&
				   res[tot].z==a[i].z)) res[tot].v++;
		else res[++tot]=a[i];
	}
	tr.init(k);
	cdq(1,tot);
	for(i=0;i<=n;i++) ans[i]=0;
	for(i=1;i<=tot;i++) ans[res[i].ans+res[i].v-1]+=res[i].v;
	for(i=0;i<n;i++) printf("%d\n",ans[i]);
	return 0;
}
