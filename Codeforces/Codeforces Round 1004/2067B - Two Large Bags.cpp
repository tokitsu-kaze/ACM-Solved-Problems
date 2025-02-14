#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=1000+10;
int cnt[MAX];
int main()
{
	int T,n,i,x,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		for(i=1;i<n;i++)
		{
			if(cnt[i]>2)
			{
				cnt[i+1]+=cnt[i]-2;
				cnt[i]=2;
			}
		}
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(cnt[i]&1) ok=0;
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
