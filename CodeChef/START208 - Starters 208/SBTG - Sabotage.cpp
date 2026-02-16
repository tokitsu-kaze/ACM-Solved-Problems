#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int a[MAX];
int main()
{
	int T,n,x,k,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&x,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		for(i=1;i<=min(n,k);i++) a[i]=0;
		x+=k*100;
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]>x) ans++;
		}
		printf("%d\n",ans+1);
	}
	return 0;
}
