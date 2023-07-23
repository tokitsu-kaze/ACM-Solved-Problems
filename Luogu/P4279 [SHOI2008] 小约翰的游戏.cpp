#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t,n,i,x,cnt,sg;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt=sg=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x!=1) cnt++;
			sg^=x;
		}
		if(sg&&cnt) puts("John");
		else if(!sg&&!cnt) puts("John");
		else puts("Brother");
	}
	return 0;
}
