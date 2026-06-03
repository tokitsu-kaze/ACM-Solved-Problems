#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int n,m,cnt;
	scanf("%d%d",&n,&m);
	cnt=0;
	while(m)
	{
		m=n%m;
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
