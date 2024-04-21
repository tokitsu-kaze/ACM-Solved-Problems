#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int t,m,k,a1,ak,tmp,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&m,&k,&a1,&ak);
		ans=m/k+m%k;
		tmp=min(m/k,ak);
		m-=tmp*k;
		m-=a1;
		if(m<=0)
		{
			puts("0");
			continue;
		}
		ans=min(ans,m/k+m%k);
		m+=min(a1,k-m%k);
		ans=min(ans,m/k+m%k);
		printf("%d\n",ans);
	}
	return 0;
}
