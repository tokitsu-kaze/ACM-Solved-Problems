#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=998244353;
const int MAX=1.5e4+10;
const int N=9e5+1;
int a[MAX],b[MAX],c[MAX];
int main()
{
	int n,f,i;
	scanf("%d%d",&n,&f);
/*	n=1.5e4;
	for(i=1;i<=n;i++)
	{
		a[i]=rand()%60+1;
		b[i]=rand()%60+1;
		c[i]=rand()%60+1;
	}*/
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	for(i=1;i<=n;i++) scanf("%d",&c[i]);
	bitset<N> dp,tmp;
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		tmp=dp;
		dp<<=a[i];
		dp|=(tmp<<b[i]);
		dp|=(tmp<<c[i]);
		printf("%d\n",dp.count());
	}
	return 0;
}

