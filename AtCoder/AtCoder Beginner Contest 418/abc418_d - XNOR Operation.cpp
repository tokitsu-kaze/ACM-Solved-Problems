#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int n,i,j,cnt0,mp[2];
	ll ans;
	scanf("%d",&n);
	scanf("%s",s+1);
	ans=0;
	memset(mp,0,sizeof mp);
	mp[0]=1;
	cnt0=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='0') cnt0++;
		ans+=mp[cnt0%2];
		mp[cnt0%2]++;
	}
	/*
	for(i=1;i<=n;i++)
	{
		cnt0=0;
		for(j=i;j<=n;j++)
		{
			if(s[j]=='0') cnt0++;
			if(cnt0%2==0)
			{
				// cnt0>=2, cnt0%2==0
				ans++;
			}
		}
	}
	*/
	printf("%lld\n",ans);
	return 0;
}
