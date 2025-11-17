#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,m,k,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		ans=0;
		for(i=0;i<=n;i++)
		{
			if(i*m>=k) ans=max(ans,(n-i)*m);
		}
		for(i=0;i<=m;i++)
		{
			if(i*n>=k) ans=max(ans,(m-i)*n);
		}
		printf("%d\n",ans);
	}
	return 0;
}

