#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
int a[MAX],cnt[MAX];
int main()
{
	int n,l,r,i,j,mod,ans,f,pos;
	scanf("%d%d%d",&n,&l,&r);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if(l<=a[n]) ans=max(0,r-a[n]);
	else ans=r-l+1;
	f=0;
	for(i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) f=1;
	}
	if(f)
	{
		puts("0");
		return 0;
	}
	r=min(r,a[n]);
	if(l>r)
	{
		printf("%d\n",ans);
		return 0;
	}
	for(i=0;i<=a[n];i++) cnt[i]=0;
	for(i=1;i<=n;i++) cnt[a[i]]++;
	pos=n;
	for(mod=r;mod>=l;mod--)
	{
		while(pos>=1&&a[pos]>=mod)
		{
			cnt[a[pos]]--;
			pos--;
		}
		f=1;
		for(i=pos+1;i<=n;i++)
		{
			cnt[a[i]%mod]++;
			if(cnt[a[i]%mod]>1)
			{
				for(j=pos+1;j<=i;j++) cnt[a[j]%mod]--;
				f=0;
				break;
			}
		}
		ans+=f;
		if(f)
		{
			for(j=pos+1;j<=n;j++) cnt[a[j]%mod]--;
		}
	}
	printf("%d\n",ans);
	return 0;
}
