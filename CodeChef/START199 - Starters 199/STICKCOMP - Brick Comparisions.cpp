#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=400+10;
int main()
{
	int T,n,i,a[105],p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		p=1;
		for(i=2;i<=n;i++)
		{
			if(a[i]>a[p]) p=i;
		}
		printf("%d\n",p);
	}
	return 0;
}
