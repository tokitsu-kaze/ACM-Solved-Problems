#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
char s[MAX];
int main()
{
	int n,i,j,k,l,id;
	ll ans,res[4];
	scanf("%d",&n);
	scanf("%s",s+1);
	vector<int> pos[4];
	for(i=1;i<=n;i++)
	{
		if(s[i]=='K') id=0;
		else if(s[i]=='U') id=1;
		else if(s[i]=='P') id=2;
		else if(s[i]=='C') id=3;
		else continue;
		pos[id].push_back(i);
	}
	ans=0;
	while(1)
	{
		if(pos[3].size()==0) break;
		res[3]=pos[3].back();
		pos[3].pop_back();
		for(i=2;~i;i--)
		{
			while(pos[i].size()>0 && pos[i].back()>res[i+1]) pos[i].pop_back();
			if(pos[i].size()==0) goto end;
			res[i]=pos[i].back();
			pos[i].pop_back();
		}
		ans=(ans+1LL*res[0]*res[1]%mod*res[2]%mod*res[3])%mod;
	}
	end:;
	printf("%lld\n",ans);
	return 0;
}
