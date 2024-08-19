#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int flag[MAX];
int main()
{
	int t,n,i,x,ok;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<=n+1;i++) flag[i]=0;
		ok=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(i!=1)
			{
				if(flag[x-1]||flag[x+1]) flag[x]=1;
				else ok=0;
			}
			else flag[x]=1;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
