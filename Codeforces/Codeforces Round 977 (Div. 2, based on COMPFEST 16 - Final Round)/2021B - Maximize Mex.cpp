#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int cnt[MAX];
int main()
{
	int T,n,a,i,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(i=0;i<=2*n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(a<=2*n) cnt[a]++;
		}
		for(i=0;i<=2*n;i++)
		{
			if(!cnt[i])
			{
				printf("%d\n",i);
				break;
			}
			if(cnt[i]>1 && i+x<=2*n)
			{
				cnt[i+x]+=cnt[i]-1;
				cnt[i]=1;
			}
		}
	}
	return 0;
}
