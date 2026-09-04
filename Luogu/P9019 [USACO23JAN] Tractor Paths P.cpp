#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
char s[MAX];
int l[MAX],r[MAX],pre[MAX],nex[MAX],sum[MAX];
int gol[21][MAX],gor[21][MAX];
ll sl[21][MAX],sr[21][MAX];
int main()
{
	int n,q,i,j,cntl,cntr,ans1,a,b,x;
	ll ans2;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	cntl=cntr=0;
	for(i=1;i<=2*n;i++)
	{
		if(s[i]=='L')
		{
			cntl++;
			l[cntl]=i;
		}
		else
		{
			cntr++;
			r[cntr]=i;
		}
	}
	scanf("%s",s+1);
	sum[0]=0;
	for(i=1;i<=n;i++)
	{
		pre[i]=lower_bound(r+1,r+1+n,l[i])-r;
		nex[i]=upper_bound(l+1,l+1+n,r[i])-l-1;
		sum[i]=sum[i-1]+(s[i]-'0');
//		printf("%d %d %d\n",i,pre[i],nex[i]);
	}
	for(i=1;i<=n;i++)
	{
		gol[0][i]=pre[i];
		gor[0][i]=nex[i];
		sl[0][i]=sum[pre[i]-1];
		sr[0][i]=sum[nex[i]];
	}
	for(j=1;j<=20;j++)
	{
		for(i=1;i<=n;i++)
		{
			gol[j][i]=gol[j-1][gol[j-1][i]];
			gor[j][i]=gor[j-1][gor[j-1][i]];
			sl[j][i]=sl[j-1][i]+sl[j-1][gol[j-1][i]];
			sr[j][i]=sr[j-1][i]+sr[j-1][gor[j-1][i]];
		}
	}
	while(q--)
	{
		scanf("%d%d",&a,&b);
		x=a;
		ans1=1;
		for(j=20;~j;j--)
		{
			if(gor[j][x]<b)
			{
				ans1+=(1<<j);
				x=gor[j][x];
			}
		}
		ans2=(s[a]-'0')+(s[b]-'0');
		for(j=0;j<=20;j++)
		{
			if(((ans1-1)>>j)&1)
			{
				ans2+=sr[j][a];
				ans2-=sl[j][b];
				a=gor[j][a];
				b=gol[j][b];
			}
		}
		printf("%d %lld\n",ans1,ans2);
	}
	return 0;
}
/*
显然尽可能往右是最优的，第一问直接倍增。
第二问，考虑暴力做法枚举 i，check通过计算 dis(a,i)+dis(i,b)=ans1。
发现有些 (dis(a,i),dis(i,b)) 是相同的，考虑一起统计。
考虑枚举 dis(a,i)=k，dis(i,b)=ans1-k，
这样从a尽可能往右走，从b尽可能往左走，一定会有一个相交的区间。
而且会发现，不同的 k 求出来的区间都互不相交，所以每个区间单独统计答案。
求出区间后，就可以用前缀和 sum[r]-sum[l-1] 计算，但这样枚举 k 还是O(nq)的。
考虑把前缀和拆开计算，变为求sum{sum[r]}-sum{sum[l-1]}，然后可以倍增优化。
*/
