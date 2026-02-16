#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int st[MAX],top;
int main()
{
	int n,i,x;
	scanf("%d",&n);
	top=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		st[top++]=x;
		if(top>=4)
		{
			if(st[top-1]==st[top-2] &&
			   st[top-1]==st[top-3] &&
			   st[top-1]==st[top-4])
			{
				top-=4;
			}
		}
	}
	printf("%d\n",top);
	return 0;
}
