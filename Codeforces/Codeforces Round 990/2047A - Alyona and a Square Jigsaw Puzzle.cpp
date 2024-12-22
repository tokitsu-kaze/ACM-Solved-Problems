#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int T,n,i,j,ans,sum,x,now,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=0;
		ans=0;
		now=1;
		tmp=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			sum+=x;
			while(now<sum)
			{
				tmp+=2;
				now+=tmp*4-4;
			}
			if(sum==now) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
