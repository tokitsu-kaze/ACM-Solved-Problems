#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int a[MAX];
ll sum[MAX],l[42],r[42];
int main()
{
	int T,n,c,q,i;
	ll k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&c,&q);
		scanf("%s",s+1);
		sum[0]=n;
		for(i=1;i<=c;i++)
		{
			scanf("%lld%lld",&l[i],&r[i]);
			sum[i]=sum[i-1]+(r[i]-l[i]+1);
		}
		while(q--)
		{
			scanf("%lld",&k);
			for(i=c;i;i--)
			{
				if(k>sum[i-1])
				{
					k-=sum[i-1];
					k=l[i]+k-1;
				}
			}
			printf("%c\n",s[k]);
		}
	}
	return 0;
}
