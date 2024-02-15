#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int t,n,i,ok;
	ll s,now;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
		}
		s/=n;
		now=0;
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(a[i]>=s) now+=a[i]-s;
			else
			{
				if(a[i]+now<s) ok=0;
				now-=s-a[i];
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
