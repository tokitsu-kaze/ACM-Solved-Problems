#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct RMQ
{
	#define type int
	type v[MAX];
	int lg[MAX],bin[22];
	type mx[MAX][22];
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			mx[i][0]=v[i];
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				mx[i][j]=max(mx[i][j-1],mx[i+bin[j-1]][j-1]);
			}
		}
	}
	type ask_max(int l,int r)
	{
		int t=lg[r-l+1];
		return max(mx[l][t],mx[r-bin[t]+1][t]);
	}
	#undef type
}rmq;
int a[MAX],val[MAX],to[MAX];
int main()
{
	int t,n,q,l,r,i,pos;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		map<int,int> lst;
		for(i=1;i<=n;i++)
		{
			to[i]=0;
			if(lst.count(a[i]))
			{
				if(lst[a[i]]==i-1) val[i]=val[lst[a[i]]];
				else val[i]=i-1;
			}
			else val[i]=i-1;
			if(!to[val[i]]) to[val[i]]=i;
			lst[a[i]]=i;
		}
		rmq.work(n,val);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&l,&r);
			pos=rmq.ask_max(l,r);
			if(pos<l) puts("-1 -1");
			else printf("%d %d\n",pos,to[pos]);
		}
	}
	return 0;
}
