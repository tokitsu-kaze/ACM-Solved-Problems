#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=50000+10;
const int mod=998244353;
int main()
{
	int n,now,d,a,i;
	scanf("%d%d",&n,&now);
	while(n--)
	{
		scanf("%d%d",&d,&a);
		if(d==1)
		{
			if(now>=1600&&now<=2799) now+=a;
		}
		else
		{
			if(now>=1200&&now<=2399) now+=a;
		}
	}
	printf("%d\n",now);
	return 0;
}
