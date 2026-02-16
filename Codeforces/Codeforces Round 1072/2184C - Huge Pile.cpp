#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int main()
{
	int T,n,k,i,l,r,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(n==k)
		{
			puts("0");
			continue;
		}
		if(k>n)
		{
			puts("-1");
			continue;
		}
		l=r=n;
		ans=-1;
		for(i=0;i<=30;i++)
		{
			l/=2;
			r=(r+1)/2;
			if(l<=k && k<=r)
			{
				ans=i+1;
				break;
			}
		}
		printf("%d\n",ans);
		
	}
	return 0;
}
