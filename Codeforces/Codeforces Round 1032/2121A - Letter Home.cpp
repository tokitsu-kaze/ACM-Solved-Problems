#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,i,s,a[105],l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&s);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		if(s<a[1])
		{
			printf("%d\n",a[n]-s);
			continue;
		}
		if(s>a[n])
		{
			printf("%d\n",s-a[1]);
			continue;
		}
		l=s-a[1];
		r=a[n]-s;
		if(l<r) printf("%d\n",l*2+r);
		else printf("%d\n",l+r*2);
	}
	return 0;
}
