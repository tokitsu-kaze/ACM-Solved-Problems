#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int dp[MAX];
int main()
{
	int T,n,i,ok;
	memset(dp,0,sizeof dp);
	vector<int> res;
	for(i=1;i<=MAX-10;i++)
	{
		string tmp=to_string(i);
		ok=1;
		for(auto &ch:tmp) ok&=(ch=='0'||ch=='1');
		if(ok) dp[i]=1;
		if(dp[i])
		{
			res.push_back(i);
			for(auto &it:res)
			{
				if(1LL*i*it<MAX) dp[i*it]=1;
				else break;
			}
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(dp[n]) puts("YES");
		else puts("NO");
	}
	return 0;
}
