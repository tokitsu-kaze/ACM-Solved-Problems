#include<bits/stdc++.h>
using namespace std;
int cnt[1010];
int main()
{
	int n,m,i,x;
	scanf("%d%d",&n,&m);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	for(i=1;i<=n;i++)
	{
		while(cnt[i]>0)
		{
			m--;
			cnt[i]--;
			printf("%d%c",i," \n"[m==0]);
		}
	}
	return 0;
}
