#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int T,x,y,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		tmp=(x+y)/3;
		printf("%d\n",tmp+min(tmp,y));
	}
	return 0;
}
