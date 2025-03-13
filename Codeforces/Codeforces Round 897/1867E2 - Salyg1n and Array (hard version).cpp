#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int ask(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
int main()
{
	int T,n,k,i,ans,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(n%k==0)
		{
			ans=0;
			for(i=1;i<=n;i+=k) ans^=ask(i);
			printf("! %d\n",ans);
			fflush(stdout);
			continue;
		}
		ans=0;
		for(i=1;i<=(n/k-1)*k;i+=k) ans^=ask(i);
		tmp=n%k;
		for(i=n-k+1;i>=(n/k-1)*k+1;i-=tmp/2) ans^=ask(i);
		printf("! %d\n",ans);
		fflush(stdout);
	}
	return 0;
}
