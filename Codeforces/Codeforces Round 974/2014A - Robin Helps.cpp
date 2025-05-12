#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,k,i,x,sum,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		sum=ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x>=k) sum+=x;
			else if(x==0)
			{
				if(sum>0)
				{
					sum--;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
