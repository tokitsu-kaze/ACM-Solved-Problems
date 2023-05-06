#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,k,a,b;
	scanf("%d%d",&n,&k);
	unordered_map<int,int> r,c;
	while(k--)
	{
		scanf("%d%d",&a,&b);
		r[a]=1;
		c[b]=1;
	}
	printf("%lld\n",1ll*n*n-1ll*(n-r.size())*(n-c.size()));
	return 0;
}
