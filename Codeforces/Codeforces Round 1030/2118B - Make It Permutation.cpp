#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int mp[5050][5050];
void gao(int x,int l,int r)
{
	reverse(mp[x]+l,mp[x]+r+1);
	printf("%d %d %d\n",x,l,r);
}
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				mp[i][j]=j;
			}
		}
		printf("%d\n",2*n-1);
		gao(1,1,n);
		for(i=1;i<=n-1;i++)
		{
			gao(i+1,1,n-i);
			gao(i+1,n-i+1,n);
		}
/*		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) printf("%d%c",mp[i][j]," \n"[j==n]);
		}*/
	}
	return 0;
}
/*
7 6 5 4 3 2 1
6 5 4 3 2 1 7
5 4 3 2 1 7 6
4 3 2 1 7 6 5
3 2 1 7 6 5 4
2 1 7 6 5 4 3
1 7 6 5 4 3 2
*/

