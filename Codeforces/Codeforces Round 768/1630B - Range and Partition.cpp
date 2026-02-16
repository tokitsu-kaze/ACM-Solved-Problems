#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int cnt[MAX],a[MAX];
int main()
{
	int T,n,k,i,l,r,now,tar,x,y,mn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		tar=(n+k+1)/2;
		now=0;
		x=y=-1;
		mn=INF;
		for(l=r=1;l<=n;l++)
		{
			while(r<=n && now<tar) now+=cnt[r++];
			if(r-l<mn && now>=tar)
			{
				mn=r-l;
				x=l;
				y=r-1;
			}
			now-=cnt[l];
		}
		printf("%d %d\n",x,y);
		now=0;
		l=1;
		for(i=1;i<=n && k>1;i++)
		{
			if(x<=a[i] && a[i]<=y) now++;
			else now--;
			if(now>0)
			{
				printf("%d %d\n",l,i);
				l=i+1;
				k--;
				now=0;
			}
		}
		printf("%d %d\n",l,n);
	}
	return 0;
}
/*
k 段每段要多 1，所以总共要多 k。
计算一下目标个数，双指针扫一下最小 y-x。
这样一定会有解，因为每次移动 now 的变化量都是 +1 -1，
所以构造方案就直接满足条件的那一刻截断区间即可。
*/
