#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int main()
{
	int T,n,c,i,a[105],sum[2];
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&c);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%s",s+1);
		sum[0]=sum[1]=0;
		for(i=1;i<=n;i++) sum[s[i]-'0']+=a[i];
		if(sum[0]>=c) printf("%d\n",max(sum[0],sum[0]-c+sum[1]));
		else printf("%d\n",sum[0]);
	}
	return 0;
}
