#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=998244353;
int main()
{
	int t,n,i,x,cnt[2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt[0]=cnt[1]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x&1]+=x;
		}
		if(cnt[0]>cnt[1]) puts("YES");
		else puts("NO");
	}
	return 0;
}
