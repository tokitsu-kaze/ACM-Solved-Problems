#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int main()
{
	int n,q,i,j,x,cnt[105],mn,ans;
	scanf("%d%d",&n,&q);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=q;i++)
	{
		scanf("%d",&x);
		if(x>=1)
		{
			ans=x;
			cnt[x]++;
		}
		else
		{
			mn=INF;
			for(j=1;j<=n;j++)
			{
				if(cnt[j]<mn)
				{
					mn=cnt[j];
					ans=j;
				}
			}
			cnt[ans]++;
		}
		printf("%d%c",ans," \n"[i==q]);
	}
	return 0;
}
