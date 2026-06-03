#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int main()
{
	int n,m,k,i,j,ans,a[1010],cnt;
	scanf("%d%d%d",&m,&n,&k);
	ans=0;
	while(m--)
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
		{
			cnt=0;
			for(j=i;j<=n;j++)
			{
				cnt+=a[j];
				if(cnt==k) ans++;
				if(cnt>k) break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
