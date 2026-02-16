#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int main()
{
	int T,w,p,k,tmp,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&w,&p,&k);
		tmp=min(w,k);
		ans=tmp*2;
		k-=tmp;
		tmp=min(p,k);
		ans+=tmp;
		printf("%d\n",ans);
	}
	return 0;
}
