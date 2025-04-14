#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int a[MAX],b[MAX],cnt[MAX],tmp[MAX],n;
const int LIMT=1e9;
int ck(int k)
{
	int i;
	for(i=1;i<=n;i++) tmp[b[i]]=cnt[b[i]];
	for(i=1;i<=n;i++)
	{
		tmp[a[i]%k]--;
		if(tmp[a[i]%k]<0) return 0;
	}
	return 1;
}
int main()
{
	int T,i,ok,ans;
	ll sa,sb;
	memset(cnt,0,sizeof cnt);
	memset(tmp,0,sizeof tmp);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sa=sb=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sa+=a[i];
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			sb+=b[i];
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(a[i]!=b[i]) ok=0;
		}
		if(ok)
		{
			printf("%d\n",LIMT);
			continue;
		}
		
		sa-=sb;
		if(sa<0)
		{
			puts("-1");
			continue;
		}
		
		for(i=1;i<=n;i++) cnt[b[i]]++;
		ans=LIMT+1;
		for(i=1;1LL*i*i<=sa;i++)
		{
			if(sa%i) continue;
			ans=LIMT+1;
			if(ck(i)) ans=i;
			if(sa/i<=LIMT && ck(sa/i)) ans=sa/i;
			if(ans<=LIMT) break;
		}
		if(ans<=LIMT) printf("%d\n",ans);
		else puts("-1");
		for(i=1;i<=n;i++) cnt[b[i]]=tmp[b[i]]=0;
	}
	return 0;
}
