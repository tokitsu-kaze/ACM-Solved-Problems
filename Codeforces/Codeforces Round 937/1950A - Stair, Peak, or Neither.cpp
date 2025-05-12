#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,a,b,c;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a<b && b<c) puts("STAIR");
		else if(a<b && b>c) puts("PEAK");
		else puts("NONE");
	}
	return 0;
}
