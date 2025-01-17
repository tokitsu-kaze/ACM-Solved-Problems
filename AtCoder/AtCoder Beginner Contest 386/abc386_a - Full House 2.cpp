#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int x,i;
	map<int,int> mp;
	for(i=0;i<4;i++)
	{
		scanf("%d",&x);
		mp[x]++;
	}
	if(mp.size()!=2) puts("No");
	else puts("Yes");
	return 0;
}
