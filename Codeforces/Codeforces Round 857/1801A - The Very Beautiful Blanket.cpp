#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,m,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",n*m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				printf("%d%c",(i*(1<<10))^j," \n"[j==m]);
			}
		}
	}
	return 0;
}

