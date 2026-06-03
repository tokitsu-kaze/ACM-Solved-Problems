#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
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
int a[MAX];
vector<int> pos[MAX];
int main()
{
	int n,i,ok,pre;
	scanf("%d",&n);
	for(i=0;i<=n+1;i++) pos[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]--;
		pos[a[i]].push_back(i);
	}
	rm.work(n,a);
	for(i=0;i<=n+1;i++)
	{
		pre=0;
		ok=1;
		for(auto &it:pos[i])
		{
			if(pre+1<=it-1)
			{
				if(rm.ask_mex(pre+1,it-1)==i)
				{
					ok=0;
					break;
				}
			}
			pre=it;
		}
		if(pre+1<=n && rm.ask_mex(pre+1,n)==i) ok=0;
		if(ok)
		{
			printf("%d\n",i+1);
			break;
		}
	}
	return 0;
}
/*
枚举答案x，判断是否有区间mex为x。
区间mex为x，区间一定不包含x，所以将区间按x分段。
x会将区间分为k+1段，如果有一段mex=x，就不行。
总段数是O(n)级别。
问题转化成区间查询mex：P4137 Rmq Problem / mex
*/
