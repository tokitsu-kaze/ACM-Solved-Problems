#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,ra,rb,ok,f;
	ll mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ok=1;
		mx=0;
		for(i=1;i<=n;i++)
		{
			if((a[i]&1)!=(a[1]&1)) ok=0;
			if(a[i]&1) mx=max(mx,1LL*a[i]);
		}
		if(ok)
		{
			puts("0");
			continue;
		}
		sort(a+1,a+1+n);
		ra=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]%2==0)
			{
				if(a[i]>mx)
				{
					ra++;
					mx+=a[i];
				}
				mx+=a[i];
				ra++;
			}
		}
		mx=0;
		rb=0;
		f=0;
		for(i=n;i;i--)
		{
			if((a[i]&1)!=(a[n]&1))
			{
				mx=a[i]+a[n];
				if(a[i]&1)
				{
					rb+=2;
					f=n;
				}
				else
				{
					rb++;
					f=i;
				}
				break;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(f==i) continue;
			if(a[i]%2==0)
			{
				if(a[i]>mx)
				{
					rb++;
					mx+=a[i];
				}
				mx+=a[i];
				rb++;
			}
		}
		printf("%d\n",min(ra,rb));
	}
	return 0;
}
/*
1
4
3 10 50 100
*/
