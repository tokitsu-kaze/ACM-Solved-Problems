#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int q,op,x,i;
	scanf("%d",&q);
	vector<ll> v;
	v.push_back(0);
	i=0;
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			v.push_back(v.back()+x);
		}
		else if(op==2) i++;
		else
		{
			scanf("%d",&x);
			printf("%lld\n",v[i+x-1]-v[i]);
		}
	}
	return 0;
}
