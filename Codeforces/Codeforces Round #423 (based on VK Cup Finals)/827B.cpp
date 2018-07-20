#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e6;
int main()
{
	int n,k,ans,now,i;
	while(~scanf("%d%d",&n,&k))
	{
		ans=(n-1)/k*2;
		if((n-1)%k==1) ans++;
		else if((n-1)%k>=2) ans+=2;
		printf("%d\n",ans);
		n--;
		for(i=2;i<=1+k&&n;i++)
		{
			n--;
			now=i;
			printf("1 %d\n",i);
		}
		while(n)
		{
			now++;
			for(i=now;i<=now+k-1&&n;now++)
			{
				n--;
				printf("%d %d\n",now-k,now);
			}
		}
	}
	return 0;
}