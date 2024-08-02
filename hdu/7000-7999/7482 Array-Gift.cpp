#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105],n;
int ck0()
{
	int i,j,ok;
	for(i=1;i<=n;i++)
	{
		ok=1;
		for(j=1;j<=n;j++) ok&=(a[j]%a[i]==0);
		if(ok) return 1;
	}
	return 0;
}
int ck1()
{
	int i,j,k,p,ok,cnt;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j) continue;
			p=a[i]%a[j];
			if(!p) continue;
			ok=1;
			for(k=1;k<=n;k++)
			{
				if(k==i) continue;
				ok&=(a[k]%p==0);
			}
			if(ok) return 1;
		}
	}
	for(i=1;i*i<=a[2];i++)
	{
		if(a[2]%i) continue;
		ok=1;
		p=i;
		for(j=2;j<=n;j++) ok&=(a[j]%p==0);
		if(ok&&p>a[1]) return 1;
		ok=1;
		p=a[2]/i;
		for(j=2;j<=n;j++) ok&=(a[j]%p==0);
		if(ok&&p>a[1]) return 1;
	}
	ok=1;
	for(i=3;i<=n;i++) ok&=(a[i]%a[2]==0);
	if(ok) return 1;
	cnt=0;
	for(i=2;i<=n;i++) cnt+=(a[i]%a[1]!=0);
	if(cnt==1) return 1;
	return 0;
}
int main()
{
	int t,i,ans,ok;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=n;
		sort(a+1,a+1+n);
		vector<int> res;
		for(i=1;i<=n;i++)
		{
			ok=0;
			for(auto &it:res)
			{
				if(a[i]%it==0) ok=1;
			}
			if(!ok) res.push_back(a[i]);
		}
		for(i=1;i<=res.size();i++) a[i]=res[i-1];
		n=res.size();
		if(ck0()) printf("%d\n",ans-1);
		else if(ck1()) printf("%d\n",ans);
		else printf("%d\n",ans+1);
	}
	return 0;
}

