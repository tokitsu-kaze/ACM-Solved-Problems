#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int MAX=2e5+10;
int main()
{
	int n,m,i,a,b;
	scanf("%d%d",&n,&m);
	map<pair<int,int>,int> mp;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		if(a!=b) mp[{a,b}]=1;
	}
	printf("%d\n",m-mp.size());
	return 0;
}
