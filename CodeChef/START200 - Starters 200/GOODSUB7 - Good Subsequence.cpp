#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int T,n,i,a[105],sa,sb,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sa=0;
		f=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]%2!=f)
			{
				sa++;
				f^=1;
			}
		}
		sb=0;
		f=1;
		for(i=1;i<=n;i++)
		{
			if(a[i]%2!=f)
			{
				sb++;
				f^=1;
			}
		}
		printf("%d\n",max(sa,sb));
	}
	return 0;
}

