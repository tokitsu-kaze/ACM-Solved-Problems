#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int a[MAX];
int main()
{
	int t,n,i,ok;
	ll now;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ok=1;
		sort(a+1,a+1+n);
		if(a[1]!=1) ok=0;
		now=1;
		for(i=2;i<=n;i++)
		{
			if(a[i]>now)
			{
				ok=0;
				break;
			}
			now+=a[i];
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
