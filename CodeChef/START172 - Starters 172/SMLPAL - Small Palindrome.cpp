#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,x,y,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		for(i=0;i<x/2;i++) printf("1");
		for(i=0;i<y;i++) printf("2");
		for(i=0;i<x/2;i++) printf("1");
		puts("");
	}
	return 0;
}
