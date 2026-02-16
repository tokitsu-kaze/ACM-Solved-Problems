#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
const int mod=998244353;
ll pw[MAX][MAX],tmp[MAX][MAX],ans[MAX];
int main()
{
	int n,m,i,j,x;
	scanf("%d%d",&n,&m);
	pw[0][0]=1;
	for(i=1;i<=m;i++)
	{
		pw[i][0]=1;
		for(j=1;j<=n;j++) pw[i][j]=pw[i][j-1]*i%mod;
	}
	memset(tmp,0,sizeof tmp);
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			tmp[i][j]=(tmp[i-1][j]*m+pw[m-j][i-2])%mod;
		}
	}
	ans[0]=0;
	for(i=1;i<=n;i++)
	{
		for(x=1;x<=m;x++)
		{
			ans[i]=(ans[i]+ans[i-1]+pw[m][i-1]-tmp[i][x])%mod;
			if(ans[i]<0) ans[i]+=mod;
		}
	}
	printf("%lld\n",ans[n]);
	return 0;
}
/*
先考虑如何计算 f(A)，再考虑添加一个数后对答案的贡献。
发现添加的数和前一个它中间都比他大是没有贡献的，比如
1 2 4 3 2 中的 2。
考虑将总的减去没有贡献的。
位置i插入x的贡献，总的：m^(i-1)
减掉：枚举last=k，中间小的不能选 (m-x)^(i-k-1) * 前面任选 m^(k-1)
由于枚举的是last，所以不会算重。
减掉的玩意可以做前缀和求。最后把所有贡献累加就做完了。
*/
