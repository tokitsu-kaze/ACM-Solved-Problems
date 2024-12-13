#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int T,a,b,i,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		x=a/__gcd(a,b)*b;
		for(i=min(a,b);i<=x;i++)
		{
			if(i%a==i%b)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
