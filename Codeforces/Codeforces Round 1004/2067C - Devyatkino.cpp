#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=1000+10;
int main()
{
	int T,ans,now,i;
	ll n,x;
	vector<ll> tmp;
	tmp.push_back(9);
	for(i=1;i<10;i++) tmp.push_back(tmp.back()*10L+9);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		ans=INF;
		for(auto &it:tmp)
		{
			now=0;
			x=n;
			while(1)
			{
				string s=to_string(x);
				if(s.find('7')!=string::npos)
				{
					ans=min(ans,now);
					break;
				}
				x+=it;
				now++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
