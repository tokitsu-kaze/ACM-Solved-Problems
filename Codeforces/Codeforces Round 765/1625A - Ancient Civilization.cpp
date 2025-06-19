#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,k,i,s,cnt,a[105],ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for(s=0;s<k;s++)
		{
			cnt=0;
			for(i=1;i<=n;i++) cnt+=((a[i]>>s)&1);
			if(cnt*2>=n) ans|=(1<<s);
		}
		printf("%d\n",ans);
	}
	return 0;
}
