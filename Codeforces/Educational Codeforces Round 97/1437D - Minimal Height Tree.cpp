#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,ans,now,nex;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=1;
		now=0;
		nex=1;
		for(i=3;i<=n;i++)
		{
			if(a[i]>a[i-1]) nex++;
			else
			{
				now--;
				if(now<0)
				{
					now=nex-1;
					nex=1;
					ans++;
				}
				else nex++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
8
1 3 4 2 6 5 8 7
*/
