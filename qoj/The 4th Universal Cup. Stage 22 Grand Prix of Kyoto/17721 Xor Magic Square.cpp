#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2000+10;
int mp[MAX][MAX];
int main()
{
	int n,i,j,pre,nex;
	scanf("%d",&n);
	if(n%2==0)
	{
		printf("%d\n",n*n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%d%c",1," \n"[j==n]);
			}
		}
		return 0;
	}
	if(n==1 || n==3) return 0*puts("-1");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) mp[i][j]=1;
	}
	for(i=1;i<=n;i++)
	{
		pre=i-1;
		if(pre==0) pre=n;
		nex=i+1;
		if(nex==n+1) nex=1;
		mp[i][pre]=3;
		mp[i][nex]=2;
	}
	swap(mp[2][3],mp[2][2]);
	swap(mp[1][2],mp[1][3]);
	swap(mp[n-1][n-2],mp[n-1][n-1]);
	swap(mp[n][n-1],mp[n][n-2]);
	printf("%d\n",n*n+3*n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d%c",mp[i][j]," \n"[j==n]);
		}
	}
	return 0;
}
/*
n 为偶数显然全填 1。
n 为奇数，每一行有一个 2 和一个 3，对角线微调一下。
*/
