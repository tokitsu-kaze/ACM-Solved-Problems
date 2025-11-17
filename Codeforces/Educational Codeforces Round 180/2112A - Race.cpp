#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,a,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&x,&y);
		if(x>y) swap(x,y);
		if(a<x || a>y) puts("YES");
		else puts("NO");
	}
	return 0;
}
