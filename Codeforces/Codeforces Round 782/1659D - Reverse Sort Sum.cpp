#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int sum[MAX],a[MAX],res[MAX];
int main()
{
	int T,n,i,now;
	ll tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		tot=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			tot+=a[i];
			sum[i]=0;
		}
		tot/=n;
		now=0;
		for(i=n;i;i--)
		{
			now+=sum[i];
			a[i]-=now;
			if(a[i]==i) res[i]=1;
			else res[i]=0;
			sum[i-tot]--;
			sum[i-1]++;
			tot-=res[i];
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}
/*
0 1 1 0 0 0 1
0 1 1 0 0 0 1
0 1 1 0 0 0 1
0 0 1 1 0 0 1
0 0 0 1 1 0 1
0 0 0 0 1 1 1
0 0 0 0 1 1 1

0 3 4 2 2 1 1
0 3 4 2 1 0 1
0 3 4 1 0 0 1
0 3 3 0 0 0 1
0 2 1 0 0 0 1
0 1 1 0 0 0 1
*/
