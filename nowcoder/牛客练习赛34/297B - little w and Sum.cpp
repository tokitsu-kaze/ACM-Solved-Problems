#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,s,ans,x;
	while(~scanf("%d",&n))
	{
		map<int,int> mp;
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			mp[x]++;
			s+=x;
		}
		if(s%2||mp[s/2]==0) puts("-1");
		else printf("%d\n",mp[s/2]);
	}
	return 0;
}

