#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,i,n,sum;
	ll tot,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		tot=0;
		sum=0;
		vector<int> res;
		res.push_back(sum);
		for(i=1;i<=n;i++)
		{
			if(s[i]=='0') sum--;
			else sum++;
			tot+=1LL*i*(n-i+1);
			res.push_back(sum);
		}
		sort(res.begin(),res.end());
		now=0;
		for(auto &it:res)
		{
			now+=1LL*it*(lower_bound(res.begin(),res.end(),it)-res.begin());
			now-=1LL*it*(n-(upper_bound(res.begin(),res.end(),it)-res.begin())+1);
		}
		printf("%lld\n",tot-(tot-now)/2);
	}
	return 0;
}
