#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e6+10;
char s[MAX],st[MAX];
int top,ha1[MAX],ha2[MAX];
const int sd1=131;
const int sd2=233;
const int p1=1e9+9;
const int p2=998244353;
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	scanf("%s",s+1);
	ans=0;
	top=0;
	map<pair<int,int>,int> mp;
	mp[{0,0}]=1;
	ha1[0]=ha2[0]=0;
	for(i=1;i<=n;i++)
	{
		if(top && st[top]==s[i]) top--;
		else
		{
			st[++top]=s[i];
			ha1[top]=(1LL*ha1[top-1]*sd1+s[i])%p1;
			ha2[top]=(1LL*ha2[top-1]*sd2+s[i])%p2;
		}
		ans+=mp[{ha1[top],ha2[top]}];
		mp[{ha1[top],ha2[top]}]++;
	}
	printf("%lld\n",ans);
	return 0;
}
