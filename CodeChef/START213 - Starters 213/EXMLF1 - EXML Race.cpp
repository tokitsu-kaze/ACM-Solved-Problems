#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int main()
{
	int T,n,i,d,t,now,pos;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		now=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&d,&t);
			if(d/t>now)
			{
				now=d/t;
				pos=i;
			}
		}
		printf("%d\n",pos);
	}
	return 0;
}
