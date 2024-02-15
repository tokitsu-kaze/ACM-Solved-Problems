#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e3+10;
int main()
{
	int n,b,x,i,now,ok;
	ll ans;
	scanf("%d%d",&n,&b);
	ans=0;
	map<int,int> mp;
	mp[0]=1;
	now=0;
	ok=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x<b) now--;
		else if(x>b) now++;
		else ok=1;
		if(ok) ans+=mp[now];
		else mp[now]++;
	}
	printf("%lld\n",ans);
	return 0;
}
