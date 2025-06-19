#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int T,n,x,a[12],l,r,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		l=0;
		r=-1;
		for(i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				l=i;
				break;
			}
		}
		for(i=n;i;i--)
		{
			if(a[i]==1)
			{
				r=i;
				break;
			}
		}
		if(r-l+1<=x) puts("YES");
		else puts("NO");
	}
	return 0;
}
