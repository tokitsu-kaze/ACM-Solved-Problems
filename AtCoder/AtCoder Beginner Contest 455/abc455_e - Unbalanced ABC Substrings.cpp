#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int n;
char s[MAX];
ll cal(char x,char y)
{
	int i,now;
	ll ans;
	map<int,int> mp;
	mp[0]=1;
	now=0;
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]==x) now++;
		else if(s[i]==y) now--;
		ans+=mp[now];
		mp[now]++;
	}
	return ans;
}
int main()
{
	int i,cnt[3];
	ll ans;
	scanf("%d",&n);
	scanf("%s",s+1);
	ans=1LL*n*(n+1)/2;
	ans-=cal('A','B');
	ans-=cal('B','C');
	ans-=cal('A','C');
	map<pair<int,int>,int> mp;
	memset(cnt,0,sizeof cnt);
	mp[{0,0}]=1;
	for(i=1;i<=n;i++)
	{
		cnt[s[i]-'A']++;
		ans+=2*mp[{cnt[1]-cnt[0],cnt[2]-cnt[0]}];
		mp[{cnt[1]-cnt[0],cnt[2]-cnt[0]}]++;
	}
	printf("%lld\n",ans);
	return 0;
}

