#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
char ans[MAX];
int main()
{
	int T,n,q,i,nowq;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		nowq=0;
		for(i=n;i;i--)
		{
			if(a[i]>nowq)
			{
				if(nowq<q)
				{
					nowq++;
					ans[i]='1';
				}
				else ans[i]='0';
			}
			else ans[i]='1';
		}
		ans[n+1]='\0';
		puts(ans+1);
	}
	return 0;
}
/*
何意味，这是题啊？
ai<=q的先全部参加。
剩余的，随便参加q场。
发现看错题了(划掉)
---
显然ai<=q的全参加不劣，
然后看后缀是否有ai=当前q，
如果有，当前就不参加，
因为参加了不一定优，但不参加一定不劣。
假了，如果最后一个是q，那他就动不了了。
---
反正最后尽可能用完是最优的。
考虑时光倒流，q从0开始往回加。 
*/
