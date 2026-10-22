#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=9e6+10;
const int mod=998244353;
struct Manacher
{
	int p[MAX<<1];
	char s[MAX<<1];
	ll work(int n,char *a) // a[1..n]
	{
		int i,mid,r,mx;
		ll cnt;
		for(i=1;i<=n;i++)
		{
			p[i]=0;
			s[2*i-1]='%';
			s[2*i]=a[i];
		}
		s[n=n*2+1]='%';
		mid=r=mx=cnt=0;
		for(i=1;i<=n;i++)
		{
			if(i<r) p[i]=min(p[2*mid-i],r-i);
			else p[i]=1;
			while(i-p[i]>=1&&i+p[i]<=n&&s[i-p[i]]==s[i+p[i]]) p[i]++;
			if(i+p[i]>r)
			{
				r=i+p[i];
				mid=i;
			}
			mx=max(mx,p[i]);
			cnt+=p[i]/2;
		}
		return cnt;
	}
}la;
char s[MAX];
int main()
{
	int T,n,k,i;
	ll ans,s1,s2,s3;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		s1=la.work(n,s)%mod;
		for(i=n+1;i<=2*n;i++) s[i]=s[i-n];
		s2=la.work(2*n,s)%mod;
		for(i=2*n+1;i<=3*n;i++) s[i]=s[i-n];
		s3=la.work(3*n,s)%mod;
		ans=s1;
		ans+=(s2-s1)*(k-1);
		ans+=(1LL*(k-1)*(k-2)/2)%mod*(s3-2*s2+s1);
		ans=(ans%mod+mod)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}

