#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
int st[MAX],top;
int main()
{
	int q,op,x,i;
	top=0;
	for(i=0;i<100;i++) st[top++]=0;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			st[top++]=x;
		}
		else
		{
			printf("%d\n",st[top-1]);
			top--;
		}
	}
	return 0;
}
