#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int a[MAX];
int main()
{
	int T,i,j,k,x,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&k);
		for(i=1;i<=k;i++)
		{
			scanf("%d",&a[i]);
			for(j=1;j<a[i];j++) scanf("%d",&x);
		}
		sort(a+1,a+1+k);
		reverse(a+1,a+1+k);
		ans=0;
		for(i=1;i<=k;i++)
		{
			for(j=21;~j;j--)
			{
				if((a[i]>>j)&1)
				{
					if((ans>>j)&1)
					{
						ans|=(1<<j)-1;
						break;
					}
					else
					{
						ans|=(1<<j);
						a[i]-=(1<<j);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
k=1，选n最优；多个n时，由于能删叶子，所以1-n都能取到。
问题转化成，每个数可以选0-ai，问or最大。
*/
