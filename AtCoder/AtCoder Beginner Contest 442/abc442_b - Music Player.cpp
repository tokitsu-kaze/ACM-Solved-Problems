#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int q,op,now,f;
	scanf("%d",&q);
	now=f=0;
	while(q--)
	{
		scanf("%d",&op);
		if(op==1) now++;
		else if(op==2) now=max(0,now-1);
		else f^=1;
		if(f && now>=3) puts("Yes");
		else puts("No");
	}
	return 0;
}
