#include<bits/stdc++.h>
using namespace std;
const int MAX=5e4+10;
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
		if(l>r) return -1e9-1;
		int t=lg[r-l+1];
		return max(mx[l][t],mx[r-bin[t]+1][t]);
	}
	#undef type
}rmq;
int a[MAX],v[MAX];
int main()
{
	int n,q,i,x,y,px,py;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i],&v[i]);
	rmq.work(n,v);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if(x>y)
		{
			puts("false");
			continue;
		}
		px=upper_bound(a+1,a+1+n,x)-a-1;
		py=lower_bound(a+1,a+1+n,y)-a;
		if(a[px]==x&&a[py]==y)
		{
			if(v[px]<v[py])
			{
				puts("false");
				continue;
			}
		}
		if(a[px]==x)
		{
			if(rmq.ask_max(px+1,py-1)>=v[px])
			{
				puts("false");
				continue;
			}
		}
		if(a[py]==y)
		{
			if(rmq.ask_max(px+1,py-1)>=v[py])
			{
				puts("false");
				continue;
			}
		}
		if(a[px]==x&&a[py]==y&&y-x+1==py-px+1) puts("true");
		else puts("maybe");
	}
	return 0;
}
