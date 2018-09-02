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
const int MAX=1000000+10;
const ll mod=1e6;
int prime[MAX];
int ans[1111],c;
void work(int b)
{
	if(b)
	{
		work(b/2);
		ans[c++]=b%2;
	}
}
int main()
{
	int n,i,j,t;
	mem(prime,0);
	prime[0]=prime[1]=1;
	t=sqrt(MAX);
	for(i=2;i<t;i++)
	{
		if(!prime[i])
		{
			for(j=i+i;j<MAX;j+=i)
			{
				prime[j]=1;
			}
		}
	}
	while(~scanf("%d",&n))
	{
		mem(ans,0);
		if(!prime[n])
		{
			c=0;
			work(n);
			for(i=0;i<c;i++)
			{
				printf("%d",ans[i]);
			}
			puts("");
		}
		else puts("So Sad~");
	}
	return 0;
}