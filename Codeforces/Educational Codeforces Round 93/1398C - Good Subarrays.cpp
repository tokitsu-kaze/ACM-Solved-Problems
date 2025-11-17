#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX];
int main()
{
	int T,n,i,sum;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		map<int,int> mp;
		sum=0;
		mp[sum]++;
		ans=0;
		for(i=1;i<=n;i++)
		{
			sum+=s[i]-'0';
			ans+=mp[sum-i];
			mp[sum-i]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

