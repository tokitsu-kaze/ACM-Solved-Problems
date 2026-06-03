#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
//x is a prime if prime[x]==x(x>=2)
const int V=1e6;
int p[V+5],tot,prime[V+5];
void init_prime()
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=V;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=V;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
struct node{int cnt,id;};
int a[MAX],vis[MAX],delta[V+5],now,val[MAX],cnt1;
char b[MAX];
vector<node> q[V+5];
vector<int> pos;
void del(int x)
{
	while(pos.size()>0)
	{
		if(pos.back()<x) break;
		now-=val[pos.back()];
		pos.pop_back();
	}
}
void work(int x,int sgn,int id)
{
	int t,cnt,mn;
	if(x==1)
	{
		cnt1++;
		return;
	}
	val[id]=cnt1+1;
	pos.push_back(id);
	cnt1=0;
	while(x>1)
	{
		t=prime[x];
		cnt=0;
		while(x%t==0)
		{
			x/=t;
			cnt++;
		}
		delta[t]+=sgn*cnt;
		if(sgn==1) q[t].push_back({cnt-delta[t],id});
		else
		{
			mn=1;
			while(!q[t].empty())
			{
				node tmp=q[t].back();
				if(tmp.cnt+delta[t]>=0)
				{
					mn=tmp.id+1;
					break;
				}
				q[t].pop_back();
			}
//			printf("%d %d %d\n",id,t,mn);
			del(mn);
		}
	}
}
int main()
{
	init_prime();
	int n,i;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		vis[i]=val[i]=0;
	}
	scanf("%s",b+1);
	for(i=1;i<=V;i++)
	{
		delta[i]=0;
		while(!q[i].empty()) q[i].pop_back();
	}
	now=cnt1=0;
	ans=0;
	pos.clear();
	for(i=1;i<=n;i++)
	{
		now++;
		if(b[i]=='*') work(a[i],1,i);
		else work(a[i],-1,i);
		ans+=now;
//		printf("%d %d\n",i,now);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
考虑每种质因数分开做。乘就是加，除就是减。
合法条件是，区间内所有质因数的前缀和>=0。
考虑扫 r，维护所有合法的 l。
对于一个质因数，发现某个不合法的位置往右肯定都不合法。
用优先队列+全局tag来维护前缀和；用双向链表来维护要删除的数。
复杂度 n log n * 质因子个数，感觉log较小应该能通过？

发现不需要优先队列维护，从右到左遇到第一个合法的退出即可。
因为每次把<0的都弹出去了，往左剩下的必定都合法，最小的一定是最近的。
另外，双向链表无法从一个被删除的数快速遍历到没有被删除的数，
得用并查集，合并有方向，要带log，复杂度还是 n log n * 质因子个数。

发现其实根本不用并查集，用栈即可。
*/
