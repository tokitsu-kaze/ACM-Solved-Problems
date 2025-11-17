#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T;
	ll n,ans;
	vector<ll> tmp;
	tmp.push_back(2050);
	while(tmp.back()<1e18) tmp.push_back(tmp.back()*10);
	reverse(tmp.begin(),tmp.end());
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		ans=0;
		for(auto &it:tmp)
		{
			ans+=n/it;
			n%=it;
		}
		if(n!=0) ans=-1;
		printf("%lld\n",ans);
	}
	return 0;
}
