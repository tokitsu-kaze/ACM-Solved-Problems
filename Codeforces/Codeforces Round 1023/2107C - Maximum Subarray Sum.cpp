#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
ll a[MAX];
int main()
{
	int T,n,i,cnt,pos,ok;
	ll k,sum,mx,premx,sufmx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&k);
		scanf("%s",s+1);
		cnt=0;
		pos=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(s[i]=='0')
			{
				a[i]=-1e18;
				cnt++;
				pos=i;
			}
		}
		sum=0;
		mx=-2e18;
		for(i=1;i<=n;i++)
		{
			sum+=a[i];
			mx=max(mx,sum);
			sum=max(sum,0LL);
		}
		if(mx>k)
		{
			puts("No");
			continue;
		}
		if(mx==k)
		{
			puts("Yes");
			for(i=1;i<=n;i++) printf("%lld%c",a[i]," \n"[i==n]);
			continue;
		}
		if(cnt==0)
		{
			puts("No");
			continue;
		}
		ok=0;
		for(i=2;i<=n-1;i++)
		{
			if(s[i-1]=='0' && s[i]=='0' && s[i+1]=='0')
			{
				ok=1;
				a[i]=k;
				break;
			}
		}
		if(ok)
		{
			puts("Yes");
			for(i=1;i<=n;i++) printf("%lld%c",a[i]," \n"[i==n]);
			continue;
		}
		premx=0;
		sum=0;
		for(i=pos+1;i<=n;i++)
		{
			sum+=a[i];
			premx=max(premx,sum);
		}
		sufmx=0;
		sum=0;
		for(i=pos-1;i;i--)
		{
			if(s[i]=='0') break;
			sum+=a[i];
			sufmx=max(sufmx,sum);
		}
		a[pos]=k-premx-sufmx;
		puts("Yes");
		for(i=1;i<=n;i++) printf("%lld%c",a[i]," \n"[i==n]);
	}
	return 0;
}
