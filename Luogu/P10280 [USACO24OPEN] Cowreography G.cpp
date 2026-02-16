#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
char a[MAX],b[MAX];
int main()
{
	int n,k,i,x;
	ll ans;
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
	scanf("%s",b+1);
	ans=0;
	set<pair<int,int>> s[2];
	for(i=1;i<=n;i++)
	{
		if(a[i]==b[i]) continue;
		x=a[i]-'0';
		if(s[!x].size()==0)
		{
			s[x].insert({i%k,i});
			continue;
		}
		auto it=s[!x].lower_bound({i%k,-1});
		if(it==s[!x].end()) it=s[!x].begin();
		ans+=(i-(*it).second+k-1)/k;
		s[!x].erase(it);
	}
	assert(s[0].size()==0 && s[1].size()==0);
	printf("%lld\n",ans);
	return 0;
}

