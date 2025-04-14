#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n<=4)
		{
			puts("-1");
			continue;
		}
		vector<int> res;
		for(i=1;i<=n;i+=2)
		{
			if(i==5) continue;
			res.push_back(i);
		}
		res.push_back(5);
		res.push_back(4);
		for(i=2;i<=n;i+=2)
		{
			if(i==4) continue;
			res.push_back(i);
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i-1]," \n"[i==n]);
	}
	return 0;
}

