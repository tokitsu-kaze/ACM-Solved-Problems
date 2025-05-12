#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int sum[MAX];
int main()
{
	int T,n,m,i,fz,fm,g,tar,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		sum[0]=0;
		for(i=1;i<=n;i++) sum[i]=sum[i-1]+s[i]-'0';
		fz=sum[n];
		fm=n;
		g=__gcd(fz,fm);
		fz/=g;
		fm/=g;
		if(m%fm)
		{
			puts("-1");
			continue;
		}
		tar=fz*(m/fm);
		assert(tar<=sum[n]);
		ok=0;
		for(i=m;i<=n;i++)
		{
			if(sum[i]-sum[i-m]==tar)
			{
				puts("1");
				printf("%d %d\n",i-m+1,i);
				ok=1;
				break;
			}
		}
		if(ok) continue;
		for(i=n-m+1;i<=n;i++)
		{
			if(sum[i]-sum[i-(n-m)]==sum[n]-tar)
			{
				puts("2");
				printf("%d %d\n",1,i-(n-m));
				printf("%d %d\n",i+1,n);
				ok=1;
				break;
			}
		}
		if(!ok) puts("-1");
	}
	return 0;
}

