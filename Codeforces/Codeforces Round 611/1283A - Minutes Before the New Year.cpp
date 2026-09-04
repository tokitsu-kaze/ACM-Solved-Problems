#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,h,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&h,&m);
		printf("%d\n",1440-h*60-m);
	}
	return 0;
}
