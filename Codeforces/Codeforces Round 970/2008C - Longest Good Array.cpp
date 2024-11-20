#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int t,l,r,i,now;
	vector<int> res;
	now=1;
	for(i=0;i<=1e9;i+=now,now++) res.push_back(i);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		r-=l;
		printf("%d\n",upper_bound(res.begin(),res.end(),r)-res.begin());
	}
	return 0;
}
